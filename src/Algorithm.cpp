#include "Algorithm.h"


const double W = 10.0;
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
        delete _population[i];
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

double Algorithm::evaluate(){
    double fit;
    for(unsigned int i = 0; i < _setup.population_size(); i++){
        fit =  _population[i]->fitness();
    }
    return fit;
}

//Solution Algorithm::global_best_solution() const{
//    return _global_best_solution;
//}


vector<Solution*> Algorithm::mutation(){
    vector<Solution*> mute;
    //double mute** = new double* [_setup._population_size()];
    mute.resize(_setup.population_size());

    // generate the of Trial-Population
    for (unsigned int i = 0 ; i <_setup.population_size();i++){
    int a, b, c;

    do{
        a = (int)rand() %_setup.population_size();
    } while (a == i);

    do{
        b = (int)rand() %_setup.population_size();
    } while (b == i || b == a);

    do{
        c = (int)rand() %_setup.population_size();
    } while (c == i || c == a || c == b);

    for (unsigned int j = 0; j <_setup.solution_size(); j++) // à modifer par solution.size();
    {
         Solution* s = new Solution();
         vector<double> temp =  s->get_solution();
         temp[j] = _population[a]->get_solution()[j] + (W *_population[b]->get_solution()[j] - _population[c]->get_solution()[j]);
         //mute.push_back(temp);
         //mute[j] = temp[i];
    }
}
    return mute ;
}

