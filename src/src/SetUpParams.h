#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H
#include<iostream>
using namespace std;

const double CROSSRATE = 0.9;

class SetUpParams
{
    public:
        SetUpParams(unsigned int runs, unsigned int steps, unsigned int pop_size, unsigned int sol_size); // = Const?
        ~SetUpParams();
     	friend istream& operator >> (std::istream& is, SetUpParams& setup);
 		friend ostream& operator <<(ostream& os, const SetUpParams& setup);

        const unsigned int   independent_runs() const;
		const unsigned int   nb_evolution_steps() const;
		const unsigned int   population_size() const;
		const unsigned int   solution_size() const;

		//void UpperBound (const int up);
		//void LowerBound (const int low);
		void independent_runs(const unsigned int runs);
		void nb_evolution_steps(const unsigned int steps);
		void population_size(const unsigned int pop_size);
		void solution_size(const unsigned int sol_size);
		double getCR()const;

    private:
        const double _CR = CROSSRATE;              // Crossover rate
        unsigned int   _independent_runs;         //number of independent runs
		unsigned int   _nb_evolution_steps;      // number of iterations per run
		unsigned int   _population_size;		// number of solutions in the population
		unsigned int   _solution_size;	       // size of each particle
};

#endif // SETUPPARAMS_H
