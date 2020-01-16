#include "Algorithm.h"

Algorithm::Algorithm(Problem& pbm, SetUpParams& setup) :
                    _population{setup.population_size()},
                    _fitness_values_of_current_population{},
                    _sol{NULL},
                    _pbm{pbm},
                    _setup{setup},
                    _global_best_solution{NULL}
                    ,_upper_cost{},
                    _lower_cost{}
{
    _population.resize(_setup.population_size());
	for (unsigned int i = 0; i < _setup.population_size(); ++i) {
		_population[i] = new Solution(pbm);
	}
	evaluate();
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
    double moy_best_fit = 0.0;
    double moy_worst_fit = 0.0;
    int i = 0;
    cout << _global_best_solution->get_fitness() << " ok";
    while (i < iteration && _global_best_solution->get_fitness() != 0)
    {
        //Generation();
        //Selection();

        //FindBestSolution();

        double bestFit = bestFitness();
        double worstFit = worstFitness();
        for( unsigned int iter = 0 ; iter < _setup.nb_evolution_steps(); iter++)
        {
            evaluate();
            vector<Solution*> mutants;
            _population.resize(_setup.population_size());
            for(unsigned int i = 0; i < _population.size(); i++)
            {
                default_random_engine g;
                normal_distribution<double> distribution(0.0, 1.0);
                int random = distribution(g);

                //Generation of a trial population
                if(_setup.getCR() < random)
                {
//                    mutants.push_back(_sol.mutation(i,_population,_setup()));
                }
                else
                {
                    mutants.push_back( _population[i]);
                }
            }
            // selection
            for(unsigned int i = 0; i < mutants.size(); i++)
            {
                for(unsigned int j = 0; j < _setup.population_size(); j++)
                {
                     mutants[i]->fitness();
                    _population[j]->fitness();
                    if(mutants[i]->get_fitness() < _population[j]->get_fitness())
                    {
                        _population[j] = mutants[i];
                    }
                }
            }
            if(bestFitness() < bestFit)
            {
                bestFit = bestFitness();
                worstFit = worstFitness();
            }
        }
        evaluate();
        if(bestFitness() < bestFit)
        {
            bestFit = bestFitness();
            worstFit = worstFitness();
        }
        std::cout<<"\tExecution "<<iteration+1<<" :   \t"<<bestFit<<"\t\t"<<worstFit<<std::endl;
        moy_best_fit += bestFit;
	    moy_worst_fit += worstFit;
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











