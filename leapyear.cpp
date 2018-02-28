#include <iostream>

using namespace std;


bool leap_year(int any){

//cout << "any%4=" << any%4 <<  " any%400=" << any%400 << " any%100=" << any%100 << endl;
if (any%4==0 && (any%400==0 || any%100!=0)){
//		 cout << "és any de traspas" << endl;
		return(1);
	}
	else{
//		 cout << "NO ÉS ANY TRASPAS" << endl;
		return(0);
	}
}

int main(){

	int any;
	cout << endl << "Entra un any i et diré si és de traspás o no"<< endl ;
	cin >> any;
	if(leap_year(any)){
		 cout << endl << "és any de traspás" << endl;
	}
	else{
		 cout << endl << "no és any de traspás" << endl;
	}

return(0);
}
