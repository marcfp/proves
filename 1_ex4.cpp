#include<iostream>
using namespace std;
int main()
{
double v1, v2;
cout<<"Entra un valor ";
cin>>v1;
cout<<"\nEntra el segon valor ";
cin>>v2;
cout <<"\nValor 1 = "<< v1 << "\nValor 2 = " << v2 ;
double petit, gran, suma, diferencia1, diferencia2, producte, divisio1, divisio2;
if(v1 <= v2){
		petit = v1;
		gran = v2;
	}
	else{
		petit =v2;
		gran =v1;
		}
suma=v1+v2;
diferencia1 = v1-v2;
diferencia2 = v2-v1;
producte = v1*v2;
divisio1= v1/v2;
divisio2=v2/v1;
cout << "Els resultats de les operacions : \n petit = " << petit << "\n gran = "<< gran << "\n suma = " << suma << "\n diferencia1 = " << diferencia1 << " \n diferencia2 = " << diferencia2 << "\n producte = " << producte << "\n divisio1 = " << divisio1 << "\n divisio2 = " << divisio2;
return (0);
}
