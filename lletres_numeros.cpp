//#include<iostream>
#include <stdio.h>
//#include<ctype.h>
using namespace std;
int main()
{
	//string::size_type sz;
	int numero =0 ;
	char lletra ='a';
	printf( "\n Escric la lletra i el seu valor enter al costat ");
	//for (numero =97; numero <=122; ++numero)
	for (lletra='a';lletra <='z';++lletra)
	{
		//pagina 114 try
//	        char caracter = numero + 'a';
		numero = lletra - '0';
		//cout << "lletra " << caracter << " equival al enter "<< numero ;
		printf (" lletra %c equival al enter %d \n ", numero, lletra);/*caracter, numero);*/
	}
	
	return (0);
}
