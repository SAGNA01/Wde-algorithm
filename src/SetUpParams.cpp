#include "SetupParams.h"


SetUpParams::SetUpParams(unsigned int runs, unsigned int steps, unsigned int pop_size, unsigned int sol_size) :
                                                           _independent_runs{runs}, _nb_evolution_steps{steps},
                                                           _population_size{pop_size}, _solution_size{sol_size}
{}

const unsigned int SetUpParams::independent_runs() const{
    return _independent_runs;
}

const unsigned int SetUpParams::nb_evolution_steps() const{
    return _nb_evolution_steps;
}

const unsigned int SetUpParams::population_size() const{
    return _population_size;
}

const unsigned int SetUpParams::solution_size() const{
    return _solution_size;
}

void SetUpParams::independent_runs(const unsigned int runs){
    _independent_runs = runs;
}

void SetUpParams::nb_evolution_steps(const unsigned int steps){
    _nb_evolution_steps = steps;
}

void SetUpParams::population_size(const unsigned int pop_size){
    _population_size = pop_size;
}

void SetUpParams::solution_size(const unsigned int sol_size){
    _solution_size = sol_size;
}

double SetUpParams::getCR() const{
    return _CR;
}

istream& operator >> (std::istream& entree, SetUpParams& setup)
{
    cout << "number of independent runs (runs): "; entree >> setup._independent_runs;
    cout << "number of solutions in the population (PopSize) : "; entree >> setup._population_size;
	cout << "size of each particle (solsize) : "; entree >> setup._solution_size;
	cout << "number of iterations per run (steps) : "; entree >> setup._nb_evolution_steps;
    /*if (setup.getPopSize() >= 30)
	{
		setup.defineNbItRun(((2 * pow(10, 6)) / setup.getPopSize()));
	}
	else{
		setup.defineNbItRun(3000);
	}
	cout << setup.getNbItRun() << endl;
	cout << "Probabilite de Mutation entre 0 et 1 : ";
	is >> setup.mixrate;
	if (setup.mixrate >= 1 || setup.mixrate <= 0)
		cout << "error" << endl;
*/
}

