#include<iostream>
#include"Problem.h"
#include"Algorithm.h"
#include"Benchmark.h"
using namespace std;

int menu(){
    int input;
    do{
        std::cout<<"1 - Run the function\n2 - Change benchmark function\n3 - Quit"<<std::endl;
        std::cin>>input;
    } while(input<1 && input>3);
    return input;
}
int main(){
    cout<<"**************** Weighted differential evolution algorithm ***********"<<endl;
    Problem problem = Problem(30, -5, 5, BentCigar);
    int choice = menu();
    while(choice != 1){
        switch(choice){
            default:
                break;
            case 2:
                problem.lire(cin,problem);
                break;
            case 3:
                std::exit;
        }
        choice = menu();
    }
    problem.print(cout, problem);
    SetUpParams setup = SetUpParams(0,0,0,0);
    std::cin >> setup;
    Algorithm algoWDEA = Algorithm(problem, setup);
    algoWDEA.main();
    return 0;
}

