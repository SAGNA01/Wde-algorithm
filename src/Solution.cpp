#include"Solution.h"
#define _USE_MATH_DEFINES
#include<cmath>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>


Solution::Solution(const Problem& pbm) : _pbm{pbm}
{}

Solution::Solution(const Solution& sol) : _pbm{sol._pbm}, _fitness_current{sol._fitness_current}
{}

double Solution::get_fitness() const
{
   return _fitness_current;
}

const Problem& Solution::pbm() const
{
    return _pbm;
}
double Solution::fitness()
{
    _fitness_current = (_pbm.fonction())(_solution);
    return _fitness_current;
}
void Solution::initialize()
{
    _solution.resize((unsigned long long int) _pbm.dimension());
	double nbAleatoire, k, Xmin, Xmax;
    Xmin = _pbm.LowerBound();
    Xmax = _pbm.UpperBound();

    for (unsigned int i = 0; i < _solution.size(); ++i)
    {
        k = (double)rand() / (RAND_MAX+1);
	    nbAleatoire = Xmin + k * (Xmax - Xmin);
	    _solution[i]=(nbAleatoire);
	}
   //fitness();
}

vector<double>& Solution::get_solution() const
{
//    return vector<double&> _solution;
}

double& Solution::get_position_in_solution(const int index)
{
    return _solution[index];
}

void Solution::set_position_in_solution(const int index, const double value)
{
    _solution[index] = value;
}
