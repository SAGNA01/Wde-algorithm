#include "Algorithm.h"


Algorithm::Algorithm(const Problem& pbm, const SetUpParams& setup) : _setup{setup}
{
    _population.resize(_setup.population_size());
//    for(unsigned int i = 0; i < _setup.population_size(); i++){
//        Solution* s = new Solution(pbm);
//        _population.push_back(s);
//    }
    initialize();
}

Algorithm::~Algorithm(){
    for(unsigned int i = 0; i < _setup.population_size(); i++){
        delete _population[i];
    }
}

const SetUpParams& Algorithm::setup() const{
    return _setup;
}

void Algorithm::initialize(){
    for(unsigned int i = 0; i < _setup.population_size(); i++){
        _population[i]->initialize();
    }
}

double Algorithm::evaluate(){
    double fit;
    for(unsigned int i = 0; i < _setup.population_size(); i++){
        fit =  _population[i]->fitness();
    }
    return fit;
}
void Algorithm::main(){
    initialize();
    vector<Solution*> popu;
    for(unsigned int i = 0; i < _population.size(); i++){

        default_random_engine g;
		normal_distribution<double> distribution(0.0, 1.0);
        int random = distribution(g);

        Solution* s;
        if(_setup.getCR() < random){
//           _population[i] =  s->mutation(i,_population,_setup);
        }else{
        _population[i] = popu[i];
        }
  }
}

Solution Algorithm::global_best_solution() const{
    return _global_best_solution;
}






