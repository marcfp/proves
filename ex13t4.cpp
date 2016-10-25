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


//int primers(vector<int> vect, int numero);
int main(){
	vector<int> A;
	vector<int> B;
//	vector<int> it;
	vector<int>::iterator it;
	int suma;
	int numero;
	int primer;
	int borrar=2;
	cout << "Des de quin numero vols que et cerqui tots els números primer ? (Sedàs d'Eratòstenes)";
	cin >> numero;
	for(int i=2; i<=numero;i++)
		A.push_back(i);

	cout << endl << " llista A conté (1):" << endl;
	for(int i=0; i<A.size(); ++i){
		int num;
		cout << "A[i]=" << A[i] << endl;
	//	B.insert(B.begin()+i, A[i]); //inserto a B
	}
	cout << endl << "entrat correctament" << "A.size() = " << A.size() << endl;
	
	cout << endl << " Llista A conté :" << endl;
	for(int i=0; i<A.size(); ++i) cout << "A[i]=" << A[i] << endl;
	cout << endl << " llista B conté :" << endl;
	
	for(int i=0; i<B.size(); /*i==2;--i*/++i)   cout << "B[i]=" << B[i] << endl;

	return(0);
}

