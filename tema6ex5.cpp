#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int debug=0;
class Frase{
public:
	string paraula;
};
int main(){
//	vector<string> names;
//	vector<string> noname;
	vector<Frase> paraules;
	string para;
	//vector<Frase> noms;
	vector<Frase> verbs;
	vector<Frase> conjuncions;
	vector<Frase> noms_reconeguts;
	string inicial;
	Frase inicio;
	inicial="birds";
	inicio.paraula=inicial;
	noms_reconeguts.push_back(inicio);
	inicial="fish";
	inicio.paraula=inicial;
	noms_reconeguts.push_back(inicio);
	inicial="C++";
	inicio.paraula=inicial;
	noms_reconeguts.push_back(inicio);
	inicial="rules";
	inicio.paraula=inicial;
	verbs.push_back(inicio);
	inicial="fly";
	inicio.paraula=inicial;
	verbs.push_back(inicio);
	inicial="swim";
	inicio.paraula=inicial;
	verbs.push_back(inicio);
	inicial="and";
	inicio.paraula=inicial;
	conjuncions.push_back(inicio);
	inicial="or";
	inicio.paraula=inicial;
	conjuncions.push_back(inicio);
	inicial="but";
	inicio.paraula=inicial;
	conjuncions.push_back(inicio);
/*	noms.push_back(inicial);
	inicial="fish";
	noms.push_back(inicial);
	noms.push_back("C++");
*/	
	cout << "Entra la frase com a \"l'English Grammar\" pàgina 179 del llibre, acabaràs l'introducció de la frase quan escriguis \".\" en línea nova?" << endl;
        cout << endl << "\nllegeixo\n" << endl;
	while(cin >> para  /*&& trobat==0*/){
				Frase parau;
				//nvdins.nom=nom;
				//nvdins.edat=zero;
				//nv.push_back(nvdins);
				parau.paraula=para;
				paraules.push_back(parau);
				if(para==".") break; //trobat=1; //forço trencament de bucle
				cout << para.find(".");
			//	if(para.find(".")) break;
	}

	cout << endl << "imprimeixo tots els valors (1 parella per linea)" << endl;
	
	for(int i=0; i<paraules.size(); i++)
		cout << "i=" << i  << " " << paraules[i].paraula << "\n";
	cout << "\n Imprimeixo noms_reconeguts \n";
	for(int i=0;i<noms_reconeguts.size();++i)
		cout << "i = " << i << " " << noms_reconeguts[i].paraula << "\n";
	for(int i=0;i<verbs.size();++i)
		cout << "i = " << i << " " << verbs[i].paraula << "\n";
	for(int i=0;i<conjuncions.size();++i)
		cout << "i = " << i << " " << conjuncions[i].paraula << "\n";

return(0);
}
