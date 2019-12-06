#include "Solution.h"

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

vector<double>& Solution::get_solution() const
{
    return (std::vector<double>&) _solution;
}

double& Solution::get_position_in_solution(const int index)
{
    return _solution[index];
}

void Solution::set_position_in_solution(const int index, const double value)
{
    _solution[index] = value;
}
