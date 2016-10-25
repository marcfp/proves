#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <locale> 
using namespace std;
class Token {
	//a very simple user-defined type
	public:
		char kind;
		double value;
};

//vector<Token> tok;

Token get_token();

vector<Token> tok;
int main()
{
	//vector<Token> tok;
	//token = new Token()
	while(cin){
		Token t = get_token();
		tok.push_back(t);
	}
	return(0);
}

Token get_token(){

	cout << "Please enter expression (we can handle +, –, *, and /)\n";
	cout << "add an x to end expression (e.g., 1+2*3x): ";
	int lval = 0;
	int rval=0;
	cin >> lval;
	// read leftmost operand
	if (!cin) cout << "no first operand";
	for (char op; cin>>op; ) {
		// read operator and right-hand operand
		// repeatedly
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
			case !'x':
				cin >> rval;
			default:
				// not another operator: print result
				cout << "Result: " << lval << '\n';
				//keep_window_open();
				//return 0;
		}
	}
	cout <<"bad expression";
}
