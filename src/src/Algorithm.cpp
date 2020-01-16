#include "Algorithm.h"

Algorithm::Algorithm(Problem& pbm, SetUpParams& setup) :
                    _population{setup.population_size()},
                    _fitness_values_of_current_population{},
                    _sol{NULL},
                    _pbm{pbm},
                    _setup{setup},
                    _global_best_solution{NULL}
                    //,_upper_cost{}, _lower_cost{}
{
    _population.resize(_setup.population_size());
	for (unsigned int i = 0; i < _setup.population_size(); ++i) {
		_population[i] = new Solution(pbm);
	}
	//evaluate();
}

Algorithm::~Algorithm(){
    for(unsigned int i = 0; i < _setup.population_size(); i++)
        delete _population[i];
}

const SetUpParams& Algorithm::setup() const{
    return _setup;
}

void Algorithm::initialize(){
    for(unsigned int i = 0; i < _setup.population_size(); i++){
        _population[i]->initialize();
        //_upper_cost = 29;
        //_lower_cost = 0;
    }
}

void Algorithm::evaluate(){
    for(unsigned int i = 0; i < _setup.population_size(); i++)
         _population[i]->fitness();
}

const vector<Solution*>& Algorithm::current_solutions() const{
    return _population;
}
//double Algorithm::global_best_cost() const{} // pas encore defini

Solution& Algorithm::solution(const unsigned int index) const{
    return *_population[index];
}

Solution& Algorithm::global_best_solution() const{
    return *_global_best_solution;
}

void Algorithm::UpdateBestSolution(Solution *NewSolution){
    if (!NewSolution)
        NewSolution = new Solution(*_global_best_solution);
    else if ((NewSolution->get_fitness()) > (_global_best_solution->get_fitness()))
        *NewSolution = *_global_best_solution;
}

double Algorithm::bestFitness() const{
	return _population[_lower_cost]->get_fitness();
}

double Algorithm::worstFitness() const{
	return _population[_upper_cost]->get_fitness();
}

void Algorithm::FindBestSolution()
{
    if (_population.size())
    {
        int k = rand() % _setup.population_size();
        double minimum = _population[k]->get_fitness();
        _global_best_solution = _population[k];

        for (unsigned i = 0; i < _population.size(); ++i)
        {
            if ((_population[i]->get_fitness()) < (minimum))
            {
                minimum = _population[i]->get_fitness();
                _global_best_solution = _population[i];
            }
        }
    }
}

void Algorithm::evolution(int iteration)
{
    //double moy_best_fit = 0.0;
    //double moy_worst_fit = 0.0;
    int i = 0;
    cout << o_global_best_solution->get_fitness() << " ok";
    while (i < iteration && _global_best_solution->get_fitness() != 0)
    {
        //Generation();
        //Selection();

        //FindBestSolution();

        double moy_best_fit = 0.0;
	double moy_worst_fit = 0.0;
	std::cout << "\t\t\t Best fitness           Worst fitness" << std::endl;
	for (unsigned int r = 0; r < _setup.independent_runs(); r++)
	{
		initialize();
		double bestFit = bestFitness();
		double worstFit = worstFitness();
		for (unsigned int iter = 0; iter < _setup.nb_evolution_steps(); iter++)
		{
		    //Mutation and crossover
			vector<Solution*> mutants;
			for (unsigned int i = 0; i < _population.size(); i++)
			{
				default_random_engine g;
				normal_distribution<double> distribution(0.0, 1.0);
				int random = distribution(g);
				if (_setup.getCR() < random)
				{
					Solution s = Solution(*_sol);
					s.set_solution(_sol->mutation(i, _population, _setup));
					mutants.push_back(&s);
				}
				else
				{
					mutants.push_back(_population[i]);
				}
			}
			// selection
			double score_init = 0.0;
			double score_trail = 0.0;
			for (unsigned int i = 0; i < mutants.size(); i++)
			{
				mutants[i]->fitness();
				_population[i]->fitness();
				score_trail += mutants[i]->get_fitness();
				score_init += _population[i]->get_fitness();
			}

			if (score_trail < score_init)
			{
				_population = mutants;
			}
		}
			evaluate();
			if (bestFitness() < bestFit)
			{
				bestFit = bestFitness();
				worstFit = worstFitness();
			}
			std::cout << "\tExecution " << r + 1 << " : \t" << bestFit << "\t\t" << worstFit << std::endl;
			moy_best_fit += bestFit;
			moy_worst_fit += worstFit;
		}
		double somme = 0.0;
		vector <double> temp;
		temp.resize(_setup.independent_runs());
		for (unsigned int i = 0; i < _setup.independent_runs(); i++)
		{
			somme += temp[i];
		}
		moy_best_fit /= _setup.independent_runs();
		moy_worst_fit /= _setup.independent_runs();

		std::cout << "\nMoyenne meilleures fitness : " << moy_best_fit << std::endl;
		std::cout << "Moyenne pires fitness : " << moy_worst_fit << std::endl;
	}
    }


void Algorithm::run()
{
    Solution* BestSolution = NULL;
    for (unsigned i = 0; i < _setup.independent_runs(); i++)
    {
        initialize();
        evaluate();
        global_best_solution();
        evolution(_setup.nb_evolution_steps());
        _fitness_values_of_current_population.push_back(_global_best_solution->get_fitness());
        //update best solution
        UpdateBestSolution(BestSolution);
    }
    _global_best_solution = BestSolution;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Function benchmark : " << _pbm.name() << endl;
    cout << "Best Fitness : " << _global_best_solution->get_fitness() << endl;
    cout << "There have been " << _pbm.calls() << " iterations.\n";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}










