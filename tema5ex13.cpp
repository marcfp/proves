/*
13. The program is a bit tedious because the answer is hard-coded into the program. Make a version
where the user can play repeatedly (without stopping and restarting the program) and each game
has a new set of four digits. You can get four random digits by calling the random number
generator randint(10) from std_lib_facilities.h four times. You will note that if you run that
program repeatedly, it will pick the same sequence of four digits each time you start the
program. To avoid that, ask the user to enter a number (any number) and call srand(n) where n
is the number the user entered before calling randint(10). Such an n is called a seed, and
different seeds give different sequences of random numbers.
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
void introdueix(int &num_user,vector<int> &entra, int &conta)
{
	do{
		cout << "\nEntra el número de la posicio " << conta+1 << " que vols encertar : " ;
		if(getline(cin >> num_user)) cout <<  "\nok";
		else wcerr << "\nerror\n";
		do{
			if(conta>=1 && entra.at(conta-1)==num_user) { 
//				cin.clear();
				cout << "repetimos!!! ÚLTIM número no vàlid!!!!";
				cout << "\nllegeixo de nou\n";
				if(cin >> num_user) cout << "\nok2";
			}
		}while(conta>=1 && entra.at(conta-1)==num_user);
		//numero=rand()%9;
		entra.push_back(num_user);
		cout << "\nnum_user entrat= " << num_user  << "\n"; //Sortir ? ";
		//cin >> s;
		conta++;
	}while (conta<4);

}
void carregar( int &numero, vector<int> &tria, int &conta)
{
	 /* initialize random seed: */
	srand (time(NULL));
	do{
//		numero=rand()%9;
/*	if(tria.size()==5){
			if(tria.at(3)==tria.at(4)){
						do{
                                                        numero=rand()%9;
                                                }while(numero!=tria.at(3));
                                                cout << "numero diferent =" << numero << "\n";
                        }
		}
		else */
		if(tria.size()==4){
			cout << "numero 4 = " << numero << "\n";
			if(tria.at(3)==numero){
						do{
	                                                numero=rand()%9;
						}while(numero!=tria.at(2));
                                                cout << "numero diferent 3=" << numero << "\n";
                        }
			
		}
		else if(tria.size()==3){
			cout << "numero 3 = " << numero << "\n";
			if(tria.at(2)==numero){
						do{
                                                        numero=rand()%9;
                                                }while(numero!=tria.at(1));
                                                cout << "numero diferent 2=" << numero << "\n";
                        }
		}
		else if(tria.size()==2){
			cout << "numero 2 = " << numero << "\n";
			if(tria.at(1)==numero){ 
						do{
                                                        numero=rand()%9;
                                                }while(numero!=tria.at(0));
						cout << "numero diferent 1=" << numero << "\n";
			}
		}
		else numero=rand()%9;
		tria.push_back(numero); //carrega 1 7 0 7
		cout << "numero = " << numero  << "\n"; //Sortir ? ";
		//cin >> s;
		conta++;
	}while (conta<4);
}

void repeteix()
{
int numero;
int conta=0;
int num_user;
int cows=0;
int bulls=0;
char c='s';
char s;
bool encert=true;
bool repetit=true;
vector<int> tria;
vector<int> entra;
cout << "game \"bulls and cows\", 4 numbers, user must discover them.Program has 1234( but not 1122) and user insert 1359, the response should be \"1 bull and 1 cow\" 1 bull becouse user got digit one(1) right and in right position, 1 cow becouse there are one 3 in the number but it isn't in the right position. the loop continues while user gets four bulls (the four digits in the correct order).\n" ;
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
//return (0);
}
int main()
{
char jugar='s';
while(jugar=='s') {
	repeteix();
	cout << "vols tornar a jugar ?? (s/n)";
	cin >> jugar;
	if(jugar!='n' && jugar!='N' ) jugar='s';
	cout << "jugar = " << jugar << "\n";
	}
return(0);
}
