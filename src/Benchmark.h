#ifndef BENCHMARK_H
#define BENCHMARK_H
#include<vector>

//Fonctions permettant l'evaluation d'une solution


/*
 BentCigar function
 sol : Position de la solution a evaluer
 return la valeur de la fitness de la solution
*/
double BentCigar(const std::vector<double>& sol);


/*
 Discus function
 sol : Position de la solution a evaluer
 return la valeur de la fitness de la solution
*/
double Discus(const std::vector<double>& sol);


/*
 Weierstrass function
 sol : Position de la solution a evaluer
 return la valeur de la fitness de la solution
*/
double Weierstrass(const std::vector<double>& sol);


/*
 Katsuura function
 sol : Position de la solution a evaluer
 return la valeur de la fitness de la solution
*/
double Katsuura(const std::vector<double>& sol);


/*
 HappyCat function
 sol : Position de la solution a evaluer
 return la valeur de la fitness de la solution
*/
double HappyCat(const std::vector<double>& sol);

/*
 HGBat function
 sol : Position de la solution a evaluer
 return la valeur de la fitness de la solution
*/
double HGBat(const std::vector<double>& sol);

#endif // BENCHMARK_H
