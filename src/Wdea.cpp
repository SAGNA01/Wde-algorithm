#include<iostream>
#include"Problem.h"

using namespace std;


int main()
{
    Problem problem = Problem();

    problem.read(cin,problem);
    problem.print(cout, problem);


    return 0;

}
