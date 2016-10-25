#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>
//#include<ctype.h>
using namespace std;
int main()
{
	//string::size_type sz;

	string suma ="+";
	string resta  = "-";
	string mult = "*";
	string divisio = "/";
	string plus = "plus";
	string minus = "minus";
	string mul = "mul";
	string div = "div";
	string operation = suma ;
	string op1 = "1";
//	istringstream ss(str);
	long double primer;
	long double segon;
	long double resultat;
	string op2 = "2";
	string surt = "q";
//	cin >> numero;
        cout << "dóna'm una operació (+, -, *, /) i 2 operands i et retornaré el resultat de l'operació (\"q q q\" per sortir),p.ex : + 1 2 ";
		
	while (operation.compare(surt)){ //strcmp(numero,surt)!=0){
		cin >> operation >> op1 >> op2;
		cout << "operation = " << operation << "operand 1 = " << op1 << "operand 2 = " << op2 << "\n" ;
		//primer = stoi(op1, 10);
		if (operation.compare(suma)==0) {
				istringstream ss(op1);
				ss >> primer;
				istringstream ss1(op2);
				ss1 >> segon;
				resultat = primer + segon;	
				cout << "\n suma de 2 sumants \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la suma = " << resultat << "\n";			
//				segon =stoi(op2,10);
		}
		if (operation.compare(resta)==0){
				istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = primer - segon;
				cout << "\n Resta de 2 sumants \n" << op1 << " i " << op2 << "\n  primer = "<< primer << " \n segon = " << segon  << " \n resultat de la resta = " << resultat << "\n";
		}
		if (operation.compare(mult)==0){
				istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = primer * segon;
				cout << "\n Multiplicació de 2 factors \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la multiplicació = " << resultat << "\n";
		}
		if (operation.compare(divisio)==0){
				istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = primer / segon;
				cout << "\n Divisió de 2 factors \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la divisió = " << resultat << "\n";
		}
		if (operation.compare(plus)==0){
                                istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = 0;// primer ^ segon;
                                cout << "\n PLUS??? de 2 factors \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la divisió = " << resultat << "\n";
                }
		if (operation.compare(minus)==0){
                                istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = primer / segon;
                                cout << "\n MINUS?? de 2 factors \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la divisió = " << resultat << "\n";
                }
		if (operation.compare(mul)==0){
                                istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = primer / segon;
                                cout << "\n MUL???? de 2 factors \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la divisió = " << resultat << "\n";
                }
		if (operation.compare(div)==0){
                                istringstream ss(op1);
                                ss >> primer;
                                istringstream ss1(op2);
                                ss1 >> segon;
                                resultat = primer / segon;
                                cout << "\n DIV???? de 2 factors \n" << op1 << " i " << op2 << "\n primer = "<< primer << " \n segon = " << segon  << " \n resultat de la divisió = " << resultat << "\n";
                }

	}

	return (0);
}
