#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int debug =0;
	double A;
	double B;
	double C;
	double resultat1;
	double resultat2;
	double calcul;
	cout<< endl << " resolució d'equacions quadrades (Ax2+Bx+C)" << endl<< "Entra el valor de A B C ";
	cin >> A >> B >> C;
	calcul=pow(B,2)-4*A*C;
	if(calcul>0){
			resultat1 = (-B+sqrt(calcul))/(2*A);
		        resultat2 = (-B-sqrt(calcul))/(2*A);
			cout << " té 2 solucions reals : " << resultat1 << ", " << resultat2 << endl;
	}
	else if(calcul<0){
			 cout << "No existeix solucions reals " << endl;
			}
		else {
			resultat1 = (-B)/(2*A);
			cout << " Només té aquesta solució : " <<  resultat1;
		}
}
