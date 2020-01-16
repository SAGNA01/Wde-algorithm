#include"Solution.h"
#define _USE_MATH_DEFINES
#include<cmath>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include<random>

const double PI = 3.141592653589;

//~~~~~~~~~~~~ Constructor ~~~~~~~~~~~~
Solution::Solution(Problem& pbm) : _solution{}, _fitness_current{}, _pbm{pbm}
{
    //initialize();
}

Solution::Solution(const Solution& sol) :
        _solution{sol._solution}, _fitness_current{sol._fitness_current}, _pbm{sol._pbm}
{
    _solution.resize(sol._solution.size());
	_solution = sol._solution;
}

Solution::~Solution()
{}

//~~~~~~~~~~~~ Benchmark ~~~~~~~~~~~~

double BentCigarFunction(const std::vector<double>& sol){
    double sum = pow(sol[0],2);
    for(unsigned int i = 2; i <sol.size(); i++){
        sum += pow(10.0, 6.0) * pow(sol[i],2);
    }
    return sum;
}

double DiscusFunction(const std::vector<double>& sol){
     double sum = pow(10, 6) * pow(sol[0],2);
     for(unsigned int i = 2; i < sol.size(); i++)     {
         sum += pow(sol[i],2);
     }
     return sum;
}

double WeierstrassFunction(const std::vector<double> &X)
{
    double a = 0.5, b = 3.0;
    double kMax = 20.0;
    double sum1 = 0.0;
    for (unsigned i = 0; i < X.size(); ++i)
    {
        double sum2 = 0.0;
        for (int k = 0; k <= kMax; ++k)
            sum2 += std::pow(a, k) * std::cos( 2.0 * PI * std::pow(b, k) * (X[i] + 0.5) );
        sum1 += sum2;
    }
    double sum3 = 0.0;
    for (int k = 0; k <= kMax; ++k)
        sum3 += std::pow(a, k) * std::cos( 2.0 * PI * std::pow(b, k) * 0.5 );cout << "ok";
    return sum1 - X.size() * sum3;
}

double KatsuuraFunction(const std::vector<double>& sol){
    double d = 20;
    double prod = 1.0;
    for(unsigned int i = 0; i < sol.size(); i++){
        double sum = 0;
        for(int j = 0 ; j < 32; j++)        {
            sum += (abs(pow(2,j) * sol[i] - floor(pow(2,j * sol[i]))) / pow(2,j));
        }
        prod *= pow((1 + i * sum ),10.0/(pow(d, 1.2)));
    }
    return ((10/pow(d,2)) * prod - (10/pow(d,2)));
}

double HappyCatFunction(const std::vector<double>& sol){
    double alpha, sum, r2;
    alpha = 1.0 / 8.0;
    sum = 0.0;
    r2 = 0.0;
    double f = 0.0;
    for(unsigned int i = 0; i < sol.size(); i++){
        r2 += pow(sol[i],2);
        sum += sol[i];
    }
    f = pow(abs(r2 - sol.size()), 2 * alpha) + (0.5 * r2 + sum) / sol.size() + 0.5;
    return f;
}

double HGBatFunction(const std::vector<double>& sol){
    double alpha, sum, r2;
    alpha = 1.0 / 0.4;
    sum = 0.0;
    r2 = 0.0;
    for(unsigned int i = 0; i < sol.size(); i++){
        r2 += pow(sol[i],2.0);
        sum += sol[i];
    }
     double result = pow(abs(pow(r2, 2.0) - pow(sum, 2.0)), 2 * alpha) + (0.5 * r2 + sum) / sol.size() + 0.5;
     return result;
}


//~~~~~~~~~~~~ MainF ~~~~~~~~~~~~

void Solution::initialize(){ //?
    _solution.clear();
    _solution.reserve(_pbm.dimension());
	 double nbAleatoire, k, _min, _max;
    _min = _pbm.LowerBound();
    _max = _pbm.UpperBound();

    for (unsigned int i = 0; i < _solution.size(); ++i){
        k = (double)rand() / (RAND_MAX+1);
	    nbAleatoire = _min + k * (_max - _min);
	    _solution[i] = (nbAleatoire);
	}

	//fitness();
}

void Solution::fitness() {
   ++_pbm;
    double value = -1.0;
    switch(_pbm.laFonction())
    {

    case BentCigar:
        value = BentCigarFunction(_solution);
        break;

    case Discus:
        value = DiscusFunction(_solution);
        break;

    case Weierstrass:
        value = WeierstrassFunction(_solution);
        break;

    case Katsuura:
        value = KatsuuraFunction(_solution);
        break;

    case HappyCat:
        value = HappyCatFunction(_solution);
        break;

    case HGBat:
        value = HGBatFunction(_solution);
        break;
    }
    _fitness_current = value;
}

void  Solution::set_fitness(double fitness)
{
    _fitness_current = fitness;
}

double Solution::get_fitness() const
{
    return _fitness_current;
}

const Problem& Solution::pbm() const{
    return _pbm;
}

double& Solution::get_position(const int index){
    return _solution[index];
}

void Solution::set_position(const int index, const double value){
    _solution[index] = value;
}

//~~~~~~~~~~~~ Vector ~~~~~~~~~~~~

vector<double> Solution::get_solution() const{
    return _solution;
}

vector<double> Solution::mutation(int i, vector<Solution*> pop ,SetUpParams setup){
    pop.resize((unsigned long long int) _pbm.dimension());
    int a, b, c;
    do{
        a = (int)rand() %setup.population_size();
    } while (a == i);

    do{
        b = (int)rand() %setup.population_size();
    } while (b == i || b == a);

    do{
        c = (int)rand() %setup.population_size();
    } while (c == i || c == a || c == b);

    double F;
    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 1.0);
    F = 3 * distribution(generator);

    vector<double> mutant;
    for(unsigned int j = 0; j < setup.solution_size(); j++)
    mutant.push_back(pop[i]->get_solution()[j] +
                  (F * pop[b]->get_solution()[j]  -
                   pop[c]->get_solution()[j]));
    //_solution = mutant;
    return mutant;
}

//~~~~~~~~~~~~ Operator ~~~~~~~~~~~~
ostream& operator<<(ostream& os, const Solution& sol)
{
    unsigned i;
    for (i = 0; i < sol._solution.size() - 1; ++i)
        os << sol._solution[i] << ", ";
    os << sol._solution[i];
    return os;
}

Solution& Solution::operator=(const Solution& sol)
{
    _solution = sol._solution;
    _fitness_current = sol._fitness_current;
    return *this;
}

Solution& Solution::operator*=(double factor)
{
    for (unsigned i = 0; i < _solution.size(); ++i)
        _solution[i] *= factor;

    return *this;
}

Solution Solution::operator*(double factor) const
{
    Solution S(*this);
    S *= factor;
    return S;
}

void Solution::set_solution(vector<double> solution){
_solution = solution;}

