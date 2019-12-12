#include "Problem.h"

Problem::Problem() : _dimension{20}, _LowerBound{}, _UpperBound{}
{

}
Problem::Problem(int fonction_id, int dim, double low_bound, double up_bound, Fonction f) : _fonction_id{fonction_id},
                                                                                            _dimension{dim},
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

void Problem::read(std::istream& entree, Problem& pbm)
{
    std::cout<<"1 : BentCigar function\n"<<"2 : Discus function\n"<<"3 : Weierstrass function\n"<<"4 : Katsuura function\n";
    std::cout<<"5 : HappyCat function\n"<<"6 : HGBat function\n";
    std::cout<< "======================================================================" << std::endl;

    	std::cout <<"                        Function Id : ";
	    entree>>pbm._fonction_id;
	    switch (pbm._fonction_id)
	{
	case 1: // BentCigar function
	    std::cout<<"1 BentCigar function"<<std::endl;
		pbm._LowerBound = -2.048;
		pbm._UpperBound = 2.048;
		break;
	case 2: // Discus function
	    std::cout<<"2 Discus function"<<std::endl;
		pbm._LowerBound = -5.12;
		pbm._UpperBound = 5.12;
		break;
	case 3: // Weierstrass function
	    std::cout<<"3 Weierstrass function"<<std::endl;
		pbm._LowerBound = -32.768;
		pbm._UpperBound = 32.768;
		break;
	case 4: // Katsuura function
	    std::cout<<"4 Katsuura function"<<std::endl;
		pbm._LowerBound = -500;
		pbm._UpperBound = 500;
		break;
	case 5: // HappyCat function
	    std::cout<<"5 HappyCat function"<<std::endl;
		pbm._LowerBound = -100;
		pbm._UpperBound = 100;
		break;
	case 6: // HGBat function
	    std::cout<<"6 HGBat function"<<std::endl;
		pbm._LowerBound = -30;
		pbm._UpperBound = 30;
		break;
	}
	//return entree;
}

int Problem::dimension() const
{
    return _dimension;
}

double Problem::LowerBound() const
{
    _LowerBound;
}

double Problem::UpperBound() const
{
    return _UpperBound;
}

Fonction Problem::fonction() const
{
    return _fonction;
}
Problem::~Problem()
{

}
