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
int jugar(int volta , string user, bool bolea, vector<string> valors_usuari)
{
                while((user!=valors_usuari[0] || user!=valors_usuari[1] || user!=valors_usuari[2]) && volta<6) 
		{
                        cout << "Juguem al pedra, paper, tisores !" ;
                        cin >> user;
			if(debug==1)cout << "dades[user] = " << user << endl << "volta[user] = " << volta << endl;
			if(user==valors_usuari[volta]) {
				volta=6;
				bolea=true;
				cout << "Encertat!!!";
			}
                        ++volta;
                }
}
int main()
{
	string user;
	vector<string>::iterator it;
	vector<string> valors_usuari;
	
	int volta=0;
	bool bolea=false;
	
	it = valors_usuari.begin();
	it = valors_usuari.insert(it,"paper");
	it = valors_usuari.insert(it,"tisores");
	it = valors_usuari.insert(it,"pedra");
	it = valors_usuari.insert(it,"paper");
	it = valors_usuari.insert(it,"tisores");
	it = valors_usuari.insert(it,"pedra");

	volta=jugar(volta, user, bolea, valors_usuari);

	return(0);
}
