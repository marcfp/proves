//#include "std_lib_facilities.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() { char ch; cin>>ch; }
int main()
{
	cout << "SENSE TOKENS!!\n";
	cout << "Please enter expression (we can handle +, –, *, and /)\n";
	cout << "add an x to end expression (e.g., 1+2*3x): ";
	int lval = 0;
	int rval;
	cin>>lval;
	// re ad le ftmost ope rand
	if (!cin) cout << "no first operand";
	for (char op; cin>>op; ) {
		// re ad ope rator and right-hand ope rand
		// re pe ate dly
		if (op!='x') cin>>rval;
		if (!cin) cout << "no second operand";
		switch(op) {
			case '+':
					lval += rval;
					// add: lval = lval + rval
				break;
			case '-':
					lval -= rval;
					// subtract: lval = lval – rval
				break;
			case '*':
					lval *= rval;
					// multiply: lval = lval * rval
				break;
			case '/':
					lval /= rval;
					// divide : lval = lval / rval
				break;
			default:
				// not anothe r ope rator: print re sult
				cout << "Result: " << lval << '\n';
				//keep_window_open();
			return (0);
		}
	}
cout << "bad expression";
}
