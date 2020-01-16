#include<iostream>
#include"Problem.h"
#include"Algorithm.h"
using namespace std;

fonction AskAlgo()
{
    int input;
    cout << "**************** Weighted differential evolution algorithm ***********"<<endl;
    cout << "1 : BentCigar function\n"<<"2 : Discus function\n"<<"3 : Weierstrass function\n"<<"4 : Katsuura function\n";
    cout << "5 : HappyCat function\n"<<"6 : HGBat function\n";
    cout << "======================================================================" << endl;
    cout << "Function Id : ";
    cin >> input;
    while(input < 1 && input > 6)
    {
        cout << "Invalid Id!\n";
        cout << "Function Id : ";
        cin >> input;
    }
    switch (input)
    {

    case 1:
        return BentCigar;
        break;

    case 2:
        return Discus;
        break;

    case 3:
        return Weierstrass;
        break;

    case 4:
        return Katsuura;
        break;

    case 5:
        return HappyCat;
        break;

    case 6:
        return HGBat;
        break;

    }
    return BentCigar;
}

int menu(){
    int input;
    do{
        std::cout<<"1 - Run the function\n2 - Change benchmark function\n3 - Quit"<<std::endl;
        std::cin>>input;
    } while(input<1 && input>3);
    return input;
}
int main(){
    Problem problem = Problem(30, AskAlgo());
    SetUpParams setup(1, 10050, 40, 20);

    Algorithm algoWDEA = Algorithm(problem, setup);
    algoWDEA.run();
    return 0;
}



