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


int primers(vector<int> vect, int numero);
int main(){
	vector<int>  vect;
	vector<int> it;
	int numero;
	int primer;
	int i;
	cout << "Des de quin numero vols que et cerqui tots els números primers ?";
	cin >> numero;
	for(i=0; i<=numero;++i){
		if(!cin.fail()){
			primer=primers(vect, i);
			if(primer==0){ /*cout << endl << "NO ÉS PRIMER" << endl; */}
			if(primer!=0){
//				 cout << endl << " -> " << primer << " <- ÉS PRIMER!!!!" << endl;
				//si el vector no té el número, que l'afegeixi
				bool existeix=false;
				for(int j=0;j<vect.size();++j)
					if(vect[j]==primer) existeix=true;
				if(existeix==false) vect.push_back(primer);
				}
		}
		else {
			cout << "Això no és un número vàlid"<< endl;
		}
	}
	cout << endl << "Aquests són els números primers : " << endl;
	for(i=0;i<vect.size();++i) cout << vect[i] << " " ;
	return(0);
}

int primers(vector<int> vect, int numero)
{
	int i=2;
	
	bool primer=true;
//	cout << "Vector" << endl;
	while(i<=numero){
//		cout << "i = " << i << endl;
		cout << endl << "i =" << i << "(size_t)i = " << (size_t)i  << endl;
		if(numero%i==0 && numero!=i) {
			//	cout << " numero " << numero << " divisible per " << i << endl;
				return (0); //0 NO ÉS PRIMER
				}
		else{
		//	cout << "numero" << numero << "NO divisible per " << i << endl;
			if(numero==i) return(i);	//i es primer
		}
	++i;
	}

}
