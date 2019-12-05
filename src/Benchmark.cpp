#define _USE_MATH_DEFINES
//#include"Benchmark.h
#include<cmath>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

float M_PI = 3.643674;

double BentCigar(const std::vector<double>& sol)
{
    double sum = sol[0] * sol[0];
    for(int i = 2; i <sol.size(); i++)
    {
        sum =+ pow(10.0, 6.0) * sol[i] * sol[i];
    }
    return sum;
}
double Discus(const std::vector<double>& sol)
{
     double sum = (10.0, 6.0) * sol[0] * sol[0];
     for(int i = 2; i < sol.size(); i++)
     {
         sum =+ sol[i] * sol[i];
     }
     return sum;
}

double Katsuura(const std::vector<double>& sol)
{
    int dim = sol.size();
    int m = 32;
	double prod = 1;
	for(int i = 0; i < dim; i++)
    {
        double sum = 0;
		for(int j = 1; j < m; j++)
        {
  		    //int term = pow(2, j) * dim.valueOf[j];
//			sum+= std::abs(term - round(term)) / pow(2, j);

		}
    prod *= pow(1 + ((i + 1) * sum), 10.0/ pow(dim,1.2));
    }
	return (10.0 / dim * dim) * prod - (10.0 / dim * dim);
}


double Weierstrass(const std::vector<double>& sol)
{
    int a, b, kmax;
    a = 0.5;
    b = 3;
    kmax = 20;
	double sum = 0;
	for(int j = 0; j < kmax; ++j)
		for(int i = 1; i < sol.size(); ++i)
			sum += pow(a, j) * cos(pow(b, j) * M_PI * sol[i]+ 0.5);
	return sum;
}

double HappyCat(const std::vector<double>& sol)
{
    double alpha, sum, r2;
    alpha = 1.0 / 8.0;
    sum = 0.0;
    r2 = 0.0;
    double f = 0.0;
    for(int i = 0; i < sol.size(); i++)
    {
        //sol[i] -= 1.0;
        r2 += sol[i] * sol[i];
        sum += sol[i];
    }
    f = pow(abs(r2 - sol.size()), 2 * alpha) + (0.5 * r2 + sum) / sol.size() + 0.5;
    return f;
}

double HGBat(const std::vector<double>& sol)
{
    double alpha, sum, r2;
    alpha = 1.0 / 0.4;
    sum = 0.0;
    r2 = 0.0;
    for(int i = 0; i < sol.size(); i++)
    {
        //sol[i] = sol[i] - 1.0;
        r2 += sol[i] * sol[i];
        sum += sol[i];
    }
     double f = pow(abs(pow(r2, 2.0) - pow(sum, 2.0)), 2 * alpha) + (0.5 * r2 + sum) / sol.size() + 0.5;
     return f;
}
