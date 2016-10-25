#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int debug =0;
int check_edat(double edat)
{

int edat_total;
double mesos;

if(debug ==1)cout << "Edat entrada (en mesos)= " << edat << "\n";
edat_total = edat/12;
mesos = edat/12-edat_total;
cout << "Tens " << edat_total << " anys i " << mesos << " mesos de vida\n" ;
return(0);
}
int check_nom(string nom)
{
	int i=0;
	int bolea=0;
	int caracters = nom.length();
	//cout << "Entro ?";
	while (nom[i])
	{
		//if(!isalpha(nom[i])) bolea=1;
		if(nom[i]>'0' && nom[i]<'9'){
			if(debug ==1)cout << "És un número el caracter nom[i]= " << nom[i] ;
			bolea=1;
			return(bolea);
		}
		else{
			if(debug ==1)cout << "No és número, m'ho menjo\n nom[i]= " << nom[i]; 	
			 i++;	
		}
	}
	cout << "\nEl nom llegit que has introduit és  " << nom << ",\n amb una allarga de " << caracters << " caràcters \n";
	return(bolea);
}
int main()
{
string nom;
double edat;
int anys;
cout << "\n Dóna'm el teu nom ";
//while(check_nom(nom)!=0){
do{
cin >> nom;
}while(check_nom(nom)!=0);
cout << "\nDóna'm la teva edat (amb mesos) ";
do{
cin >> edat;
}while(check_edat(edat) !=0);
cout << "\nPàgina 78 \n";
return (0);
}
