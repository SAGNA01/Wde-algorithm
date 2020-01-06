#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include"Problem.h"
#include"SetUpParams.h"

using namespace std;
class Solution
{
    public:
        Solution();
        Solution(const Problem& pbm);
		Solution(const Solution& sol);

		~Solution() = default;
		void initialize();
		const Problem& pbm() const;
		void fitness();
		double get_fitness() const;
		vector<double>& get_solution() const;

		double& get_position_in_solution(const int index);
        void  set_position_in_solution(const int index, const double value);

		vector<double> mutation(int i , vector<Solution*> pop, SetUpParams setup);

    private:
        vector<double> _solution;
        double _fitness_current;
		const Problem& _pbm;
};

#endif // SOLUTION_H
