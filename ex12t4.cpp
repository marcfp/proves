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
//	vector<int> it;
	vector<int>::iterator it;
	int numero;
	int primer;
	int i;
	cout << "Des de quin numero vols que et cerqui tots els números primer ?";
	cin >> numero;
	for (int i=2;i<=numero;++i) {
		if(!cin.fail()){
			primer=primers(vect, i);
//			if(primer==0) cout << endl << "NO ÉS PRIMER" << endl;
			if(primer!=0){
//				cout << endl << "ÉS PRIMER!!!!" << endl;
				//afegir primer al vector i llistar vector quan hagi acabat el bucle for
				it = vect.begin();
				  it = vect.insert ( it , primer );
			//	vect.insert(it,primer);	
			//	it++;
				}
		}
		else {
			cout << "Això no és un número vàlid"<< endl;
		}
	}
	cout << "Els primers són :" << endl;
	for(it=vect.begin(); it<vect.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
	return(0);
}

int primers(vector<int> vect, int numero)
{
	int i=2;
	bool primer=true;
//	cout << "Vector" << endl;
	//falta guardar-ho en un vector i incremantar l'index del vector, pk mirar on estic quan fa la comprobació ?
//	for(i=2; i<=numero; ++i){
	while(i<=numero){
//		cout << "i = " << i << endl;
		if(numero%i==0 && numero!=i) {
				//cout << " numero " << numero << " divisible per " << i << endl;
				return (0); //1 NO ÉS PRIMER
//				return (1);
				}
		else{
		//	cout << "numero" << numero << "NO divisible per " << i << endl;
			if(numero==i) return(i);	
//			 return(0);		
		}
	++i;
	}

}
