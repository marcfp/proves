#include<iostream>
#include<math.h>
using namespace std;
int main()
{


	int a=1;

	cout << " Entra'm números i et diré si són senars o parells (0 per acabar) " ;
	while (a!=0){
		cin >> a;
		if (a % 2 == 0 ) cout << "el nombre " << a << " és parell";
		else cout << "El número " << a << " és  senar ";
	}
	return (0);
}
