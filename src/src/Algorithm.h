#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<random>
#include <limits>
#include <cmath>

#include"Problem.h"
#include"Solution.h"
#include"SetUpParams.h"

using namespace std;

class Algorithm
{
    public:
        Algorithm(Problem& pbm, SetUpParams& setup);
		~Algorithm();

		const SetUpParams& setup() const;
	  	void initialize();
        void evaluate();     //evaluate the current population
	 	const vector<Solution*>& current_solutions() const;
		//unsigned
		double global_best_cost() const;
		Solution& solution(const unsigned int index) const;
		Solution& global_best_solution() const;
		void UpdateBestSolution(Solution *NewSolution);

		void FindBestSolution();

 		double bestFitness() const;
		double worstFitness() const;

 		void evolution(int iteration); // main loop of the algorithm
		void run();

    private:
        vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values_of_current_population;
        Solution* _sol;
        const Problem& _pbm;
		const SetUpParams& _setup;
		Solution* _global_best_solution;
		double _lower_cost;
		double _upper_cost;

};

#endif // ALGORITHM_H
