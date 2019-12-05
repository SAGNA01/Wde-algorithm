#include "SetupParams.h"

SetUpParams::SetUpParams(unsigned int runs, unsigned int steps, unsigned int pop_size, unsigned int sol_size) :
                         _independent_runs{runs}, _nb_evolution_steps{steps},
                         _population_size{pop_size}, _solution_size{sol_size}
{}

const unsigned int SetUpParams::independent_runs() const
{
    return _independent_runs;
}
const unsigned int SetUpParams::nb_evolution_steps() const
{
    return _nb_evolution_steps;
}
const unsigned int SetUpParams::population_size() const
{
    return _population_size;
}
const unsigned int SetUpParams::solution_size() const
{
    return _solution_size;
}
void SetUpParams::independent_runs(const unsigned int runs)
{
    _independent_runs = runs;
}
void SetUpParams::nb_evolution_steps(const unsigned int steps)
{
    _nb_evolution_steps = steps;
}
void SetUpParams::population_size(const unsigned int pop_size)
{
    _population_size = pop_size;
}
void SetUpParams::solution_size(const unsigned int sol_size)
{
    _solution_size = sol_size;
}
