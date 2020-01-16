#ifndef PROBLEM_H
#define PROBLEM_H
#include<iostream>
#include<vector>
#include<string>

using namespace std;
enum fonction {BentCigar, Discus, Weierstrass, Katsuura, HappyCat, HGBat};

//typedef double(*Fonction)(const std::vector<double>&);
class Problem
{
    public:
        Problem(int dim, fonction f);
        ~Problem();

        friend ostream& operator<<(ostream& os, const Problem& pbm);
		friend istream& operator>>(istream& is, Problem& pbm);
		Problem& operator++();

		fonction laFonction() const;
		string name() const;
        int dimension() const;
        double LowerBound() const;
        double UpperBound() const;
        long long int calls() const;

    private:
        int _dimension;
		fonction _fonction;
		double _LowerBound;
		double _UpperBound;
		long long int _calls;
};

#endif // PROBLEM_H
