/*
14. Read (day-of-the-week,value) pairs from standard input. For example:
Click here to view code image
T uesda y 23 Frida y 56 T uesda y –3 T hursda y 99
Collect all the values for each day of the week in a vector<int>. Write out the values of the
seven day-of-the-week vectors. Print out the sum of the values in each vector. Ignore illegal
days of the week, such as Funday, but accept common synonyms such as Mon and monday.
Write out the number of rejected values.
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <locale> 
using namespace std;
void valida_dia(vector<string> nom, vector<int> each_day);
int main()
{
vector<string> nom;
vector<int> each_day;
string noms;
int numero;
cout << "Entra les dades, p.ex: dilluns 35\n" ;

while(cin >> noms>> numero){
	try{ 
		nom.push_back(noms);
		each_day.push_back(numero);
		valida_dia(nom, each_day);

		cout << "Dades entrades = :\n" ;
		for (int i=0;i<nom.size();++i)
			cout << " nom = " << nom[i] << "\n numero = " << each_day[i] << "\n";

	}
	catch(exception& e){
		cout << "Error !!!" << e.what() << "\n";
	}

}


return(0);
}
void valida_dia(vector<string> nom, vector<int> each_day)
{

	cout << "dins de valida_dia";
	string dll="dilluns";
	string dllc="dll";
	string dmt="dimarts";
	string dmtc="dmt";
	string dmc="dimecres";
	string dmcc="dmc";
	string dj="dijous";
	string djc="dj";
	string dv="divendres";
	string dvc="dv";
	string dss="dissabte";
	string dssc="dss";
	string dmg="diumenge";
	string dmgc="dmg";

	int suma=0;
/* prova */
//transform(nom[0].begin(), nom[0].end(), nom[0].begin(), ::tolower);
//cout << "nom[0] majúscules = " << nom[0];
/* fi prova*/

for (int i=0; i<nom.size(); ++i){
	transform(nom[i].begin(), nom[i].end(), nom[i].begin(), ::tolower);	
	if((nom[i].compare(dll)==0 || nom[i].compare(dllc)==0) ){
								suma=each_day.at(i)+suma;
								 cout << "\nprimer dia de la setmana escrit!!\n" << nom.at(i); 
	}
	else if(nom[i].compare(dmt)==0 || nom[i].compare(dmtc)==0){
								suma=each_day.at(i)+suma;
								cout << "\nSegon dia de la setmana escrit!!\n" << nom.at(i); 
	}
	else if(nom[i].compare(dmc)==0 || nom[i].compare(dmcc)==0){
								suma=each_day.at(i)+suma;
								 cout << "\nTercer dia de la setman escrit!!\n" << nom.at(i); 
	}
	else if(nom[i].compare(dj)==0 || nom[i].compare(djc)==0){
								suma=each_day.at(i)+suma;
								 cout << "\nQuart dia de la setman escrit!!\n" << nom.at(i); 
	}
	else if(nom[i].compare(dv)==0 || nom[i].compare(dvc)==0 ){ 
								suma=each_day.at(i)+suma;
								cout << "\nCinqué dia de la setman escrit!!\n" << nom.at(i);
	}
	else if(nom[i].compare(dss)==0 || nom[i].compare(dssc)==0 ){ 
								suma=each_day.at(i)+suma;
								cout << "\nSisé dia de la setman escrit!!\n" << nom.at(i); 
								}
	else if(nom[i].compare(dmg)==0 || nom[i].compare(dmgc)==0){ 
								suma=each_day.at(i)+suma;
								cout << "\nSeté dia de la setman escrit!!\n" << nom.at(i); 
								}
		else{
			 cout << "\nDia no reconegut!!!\n\n";
		}
	}
	cout << "\n\nSuma total de dies = " << suma << "\n\n";
}
