#include<iostream>
using namespace std;
int main()
{
int v1, v2, v3;
int primer, segon, tercer, aux;
cout<<"Entra un valor";
cin>>v1;
cout<<"\nEntra el segon valor ";
cin>>v2;
cout<<"\nEntra el tercer valor ";
cin>>v3;
if (v1 <= v2) {
		aux = v1;
		v1 = v2;
		v2= aux;

}

cout << "\n3 primer = " << primer << " segon = " << segon << " tercer = " << tercer << ".\n";

return (0);
}	
