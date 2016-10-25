#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
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
int check_nom(string nom, string letter)
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
	letter= letter + "\n Dear " + nom + ", ";
	cout << "\nDear  " << nom < ", "; // << ",\n amb una allarga de " << caracters << " caràcters \n";
	return(bolea);
}
int main()
{
char friend_sex {0};
string nom;
string letter;
double edat;
int anys;
cout << "\n Enter the name of the person you want to write to ";
//while(check_nom(nom)!=0){
do{
cin >> nom;
}while(check_nom(nom,letter)!=0);
letter = letter + "\n\tHow are you ? I am fine. I miss you.\n";
string friend_name;
cout << "\n Insert friend name ";
cin >> friend_name;
letter = letter + "Have you seen " + friend_name + " latelly ?";
cout << "\nWhich sex are you ? \n m <- for male\n f <- for female\n ";
while (friend_sex !='m' or friend_sex !='f')
	cin >> friend_sex;
if(friend_sex=='m') letter = letter + "If you see " + friend_name + " please ask him to call me.";
else if(friend_sex=='f') letter= letter + "If you see " + friend_name + "please ask her to call me.";
cout << "Insert how old are you";
int old_i;
char old;
cin >> old_i;
old = itoa(old_i,old,3);
if(old_i <=0 or old >109)
	letter = "You are kidding me!!!";
if (old_i <12 ) {
		old_i++;
		old= itoa(old_i,old, 3);
		letter = letter + "Next year you will be ";
		letter = letter + old;
}
if(old_i ==17) letter = letter + "\n Next year you will be able to vote.";
if (old_i >=70) letter = letter + "\nI hope you are enjoiering retirement"; 
letter = letter + "\n I hear you just had a brithday and you are " + old + " years old" ;
letter= letter + "\n\n\t\t\tYour Sincerely\n\n";
cout << "\n\n" << letter;
/*cout << "\nDóna'm la teva edat (amb mesos) ";
do{
cin >> edat;
}while(check_edat(edat) !=0);
cout << "\nPàgina 94 \n";*/
return (0);
}
