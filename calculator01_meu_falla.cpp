
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

//#include "../std_lib_facilities.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


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

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
if (full) cout << "putback() into a full buffer";
buffer = t;       // copy t to buffer
full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
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
       cout << /* error(*/"Bad token";//);
    }
}

//------------------------------------------------------------------------------

Token_stream ts;

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();primary();//get_token();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();primary();//get_token();
            if (t.kind != ')') cout << /*error(*/"')' expected";//);
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
       cout << /* error(*/"primary expected";//);
    }
}
//------------------------------------------------------------------------------

int main()
try {
    while (cin)
        cout << '=' << expression() << '\n';
//    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
 //   keep_window_open ("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
//    keep_window_open ("~2");
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get(); //get_token();     // get the next token from the Tokenstream
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();//get_token();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();//get_token();
            break;
        default:
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();//get_token();     // get the next token

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();//get_token();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0){ cout << /*error(*/"divide by zero";//);
				return (-2);
		}
                left /= d; 
                t = ts.get();//get_token();
                break;
            }
        default: 
	    ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------
