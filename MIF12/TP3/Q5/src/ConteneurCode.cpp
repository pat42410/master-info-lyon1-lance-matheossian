#include "ConteneurCode.hpp"

using namespace std;

ConteneurCode::ConteneurCode(){

	nombreInstructions = 0;
	
}

ConteneurCode::~ConteneurCode(){}

void ConteneurCode::ajouterInstFinBlocCourant(Instruction* _instruction)
{
	

	//if(_instruction != NULL){
	
	tabInstruction.push_back(_instruction);
	nombreInstructions++;

	//}

}

void ConteneurCode::ajouterLesInstrFinBlocCourant(vector <Instruction*> _tabInstructions)
{
	for (unsigned int i = 0; i < _tabInstructions.size() ; i++)
	{
		tabInstruction.push_back(_tabInstructions[i]);
		nombreInstructions++;
	}
}


void ConteneurCode::affichageCode3AD()
{
	string temp = "";

	Instruction* i1;
	Operande* op1;
	Operande* op2;
	Operande* op3;
	string* operation;

	
	
	cout << "Code 3@" << endl;

	for (unsigned int i = 0 ; i < tabInstruction.size(); i++)
	{
		// On récupère tous les attibuts de l'instruction pour plus de lisibilité
	 	i1 = tabInstruction[i];
		op1 = i1->getOperande(1);
		op2 = i1->getOperande(2);
		op3 = i1->getOperande(3);
		operation = i1->getOperation();
		
		// OPERATIONS
		if ( (op1 != NULL) && (op2 != NULL) && (op3 != NULL) ){

			// on affiche les différents cas d'opération ( 2 entiers, 1 ident et 1 entier, 2 idents)
			if ((op1->isIdentifiant() == true) && (op2->isIdentifiant() == false) && (op3->isIdentifiant() == false)) // 2 entiers
				 cout << *op1->getSymbole()->getNomSymbole() << convOperation(1) << op2->getValConvString() << " " << *operation  << " " << op3 ->getValConvString()  << endl;
			 
			else if ((op1->isIdentifiant() == true) && (op2->isIdentifiant() == true) && (op3->isIdentifiant() == false)) // 1 ident 1 entier
				 cout << *op1->getSymbole()->getNomSymbole() << convOperation(1) << *op2->getSymbole()->getNomSymbole() << " " << *operation  << " " << op3 ->getValConvString()  << endl;

			else if ((op1->isIdentifiant() == true) && (op2->isIdentifiant() == false) && (op3->isIdentifiant() == true)) // 1 entier 1 ident
				 cout << *op1->getSymbole()->getNomSymbole() << convOperation(1) << op2->getValConvString() << " " << *operation  << " " << *op3->getSymbole()->getNomSymbole()  << endl;

			else if ((op1->isIdentifiant() == true) && (op2->isIdentifiant() == true) && (op3->isIdentifiant() == true)) // 2 idents
				 cout << *op1->getSymbole()->getNomSymbole() << convOperation(1) << *op2->getSymbole()->getNomSymbole() << " " << *operation  << " " << *op3->getSymbole()->getNomSymbole()  << endl;
		}


		// AFFECTATION seulement
		else if ((tabInstruction[i]->getOperande(1) != NULL) && (tabInstruction[i]->getOperande(2) != NULL))
		{
			cout << *op1->getSymbole()->getNomSymbole() <<" " << *operation << " " << op2->getValConvString() << endl;
		}
		
	}

}

Operande* ConteneurCode::getDerniereAffectationVariable(string nomVariable)
{
	
	for (int i = tabInstruction.size()-1; i >= 0; i--)
	{
	
		if (*tabInstruction[i]->getOperande(1)->getSymbole()->getNomSymbole() == nomVariable)
		{
			return tabInstruction[i]->getOperande(1);
		}
	}

	return NULL;
}


string ConteneurCode::convOperation(int _operation)
{

	switch(_operation){
		case 1: return " := ";
		break;
		case 2: return " + ";
		break;
		case 3: return " - ";
		break;
		case 4: return " * ";
		break;
		case 5: return " / ";
		break;
		case 6:return " (-) ";
		break;
		default: return "";
		break;
	}
}


