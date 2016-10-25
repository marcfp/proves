#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void introdueix(char &num_user,vector<char> &entra, int &conta)
{
	do{
		cout << "\nEntra la lletra de la posicio " << conta+1 << " que vols encertar : " ;
		cin >> num_user;
		do{
			if(conta>=1 && entra.at(conta-1)==num_user) { 
				cout << "repetimos!!! ÚLTIMA lletra no vàlida!!!!";
				cout << "\nllegeixo de nou\n";
				cin >> num_user;
			}
		}while(conta>=1 && entra.at(conta-1)==num_user);
		//numero=rand()%9;
		entra.push_back(num_user);
		cout << "\nnlletra_user entrat= " << num_user  << "\n"; //Sortir ? ";
		//cin >> s;
		conta++;
	}while (conta<4);

}
void carregar( char &numero, vector<char> &tria, int &conta)
{
        int num_random;
	int lletra;
	do{
		num_random = rand()%25;
		lletra = rand()%1;//lletra 0 majúscula lletra 1 minúscula
		cout << " num_random = " << num_random << endl;
		if(lletra==0) {
			cout << " lletra MAJÚSCULA posició = " << num_random << endl;
			num_random=num_random+64;
			numero = (char)num_random;
		}
		else{
			cout << " lletra minúsucla posició = " << num_random << endl;
			num_random=num_random+97;
			numero= (char)num_random;
	
		}
		//numero=rand()%255;
		tria.push_back(numero); //carrega 1 7 0 7
		cout << "numero = " << numero  << "\n lletra = " << lletra << endl; //Sortir ? ";
		//cout << "num_random = " << num_random << " lletra = " << lletra << endl;
		//cin >> s;
		conta++;
	}while (conta<4);
}

int main()
{
char numero;
int conta=0;
char num_user;
int cows=0;
int bulls=0;
char c='s';
char s;
bool encert=true;
bool repetit=true;
vector<char> tria;
vector<char> entra;
cout << "game \"bulls and cows\", 4 numbers, user must discover them.Program has 1234( but not 1122) and user insert 1359, the response should be \"1 bull and 1 cow\" 1 bull becouse user got digit one(1) right and in right position, 1 cow becouse there are one 3 in the number but it isn't in the right position. the loop continues while user gets four bulls (the four digits in the correct order).\n\n\n \t New VERSION : Insert letters instead of numbers " << endl;
carregar(numero, tria,conta); //carrego valors
cout << "recorregut del vector : \n" ;
//for(int i=0;i<tria.size();++i) cout << "posició " << i << " conté el número " << tria[i] << "\n";

conta=0;

introdueix(num_user,entra, conta); //introdueix valors


//cout << "entra.size()=" << entra.size() << "\n";
//for(int i=0;i<entra.size();++i) cout << "posició " << i << " conté el número " << entra[i] << "\n";

for(conta=0; conta<4; ++conta){
	cout << "tria.at(conta) =" << tria.at(conta) << "\n";
	if(tria.at(conta) != entra.at(conta)) {
					encert=false;
					cout << "\nno encertat en la posicio " << conta+1 << " que hi ha el valor " << tria.at(conta);
					if(tria.at(conta)==entra.at(0) || tria.at(conta)==entra.at(1) || tria.at(conta)==entra.at(2) || tria.at(conta)==entra.at(3)) cows++;
	cout << "cows = " << cows;
	}
	else{
		bulls++;
		cout << "\n number of bulls = " << bulls << "\n";
	}
}
//cout << "\nentrar 4 números i comprobar que sigui el mateix de cada posició(bull), sino fer el contador de números que existeixen però no són a posicio(cow)\npàgina 163\n";
cout << " bulls = " << bulls << " i cows = " << cows << "\n";
return (0);
}
