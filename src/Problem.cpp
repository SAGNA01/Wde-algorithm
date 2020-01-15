#include"Problem.h"
#include"Benchmark.h"
#include<cmath>

Problem::Problem() : _dimension{30}, _LowerBound{}, _UpperBound{}, _fonction{BentCigar}
{}

Problem::Problem(int dim, double low_bound, double up_bound, Fonction f) : _dimension{dim},
                                                                           _LowerBound{low_bound},
                                                                           _UpperBound{up_bound},
                                                                           _fonction{f}

{}

void Problem::print(std::ostream& sortie, const Problem& pbm) const
{
    sortie << "========================Problem : Parametres==========================" << std::endl;
    sortie << " Lower Bound : " << pbm._LowerBound << std::endl;
    sortie << " Upper Bound : " << pbm._UpperBound << std::endl;
    sortie << " Dimension : " << pbm._dimension << std::endl;
    sortie << "======================================================================" << std::endl;
}

Fonction Problem::fonction() const{
   return _fonction;
}

void Problem::lire(std::istream& ist, Problem& pbm){
	int input;

    do{
         std::cout<<"1 : BentCigar function\n"<<"2 : Discus function\n"<<"3 : Weierstrass function\n"<<"4 : Katsuura function\n";
         std::cout<<"5 : HappyCat function\n"<<"6 : HGBat function\n";
         std::cout<< "======================================================================" << std::endl;
    	 std::cout <<"       Function Id : ";
		 ist >> input;
    } while(input< 1 && input>6);
	   
    switch (input)
    {
	case 1: // BentCigar function
	    _fonction=BentCigar;
	    std::cout<<"2 BentCigar function selected"<<std::endl;
		pbm._LowerBound = -2.048;
		pbm._UpperBound = 2.048;
		break;
	case 2: // Discus function
	    _fonction=Discus;
	    std::cout<<"2 Discus function selected"<<std::endl;
		pbm._LowerBound = -5.12;
		pbm._UpperBound = 5.12;
		break;
	case 3: // Weierstrass function
	    _fonction=Weierstrass;
	    std::cout<<"3 Weierstrass function selected"<<std::endl;
		pbm._LowerBound = -32.768;
		pbm._UpperBound = 32.768;
		break;
	case 4: // Katsuura function
	    _fonction=Katsuura;
	    std::cout<<"4 Katsuura function selected"<<std::endl;
		pbm._LowerBound = -500;
		pbm._UpperBound = 500;
		break;
	case 5: // HappyCat function
	    _fonction=HappyCat;
	    std::cout<<"5 HappyCat function selected"<<std::endl;
		pbm._LowerBound = -100;
		pbm._UpperBound = 100;
		break;
	case 6: // HGBat function
	    _fonction = HGBat;
	    std::cout<<"6 HGBat function selected"<<std::endl;
		pbm._LowerBound = -30;
		pbm._UpperBound = 30;
		break;
	}
}

int Problem::dimension() const{
    return _dimension;
}

double Problem::LowerBound() const{
   return  _LowerBound;
}

double Problem::UpperBound() const{
    return _UpperBound;
}

Problem::~Problem()
{}
