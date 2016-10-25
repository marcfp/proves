#include<iostream>
#include<cmath>
//#include<ctype.h>
using namespace std;
int square (int nombre)
{
	return (nombre*nombre);
}
int main()
{
	//string::size_type sz;
	int nombres =0 ;
	cout << "\nElevo al quadrat els 100 primers nombres naturals \n";
	while (nombres <= 100)
	{
		cout << "\nQuadrat de " << nombres << " és "  << square(nombres);
		++nombres;
	}
	//for (nombres = 0; nombres<=100; ++nombres) cout << "\nQuadrat de " << nombres << " és " << square(nombres); 
	
	return (0);
}
