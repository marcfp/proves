#include<iostream>
using namespace std;
int main()
{

	char a, b;
	double valor1;
        double valor2;
	double petit;
	double gran;
	cout << "\n Estic al punt 3 de la pàgina 126 \n";

	cout << "\n Entra 2 números enters, per sortir escriu '|' \n ";
	while(valor1!=124 && valor2!=124  )
	{
		cin >> a >> b;
		valor1 = a;
		petit=valor1;
		valor2 = b;
		gran=valor2;	
		cout << "\nEnter valor1 = " << valor1 << "\nEnter valor2= " << valor2 << "\nchar a = " << a << "\nchar b = " << b << "\n";
		/*if(valor1<=valor2) cout << "\nEl valor més petit o igual és valor1 amb aquest valor = " << a ;
		else cout << "\nEl valor mé petit és el valor 2 amb aquest valor = " << b;
		*/
		
		if(valor1==valor2){
			 if(valor1<petit) petit=valor1;
			 if(valor1>gran)gran=valor1;
			 cout << "\n els 2 valors són iguals \n" << "gran = " << gran << "petit = " << petit << endl;
		}
		else if(valor1<=valor2){
			if(valor1<petit) petit=valor1;
                        if(valor1>gran) gran=valor1;
                        if(valor2<petit) petit=valor2;
                        if(valor2>gran) gran=valor2;
			cout << "\nEl valor més petit o igual és valor1 amb aquest valor = " << a  << " i el més gran és " << b << "gran = " << gran << " petit = " << petit <<endl;
			}
                else{
			if(valor1<petit) petit=valor1;
                        if(valor1>gran) gran=valor1;
                        if(valor2<petit) petit=valor2;
                        if(valor2>gran) gran=valor2;
			cout << "\nEl valor més petit és el valor 2 amb aquest valor = " << b << "gran = " << gran << " petit = " << petit <<endl;
		}
	double val=1.0/100;
	if(a/b<val) cout << endl << "els números són molt iguals" << endl;
	
	}
//cout << "\n Estic al punt 3 de la pàgina 126 \n";
return(0);
}
