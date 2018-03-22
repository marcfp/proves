#include <iostream>
#include <fstream> 

using namespace std;
int main()
{
//	string iname;
	string oname;
/*	cout << endl << "Please enter input file name : " << endl ;
	cin >> iname;
	ifstream ist{iname};
	if(!ist) cout << "Error, no es pot obrir el fitxer " << iname << endl;
	else {
		cout << "Fitxer obert!!! " << endl;
		ist.close();
		cout << endl << "Fitxer tancat i surtint del programa" << endl;
	}
*/
	cout << endl << "Please enter name of output file : " << endl;
	cin >> oname;
	ofstream ost {oname};
	if(!ost) cout << "can't open outputfile " << oname << endl;
	else {
		cout << "Fitxer de sortida obert! " << endl;

		ost.close();
		cout << endl << "Fitxer de sortida tancat" << endl;
	}
return(0);
}
