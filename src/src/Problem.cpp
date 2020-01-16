#include"Problem.h"
#include<cmath>

Problem::Problem(int dim, fonction f) : _dimension{dim}, _fonction{f}, _LowerBound{}, _UpperBound{}, _calls{0}

{
    switch (_fonction)
    {
        case BentCigar:
	    std::cout<<"BentCigar function selected"<<std::endl;
		_LowerBound = -2.048;
		_UpperBound = 2.048;
		break;

	case Discus:
	    std::cout<<"Discus function selected"<<std::endl;
		_LowerBound = -5.12;
		_UpperBound = 5.12;
		break;

	case Weierstrass :
	    std::cout<<"Weierstrass function selected"<<std::endl;
		_LowerBound = -32.768;
		_UpperBound = 32.768;
		break;

	case Katsuura:
	    std::cout<<"Katsuura function selected"<<std::endl;
		_LowerBound = -500;
		_UpperBound = 500;
		break;

	case HappyCat:
	    std::cout<<"HappyCat function selected"<<std::endl;
		_LowerBound = -100;
		_UpperBound = 100;
		break;

	case HGBat:
	    std::cout<<"HGBat function selected"<<std::endl;
		_LowerBound = -30;
		_UpperBound = 30;
		break;

        default:
            cout << "Error in Problem!" << endl;
            break;
    }
}

Problem::~Problem()
{}
/*
void Problem::print(std::ostream& sortie, const Problem& pbm) const
{
    sortie << "========================Problem : Parametres==========================" << std::endl;
    sortie << " Lower Bound : " << pbm._LowerBound << std::endl;
    sortie << " Upper Bound : " << pbm._UpperBound << std::endl;
    sortie << " Dimension : " << pbm._dimension << std::endl;
    sortie << "======================================================================" << std::endl;
}
*/

fonction Problem::laFonction() const{
   return _fonction;
}

string Problem::name() const{
    switch (_fonction)
    {

    case BentCigar:
        return "BentCigar";
        break;

    case Discus:
        return "Discus";
        break;

    case Weierstrass:
        return "Weierstrass";
        break;

    case Katsuura:
        return "Katsuura";
        break;

    case HappyCat:
        return "HappyCat";
        break;

    case HGBat:
        return "HGBat";
        break;

    default:
            return "Error : Problem.name() does not exist!";
}  }

/*
void Problem::read(std::istream& entree, Problem& pbm){
    int input;
    do{
         std::cout<<"1 : BentCigar function\n"<<"2 : Discus function\n"<<"3 : Weierstrass function\n"<<"4 : Katsuura function\n";
         std::cout<<"5 : HappyCat function\n"<<"6 : HGBat function\n";
         std::cout<< "======================================================================" << std::endl;
    	 std::cout <<"       Function Id : ";
    } while(input< 1 && input>6);
	    entree>>input;
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
} */

int Problem::dimension() const{
    return _dimension;
}

double Problem::LowerBound() const{
    return _LowerBound;
}

double Problem::UpperBound() const{
    return _UpperBound;
}

long long int Problem::calls() const
{
    return _calls;
}

Problem& Problem::operator++()
{
    ++_calls;
    return *this;
}

