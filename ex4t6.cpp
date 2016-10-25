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

class Name_value{
		string nom;
		int valor;
	public :
//		void get_nom(string nom); 
		void set_values(string, int);
		string get_nom(string, int);
		int get_edat(string, int);
};
void Name_value::set_values(string n, int val){
	nom=n;
	valor=val;
}
string Name_value::get_nom(string n, int val){
	return(n);	
}
int Name_value::get_edat(string n, int val){
	return(val);
}

int main(){
	vector<Name_value> nom_valor;
/*	vector<string> names;
	vector<int> scores;
	vector<int>::iterator it;*/
	vector<string> noname;
	vector<int> edat;
	int i=0;
	int contador=0;
	noname.push_back("NoName");
	edat.push_back(0);
//	nom_valor.push_back(0);
	int zero=200;
	string n;
//	while(names != noname){
//	cout << equal(names.begin(),names.end(),noname);
	cout << "Entra nom edat així : Joe 17, acabaràs quan introdueixis NoName 0" << endl;
	while(n!="NoName" && zero!=0) {			
			cin >> n >> zero; //>> nom_valor.valor;
			nom_valor.set_values(n,zero);
/*			names.push_back(nom);
			scores.push_back(zero);*/
/*		if(names.at(contador)==noname.at(0) && scores.at(contador)==edat.at(0)) {
		contador++;
		cout << "final trobat?\n";
//cout << "final trobat ?";	
	//	break;	
		}
//		else cout<< "No es final\n";
//		contador++;*/

//	cout << "nom entrat = " << names[0];
/*	}*/

	cout << endl << "llegeixo" << endl;
	cout << endl << "imprimeixo tots els valors (1 parella per linea)" << endl;

/*	for(int i=0; i<names.size(); i++) {
		cout << names.at(i) << " " << scores.at(i) << "\n";
	}*/
return(0);
}
