#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch ; }

int main()
{

	char a, b;
	double valor1;
        double valor2;
	cout << "\n Estic al punt 3 de la pàgina 126 \n";

	cout << "\n Entra 2 números enters, per sortir escriu '|' \n ";
	while(valor1!=124 && valor2!=124  )
	{
		cin >> a >> b;
		valor1 = a;
		valor2 = b;	
		cout << "\nEnter valor1 = " << valor1 << "\nEnter valor2= " << valor2 << "\nchar a = " << a << "\nchar b = " << b << "\n";
		/*if(valor1<=valor2) cout << "\nEl valor més petit o igual és valor1 amb aquest valor = " << a ;
		else cout << "\nEl valor mé petit és el valor 2 amb aquest valor = " << b;
		*/
		if(valor1==valor2) cout << "\n els 2 valors són iguals \n";
		else if(valor1<=valor2) cout << "\nEl valor més petit o igual és valor1 amb aquest valor = " << a ;
                else cout << "\nEl valor mé petit és el valor 2 amb aquest valor = " << b;}

//cout << "\n Estic al punt 3 de la pàgina 126 \n";
return(0);
}
