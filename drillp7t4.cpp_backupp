#include<iostream>
//#include<stdlib.h>
//#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{

	string a;
	int trobat =1;
//	string b;

	cout << "\n Estic al punt 7 de la pàgina 127 \n";
	cout << "\n Entra 1 número amb les unitats corresponents ( cm, m, in, ft)\n per sortir escriu \"|\"";
	//cin >> a ;
	while(trobat ==1 ){
		getline(cin, a);
		cout << " a = " << a; // << b ; //<< " b = " << b;
		size_t found_cm = a.find("cm");
		size_t found_m = a.find("m");
		size_t found_in = a.find("in");
		size_t found_ft = a.find("ft");
			//size_t found_b = b.find("cm");
		if (found_cm!=string::npos || found_m!=string::npos || found_in!=string::npos || found_ft!=string::npos){
				if(found_cm!=string::npos) cout << "first 'cm' found at a's position: " << found_cm << '\n';
				else if(found_m!=string::npos) cout << "first 'm' found at a's position: " << found_m << '\n'; 
					else if(found_in!=string::npos) cout << "first 'in' found at a's position: " << found_in << '\n';
						else if(found_ft!=string::npos) cout << "first 'ft' found at a's position: " << found_ft << '\n';
				cout << "\nfound_a = " << found_cm << "\n a.length()=" << a.length() << "\n";// << "\n found _b = " << found_b << "\n b.length()= " << b.length() << "\n" ;
				trobat =0;
		}
		else{
			trobat =1;	
		}
	}
return(0);
}

