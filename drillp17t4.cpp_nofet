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
	string valor="1";
	vector<string>  vect;
	int i;
	int resultat=0;
	cout<< endl << "Entra valor, per acabar escriu 0" << endl << "Valor = " ;
	while(valor!=0){
		cin >> valor;
		if(valor!="0") 
			vect.push_back(valor);
	//		else cout << "només positius";
	
	}
	int max=vect[0].length;
	int min=vect[0].length;
//	int conta=0;
	string ntrobat;
	for(i=0;i<vect.size();++i) {
				int conta=0;
				if(vect[i].length>max) max=vect[i].length;
				if(vect[i].length<min) min=vect[i].length;
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
