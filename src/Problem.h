#ifndef PROBLEM_H
#define PROBLEM_H
#include<iostream>
#include<vector>

typedef double(*Fonction)(const std::vector<double>&);
class Problem
{
    public:
        Problem();
        Problem(int dim, double low_bound, double up_bound, Fonction f);
        ~Problem();
        int dimension() const;
        double LowerBound() const;
        double UpperBound() const;
        void print(std::ostream& sortie, const Problem& pbm) const;
		void lire(std::istream& ist, Problem& pbm);
        Fonction fonction() const;
        double benchmarks(std::vector<double>& sol);

    private:
        int _dimension;
		double _LowerBound;
		double _UpperBound;
		Fonction _fonction;
};

#endif // PROBLEM_H
