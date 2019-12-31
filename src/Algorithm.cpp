#include "Algorithm.h"


Algorithm::Algorithm(const Problem& pbm, const SetUpParams& setup) : _setup{setup}
{
    //_population.resize(_setup.population_size());
    //initialize();
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
    }
}

void Algorithm::evaluate(){
    for(unsigned int i = 0; i < _setup.population_size(); i++)
         _population[i]->fitness();
}

const vector<Solution*>& Algorithm::current_solutions() const{
    return _population;
}

double Algorithm::global_best_cost() const{} // pas encore defini

Solution& Algorithm::solution(const unsigned int index) const{
    return *_population[index];
}

Solution Algorithm::global_best_solution() const{ // pas encore defini
    return _population[];
}

void Algorithm::main(){
    initialize();
    vector<Solution*> mutants;
    Solution _sol;
    for(unsigned int i = 0; i < _population.size(); i++){

        default_random_engine g;
		normal_distribution<double> distribution(0.0, 1.0);
        int random = distribution(g);

        // Generation of a trial population
        if(_setup.getCR() < random){
        _sol.mutation(i,_population,_setup);
        }else{
        mutants[i] = _population[i];
        }
     }

     for(unsigned int i = 0; i < _setup.population_size(); i++){
            _sol.clear_solution();
        for(unsigned int j = 0; j < _setup.solution_size(); j++){

        }
     }

// Selection
     for(unsigned int i = 0; i < mutants.size(); i++){
        for(unsigned int j = 0; j < _setup.solution_size(); j++){
              mutants[i]->fitness();
             _population[j]->fitness();
             if(mutants[i]->get_fitness() < _population[j]->get_fitness()){
                    _population[j] = mutants[i];
            }
        }
     }
}

Solution Algorithm::global_best_solution() const{
    return _global_best_solution;
}






