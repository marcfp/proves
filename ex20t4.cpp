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
	vector<string> names;
	vector<int> scores;
	vector<int>::iterator it;
	vector<string> noname;
	vector<int> edat;
	int i=0;
	int contador=0;
	noname.push_back("NoName");
	edat.push_back(0);
	int zero=200;
	string nom;
//	while(names != noname){
//	cout << equal(names.begin(),names.end(),noname);
	cout << "Entra nom edat així : Joe 17, acabaràs quan introdueixis NoName 0" << endl;
	while(nom!="NoName" && zero!=0) {
			cin >> nom >> zero;
			names.push_back(nom);
			scores.push_back(zero);
		if(names.at(contador)==noname.at(0) && scores.at(contador)==edat.at(0)) {
		contador++;
		cout << "final trobat?\n";
//cout << "final trobat ?";	
	//	break;	
		}
//		else cout<< "No es final\n";
//		contador++;
	}
//	cout << "nom entrat = " << names[0];
	//}

	cout << endl << "llegeixo" << endl;
	cout << endl << "imprimeixo tots els valors (1 parella per linea)" << endl;
/*	names.erase(names.end(),names.back());
	scores.erase(scores.end(),scores.back());*/
	for(int i=0; i<names.size(); i++) {
		cout << names.at(i) << " " << scores.at(i) << "\n";
	}

	vector<string> cercanom;
	string cerca;
	cout << endl << "Introdueix el nom que vols cercar-li el seu corresponent valor :";
	cin >> cerca;
	for(int i=0;i<names.size();++i){
		if(cerca==names.at(i)) {
			cout << endl << "Nom trobat " << names.at(i) << " a la posició " << i+1 << " amb el valor " << scores.at(i) << " corresponent...  " << endl;
		}
	}	
	
return(0);
}
