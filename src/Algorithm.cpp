#include "Algorithm.h"

Algorithm::Algorithm(const Problem& pbm, const SetUpParams& setup) : _setup{setup}
{
    _population.resize(_setup.population_size());
    for(unsigned int i = 0; i < _setup.population_size(); i++){
        Solution* s = new Solution(pbm);
        _population.push_back(s);
    }
}

Algorithm::~Algorithm(){
    for(int i = 0; i < _setup.population_size(); i++){
        //delete _population;
    }
}

const SetUpParams& Algorithm::setup() const{
    return _setup;
}

void Algorithm::initialize(){
    for(int i = 0; i < _setup.population_size(); i++){
        _population[i]->initialize();
    }
}

void Algorithm::evaluate(){
    for(unsigned int i = 0; i < _setup.population_size(); i++)
        _population[i]->fitness();
}

Solution& Algorithm::global_best_solution() const{
    return _global_best_solution;
}

vector<Solution*> Algorithm::mutation(){
    vector<Solution*> mutee;
    mutee.resize(_setup.population_size());
    for (unsigned int i = 0 ; i <_setup.population_size();i++){
    int a;
    int b;
    int c;

    do{
        a = (int)rand() %_setup.population_size();
    } while (a == i);

    do{
        b = (int)rand() %_setup.population_size();
    } while (b == i || b == a);

    do{
        c = (int)rand() %_setup.population_size();
    } while (c == i || c == a || c == b);

    for (unsigned int j = 0; j<_setup.population_size(); j++)
    {
//         Solution* s = new Solution();
//         vector<double> temp =  s.get_solution();
  //       temp[j]= _population[a].get_solution()[j]+(_setup.weigth() *_population[b].get_solution()[j]-_population[c].get_solution()[j]);
//         mutee.push_back(temp);
    }
}
    return mutee ;
}

