#include "Algorithm.h"

Algorithm::Algorithm(const Problem& pbm, const SetUpParams& setup) : _pbm{pbm}, _setup{setup}
{}

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

Solution Algorithm::global_best_solution() const{
    return _global_best_solution;                               // A RREVOIR
}

double Algorithm::bestFitness() const{
	return _population[_lower_cost]->get_fitness();
}

double Algorithm::worstFitness() const{
	return _population[_upper_cost]->get_fitness();
}

void Algorithm::main()
{

    //double moy_best_fit = 0.0;
    //double moy_worst_fit = 0.0;
    std::cout << "\t\t\ Mielleur fitness\t\tPire fitness" << std::endl;

    for(unsigned int r = 0; r < _setup.independent_runs(); r++)
    {
        initialize();
        double bestFit = bestFitness();
        double worstFit = worstFitness();
        for( unsigned int iter = 0 ; iter < _setup.nb_evolution_steps(); iter++)
        {
            vector<Solution*> mutants;
            Solution _sol{_pbm};
            for(unsigned int i = 0; i < _population.size(); i++)
            {
                default_random_engine g;
                normal_distribution<double> distribution(0.0, 1.0);
                int random = distribution(g);

                //Generation of a trial population
                if(_setup.getCR() < random)
                {
                    _sol.mutation(i,_population,_setup);
                }
                else
                {
                    mutants[i] = _population[i];
                }
            }
            // selection
            for(unsigned int i = 0; i < mutants.size(); i++)
            {
                for(unsigned int j = 0; j < _setup.solution_size(); j++)
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
        std::cout<<"\t\t\tExecution "<<r+1<<" : "<<bestFit<<"\t\t"<<worstFit<<std::endl;
    }
     std::cout << "\nMoyenne meilleures fitness : " << std::endl;
     std::cout << "Moyenne pires fitness : " << std::endl;
}








