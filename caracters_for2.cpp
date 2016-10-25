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
if(int(caracter) <= 57 || (int(caracter>=65 && int(caracter<=90))))cout << char(caracter) << "\t" << int(caracter) << "\n";
//caracter++;
}
cout << "Pàgina 116 try" << "\n";
return (0);
}
