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
	noname.push_back("NoName");
	string zero="0";
	string nom;
//	while(names != noname){
//	cout << equal(names.begin(),names.end(),noname);
	cout << "Entra nom edat així : Joe 17, acabaràs quan introdueixis NoName 0" << endl;
	while(cin >> nom) names.push_back(nom);
//	cout << "nom entrat = " << names[0];
	//}

	cout << endl << "llegeixo" << endl;
	cout << endl << "imprimeixo tots els valors (1 parella per linea)" << endl;
return(0);
}
