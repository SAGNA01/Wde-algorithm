#include"Solution.h"
#define _USE_MATH_DEFINES
#include<cmath>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include<random>

Solution::Solution() : _pbm{} {}
Solution::Solution(const Problem& pbm) : _pbm{pbm}
{
    initialize();
}

//Solution::Solution(const vector<double>& solution) : _solution{solution}
//{}

Solution::Solution(const Solution& sol) : _pbm{sol._pbm},_fitness_current{sol._fitness_current}
{
    _solution.resize(sol._solution.size());
	_solution = sol._solution;
}

void Solution::initialize(){
    _solution.resize((unsigned long long int) _pbm.dimension());
	 double nbAleatoire, k, _min, _max;
    _min = _pbm.LowerBound();
    _max = _pbm.UpperBound();

    for (unsigned int i = 0; i < _solution.size(); ++i){
        k = (double)rand() / (RAND_MAX+1);
	    nbAleatoire = _min + k * (_max - _min);
	    _solution[i] = (nbAleatoire);
	}

	fitness();
}

const Problem& Solution::pbm() const{
    return _pbm;
}

void Solution::fitness(){
    _fitness_current = (_pbm.fonction())(_solution);
}

double Solution::get_fitness() const{
   return _fitness_current;
}

vector<double>& Solution::get_solution() const{
    _solution;
}

double& Solution::get_position_in_solution(const int index){
    return _solution[index];
}

void Solution::set_position_in_solution(const int index, const double value){
    _solution[index] = value;
}

vector<double> Solution::mutation(int i, vector<Solution*> pop ,SetUpParams setup){
    pop.resize((unsigned long long int) _pbm.dimension());
    int a, b, c;
    do{
        a = (int)rand() %setup.population_size();
    } while (a == i);

    do{
        b = (int)rand() %setup.population_size();
    } while (b == i || b == a);

    do{
        c = (int)rand() %setup.population_size();
    } while (c == i || c == a || c == b);

    double F;
    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 1.0);
    F = 3 * distribution(generator);

    vector<double> mutant;
    for(unsigned int j = 0; j < setup.solution_size(); j++)
    mutant.push_back(pop[i]->get_solution()[j] +
                  (F * pop[b]->get_solution()[j]  -
                   pop[c]->get_solution()[j]));
    return mutant;
}

