#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int debug=0;



int main()
{
	int debug =0;
	int valor=1;
	vector<int>  vect;
	int i;
	int resultat=0;
	cout<< endl << "Entra valor, per acabar escriu 0" << endl << "Valor = " ;
	while(valor!=0){
		cin >> valor;
		if(valor!=0) 
			vect.push_back(valor);
	//		else cout << "només positius";
	
	}
	int max=vect[0];
	int min=vect[0];
//	int conta=0;
	int ntrobat;
	for(i=0;i<vect.size();++i) {
				int conta=0;
				if(vect[i]>max) max=vect[i];
				if(vect[i]<min) min=vect[i];
				int mod= vect[i];
				int j=0;
				
				while(j<vect.size()){
					
					if(vect[i]==vect[j]){
							conta++;
							ntrobat=vect[i];
					}
					++j;	
				}
				cout << "vect[i]=" << vect[i] << " max =" << max << " min = " << min << "ntrobat =" << ntrobat << " conta = " << conta << endl;
				}
}
