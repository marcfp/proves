#include<iostream>
#include<stdlib.h>
#include <stdio.h>
//#include <string.h>
using namespace std;
int main()
{

	char a[20];
	double valor1;
	double minim, maxim;
	int volta=0;

	cout << "\n Estic al punt 3 de la pàgina 126 \n";
	cout << "\n Entra 1 número enter \n per sortir escriu \"|\"";
	while(a[0]!='|')//surt[0])
	{
		cin >> a ;
		valor1 = atof(a);
		if(volta==0){
			volta=1; 
			minim=atof(a);
			maxim=atof(a);
		}
		cin.clear();
		if(valor1<=minim) minim=valor1;
		if(valor1>=maxim) maxim=valor1;
		printf("El valor minim = %f  i el maxim = %f, i són aquests de lluny ?", minim, maxim);
	}

return(0);
}

