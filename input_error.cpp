#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	int i = 0;
	cin >> i;
	if (!cin) {
		// we get here (only) if an input operation failed
		if (cin.bad()) {
			cout << "cin is bad" << endl; // stream corrupted: let’s get out of here !
			return(0);
		}
		if (cin.eof()) {
			cout << "no more input" << endl;
			// no more input
			// this is often how we want a sequence of input operations to end

		}
		if (cin.fail()) {
			cout << "cin failed" << endl;
			// stream encountered some thing unexpected
			cin.clear();
			// make ready for more input
			// some how recover
		}
	}
	else {
		cout << "Entrada correcte" << endl;
	}
return(0);
}
