#ifndef ALGORITHM_H
#define ALGORITHM_H
#include"Problem.h"
#include"Solution.h"
#include"SetUpParams.h"
#include<random>
#include <limits>
#include <cmath>

class Algorithm
{
    public:
        Algorithm(const Problem& pbm, const SetUpParams& setup);
		~Algorithm();
		const SetUpParams& setup() const;
	  	void initialize();
        void evaluate();     //evaluate the current population

	 	const vector<Solution*>& current_solutions() const;
		double global_best_cost() const;                                // pas encore defini
		Solution& solution(const unsigned int index) const;

		Solution global_best_solution();
		Solution global_best_solution() const;
		double bestFitness() const;
		double worstFitness() const;
 		void evolution(); // main loop of the algorithm                // pas encore defini
		void main();
    private:
        vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values_of_current_population;
        Solution _sol;
        const Problem& _pbm;
		const SetUpParams& _setup;
		Solution _global_best_solution;
		double _lower_cost;
		double _upper_cost;

};

#endif // ALGORITHM_H
