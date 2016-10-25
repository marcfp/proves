//
// This is example code from Chapter 7.2 "Input and output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//#include "../std_lib_facilities.h"
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

#define debug 0
//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}


void error(string s1){
throw runtime_error(s1);
//cout << "\n error string s = " << s<< "\n";
}
//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) { 
		error("putback() into a full buffer\nNO HI HA RES AL BUFFER??\n");
			//return (-3);
		}
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
	    case '=': case ';':    // for "print"
	    case 'x':    // for "quit"
	    case '%': case '!': case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/':
	        return Token(ch);        // let each character represent itself
	    case '.':
	    case '0': case '1': case '2': case '3': case '4':
	    case '5': case '6': case '7': case '8': case '9':
	        {
	            cin.putback(ch);         // put digit back into the input stream
	            double val;
	            cin >> val;              // read a floating-point number
	            return Token('8',val);   // let '8' represent "a number"
	        }
 	   default:
	        error("Bad token");
	
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '{':
	{
            double d = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return d;
        }
    case'(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
	return - primary();
    case '+':
	return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------
int factorial(int left)
{
	if(debug)cout  << " dins de factorial ?\n" ;
if (left!=1 && left!=0){
		/*cout << "\nfactorial  de 1 ";
		left=1;
		return(1);*/
		if(debug) cout << "\n factorial de  " << left << " * factorial(" << left-1 << ") = " << left*factorial(left-1) ;
                return( left* factorial(left-1));


	}
	else {
		if(debug) {
			cout << "left = " << left << "\n";
			if(left==0) return(1);
		}
		if(debug) cout << "\nfactorial  de 1 ";
                return(1);
		}

}
// deal with *, /, and %
double term()
{
    double left = primary();
    double valor;
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
	case '!':
	    if(debug)cout << "\nfactorial ?\n left = " << factorial((int)left) << "\n";
	    valor=left;
	    left=factorial(left);
	    cout << "El factorial de " << (int)valor << " és " << (int)left << "\nIntro > ";
	    t = ts.get(); 
 	    break;
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
	case '%':
	{

		double d = primary();
		if(d==0) error("divide by zero");
		left = fmod(left,d);

/*
		//pagina 209 del llibre pdf, mirar narrow_cast
		int i1 = narrow_cast<int>(left); //no incloc narrow_cast, mirar-ho bé ... com fer-ho
		int i2 = narrow_Cast<int>(primary());
		if(i2==0) error("% : divide by zero");
		left = i1 % i2;*/
		t = ts.get();
		break;
	}
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    double val = 0;
    cout << "\npàgina 208 del llibre, TEMA 7\n narrow_cast(com l\'incloc?)\n";
    while (cin) {
        cout << "|=> ";          // print prompt
        Token t = ts.get();
	if(t.kind == 'q'){
		//return(0);
		break;
	}
        if(t.kind == 'x') break;
	//while(t.kind==';') t= ts.get(); //eat //if (t.kind == 'x') break; // 'q' per sortir
        if(t.kind == ';') // escriure ara
            cout << "= " << val << '\n'; // print result
        else
            ts.putback(t);
        val = expression();
    }
}
catch (runtime_error& e){//(exception& e) {
    cerr << "error: " << e.what() << '\n';
    //keep_window_open():
    cout << "Please enter the character ~ to close the window " << endl;
    for(char ch; cin >> ch;)
	if(ch=='~') return (1);
    return (1);
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}

/*	while(cin){
		cout << "> ";
		Token t = ts.get();
		while(t.kind ==';') t=ts.get(); 	//eat
		if(t.kind == 'q') {
			//keep_window_open();
			for(char ch; cin >> ch;)
			        if(ch=='~') return (1);
			return(0);
		}
		ts.putback(t);
		cout << "= " << expression() << '\n';
	}
	//keep_window_open();
	for(char ch; cin >> ch;)
	        if(ch=='~') return (1);
	return(0);
	
}
catch(exception& e){
	cerr << e.what() << '\n';
//	keep_window_open("~~");
	for(char ch; cin >> ch;)
	        if(ch=='~') return (1);
	return (1);
}
catch(...){
	cerr << "exception \n";
//	keep_window_open("~~");
	for(char ch; cin >> ch;)
	        if(ch=='~') return (1);
	return(2);
}*/
//------------------------------------------------------------------------------
