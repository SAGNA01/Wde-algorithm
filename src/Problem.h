#ifndef PROBLEM_H
#define PROBLEM_H

class Problem
{
    public:
        Problem();
        ~Problem();
        int dimension() const;
        double LowerBound() const;
        double UpperBound() const;
        void benchmarks();

    private:
        int _dimension;
		double _LowerBound;
		double _UpperBound;
};

#endif // PROBLEM_H
