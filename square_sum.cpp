#include<iostream>
#include<cmath>
//#include<ctype.h>
using namespace std;
int square (int nombre)
{
/*	int contador;
	cout << "\n nombre dins square = " << nombre;
	for(contador =0; contador<=nombre; ++contador) {
//		contador=contador+ contador*nombre;
		cout << "contador =" << contador << " nombre = " << nombre;
	}
	cout << "\nnombre és " << nombre;
	cout << "\ncontador és " << contador;
*/
	int m = nombre;//base;
	int n = nombre;//potencia;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "\ni= " << i << "n= " << n << "result = " << result;
		    if (i == 0)
		        result = n;
		    else
		        result = result+n;
	}
	return (result);
}
int main()
{
	//string::size_type sz;
	int nombres =0 ;
	cout << "\nElevo al quadrat el nombre donat \n";
	cin >> nombres;
	cout << "\n El nombre entrar és " << nombres << "\n";
	cout << "\n i el quadrat és " << square(nombres) << "\n";
/*	while (nombres <= 100)
	{
		cout << "\nQuadrat de " << nombres << " és "  << square(nombres);
		++nombres;
	}
	//for (nombres = 0; nombres<=100; ++nombres) cout << "\nQuadrat de " << nombres << " és " << square(nombres); */
	
	return (0);
}
