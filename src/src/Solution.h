#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

#include"Problem.h"
#include"SetUpParams.h"
using namespace std;

class Solution
{
    public:
        Solution(Problem& pbm);
		Solution(const Solution& sol);
		~Solution();

		void initialize();
		void fitness();
        void set_fitness(double fitness);
		double get_fitness() const;
		const Problem& pbm() const;
		unsigned int size() const;
		double& get_position(const int index);
        void  set_position(const int index, const double value);
        void set_solution(vector<double> solution);

		vector<double>& solution();
		vector<double> get_solution() const;
		vector<double> mutation(int i , vector<Solution*> pop, SetUpParams setup);

		friend ostream& operator<<(ostream& os, const Solution& sol);
		friend istream& operator>>(istream& is, Solution& sol);
		Solution& operator=(const Solution& sol);
		bool operator==(const Solution& sol) const;
		bool operator!=(const Solution& sol) const;
		Solution& operator*=(double factor);
		Solution operator*(double factor) const;

    private:
        vector<double> _solution;
        double _fitness_current;
		Problem& _pbm;
};

#endif // SOLUTION_H
