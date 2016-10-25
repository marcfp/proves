#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main()
{
int unitat, desena, centena, milers;
int numero;
int valor=0;
string val="\0";
ostringstream convert;
int min=0;
int max=4;
cout << "9. Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and 3. The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value. Handle numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character '5' subtract '0', that is, '5'–'0'==5.\n";

do{
	try{
//		convert='0';
		convert.str(string());
		cout << "Entra un número, com a màxim de 4 digits ";
		cin >> numero;
		cout << "Sizeof numero = " << sizeof numero ;
//		itoa (numero,val,10);
//		val=to_string(numero);
		convert << numero;
		val = convert.str();
		cout << "convert= " << convert.str() << "\nval.length = "<< val.length() <<"\n";
		
		if(val.length()<min || val.length()>max){
							cout << "Valor incorrecte!!!!!" << endl << "Enra una valor d'entre 0 i 4 xifres!!" << endl;
							 valor=0;
		}
		else {
			cout << "valor correcte" << endl;
			
			for(int i=1; i<=val.length();++i){ // i=1; --i){
				if(val.length()==4){ 
					 if (i==1) cout <<  val[0]-'0' << " milers ";
					else if(i==2) cout <<  val[1]-'0' << " centenes " ;
					else if(i==3) cout <<  val[2]-'0' << " desenes ";
					else if(i==4) cout <<  val[3]-'0' << " unitats" << endl;
				}
				else if(val.length()==3) {
					if(i==1) cout <<  val[0]-'0' << " centenes " ;
                                        else if(i==2) cout <<  val[1]-'0' << " desenes ";
                                        else if(i==3) cout <<  val[2]-'0' << " unitats" << endl;
				}
				else if(val.length()==2) { 
                                        if(i==1) cout <<  val[0]-'0' << " desenes ";
                                        else if(i==2) cout <<  val[1]-'0' << " unitats" << endl;
				}
				else if(val.length()==1){
					if(i==1) cout <<  val[0]-'0' << " unitats "<< endl ;
				}
			}
			valor=1;
		}
	}
	catch (exception& e ) {
		cout << "error " << e.what() << endl ;
	}
}while (valor==0);

return (0);
}
