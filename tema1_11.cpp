#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>
//#include<ctype.h>
using namespace std;
int main()
{
	//string::size_type sz;
	cout << "\nConversor de diners (centims (1, 2, 5, 10, ..), euros) a lletra\n";
	//pennies = 1
 	//nickels = 5;
	//dimmies = 10;
	//quaraters = 25;
	//half dolars = 50;
	//dolars = 100;
	int numero;
	string valor_pennies, valor_nickels, valor_dimmies, valor_quarters;
	string  valor_half_dolars, valor_dolars;
	cout << "Dóna'm el número de les monedes que tens de cada valor\n i et diré el valor de totes les monedes que tens,\n per exemple, si tens:\n 23 pennies\n 17 nickels\n 14 dimmies\n 7 quarters\n 3 half dollars\nEl valor de totes les teves monedes és de 573 centims.\n";
	int pennies, nickels, dimmies, quarters, half_dolars, dolars;
	cout << "Entra els monedes que tens seguint l'exemple anterior :\n";
	cin >> pennies >> valor_pennies;
	cin >> nickels >> valor_nickels;
	cin >> dimmies >> valor_dimmies;
	cin >> quarters >> valor_quarters;
	cin >> half_dolars >> valor_half_dolars;
	cin >> dolars >> valor_dolars;
	if(pennies > 1) cout << "\nTens " << pennies << valor_pennies << ", ";
	else {
		valor_pennies=pennies;
		cout << "\nTens 1 pennie ," ; 
	}
	if(nickels > 1) cout << "\ntens " << nickels << valor_nickels << ", ";
	else {
		cout << "\ntens 1 nickel ,";
	}
	if(dimmies > 1)cout << "\ntens " << dimmies << valor_dimmies << ", ";
	else {
		cout << "\ntens 1 dimmie ,";
	}	
	if(quarters > 1 )cout << "\ntens " << quarters << valor_quarters << ",";
	else {
		cout << "\ntens 1 quarter ,";
	}
	if(half_dolars > 1) cout << "\ntens " << half_dolars << valor_half_dolars << ", ";
	else {
		cout << "\ntens 1 quarter ," ;
	}
	if(dolars > 1)cout << "\ntens " << dolars << valor_dolars << "." ; 	
	else {
		cout << "\ntens 1 dolar\n";
	}
	numero = pennies + (nickels*5) + (dimmies *10) + (quarters *25) + (half_dolars*50) + (dolars*100);
	cout << "\nEl valor de tots els teus diners són " << numero << " centims \n" ;
	cout << "\npagina 97\n";
	return (0);
}
