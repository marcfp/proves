#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int square(int x)
{
	return x*x;
}
int main()
{
	int debug =0;
	int valor;
	int i;
	int resultat=0;
	cout<< endl << "Entra un valor i et retornaré el seu quadrat sumant " << endl << "Valor = " ;
	cin >> valor;
	i=valor;
	while (i>0)
	{
		resultat =resultat+valor;
		--i;
	}
	cout << endl << "el resultat és " << resultat << endl;
	cout << endl << " el resultat usant la funció square = " << square(valor) << endl;
return(0);
}

