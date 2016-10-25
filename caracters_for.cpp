#include<iostream>
#include<cstring>
using namespace std;
int main()
{
//char caracter='a';
cout << "\n for de '0' a 'z'\n";
int caracter;
//while(caracter<='z')
for (caracter=48; caracter <=122; caracter++)
{
//cout <<"Entro ?" << caracter;
cout << char(caracter) << "\t" << int(caracter) << "\n";
//caracter++;
}
cout << "Pàgina 114 4.4.2.2 Blocks" << "\n";
return (0);
}
