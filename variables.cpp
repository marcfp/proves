#include <iostream>
using namespace std;

int main()
{

int valor;
int *punter=&valor;
cout << "Entra un valor :";
cin >> valor ;
cout << "\nValor = " << valor << " &valor = " << &valor << " *punter = " << *punter << "\n";
 
return (0);
}
