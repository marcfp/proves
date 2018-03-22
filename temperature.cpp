/*#include <iostream>
#include <fstream>
#include <vector>
*/
#include "./std_lib_facilities.h"

using namespace std;
struct Reading {
	int hour;
	double temperature;
};

// a temperature reading
// hour after midnight [0:23]
// in Fahrenheit
int main()
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist {iname};
// ist re ads from the file name d iname
	if (!ist) cout << "can't open input file " << iname ;
	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost {oname};
// ost writes to a file named oname
	if (!ost) cout << "can't open output file " << oname;
	vector<Reading> temps;
// store the readings he reint hour;
	int hour;
	double temperature;
	int j=0;
	while (ist >> hour >> temperature) {
		if (hour < 0 || 23 <hour) error("hour out of range");
			temps.push_back(Reading{hour,temperature});
			cout << '(' << temps[j].hour << ','<< temps[j].temperature << ")\n";
			j++;
	}

	for (int i=0; i<temps.size(); ++i){ 
				 ost << '(' << temps[i].hour << ','<< temps[i].temperature << ")\n";
				 //cout << '(' << temps[i].hour << ','<< temps[i].temperature << ")\n";
	}

	ist.close();
	ost.close();
}
