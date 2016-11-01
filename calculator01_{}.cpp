

//
// This is example code from Chapter 7.2 "Input and output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>

#include<std_lib_facilities.h>

using namespace std;

#define debug 0
//------------------------------------------------------------------------------

/*error: no matching function for call to ‘Variable::Variable(std::string&, double&)’*/
class Variable{
public:
	string name;
	double value;
	
	Variable(string nm, double val)
		:name(nm), value(val){ }

};

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token(char ch) : kind{ch} { }
   /* Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }*/
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)
	:kind(ch), name(n){ }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
//    void clean_up_mess();
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

const char number ='8';
const char quit = 'q';
const char print = ';';
const string prompt = "|=>";
const string result = "="; //used to indicate that what follows is a result
vector<Variable> var_table;




Token_stream ts;        // provides get() and putback()
  


// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}





void Token_stream::ignore(char c)
  //c representa el tipus de Token
  {
          //primera mirada al buffer?:
          if(full && c==buffer.kind){
                  full=false;
                  return;
          }
          full=false;
          //ara busca introduccions
          char ch=0;
          while(cin>>ch)
                  if(ch==c) return;
  }



void clean_up_mess()
{
//	cout << "\nclean_up_mess?\n";
	ts.ignore(print); //pagina 216-217 del llibre, just al cambiar de pàgina
}



//------------------------------------------------------------------------------

double get_value(string s)// return the Value of a variable named s
{
      for(const Variable& v: var_table)
                if(v.name == s) return v.value;
        error("get: undefined variable");//, s);

}

void set_value(string s, double d)
// set the Variable named s to d
{
for (Variable& v : var_table)
	if (v.name == s) {
		v.value = d;
		return;
}
error("set: undefined variable ");//, s);
}

bool is_declared(string var)
  // is var already in var_table ?
  {
	for (const Variable& v : var_table)
        	if (v.name == var) return true;

        return false;
  }
double define_name(string var, double val)
  // add (var,val) to var_table
  {
	if (is_declared(var)) error(var," declared twice");
        var_table.push_back(Variable(var,val)); //falta el setter ... pagina 218

        return val;
  }

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

const char name = 'a';
const char let = 'L';
const string declkey = "let";
// name token
// declaration token
// declaration keyword

Token Token_stream::get()
//lectura de dades des del teclat i composició del Token
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
		case '=': 
		case ';':    // for "print"
		case 'x':
		case 'q':    // for "quit"
		case '%':
		case '!': 
		case '{': 
		case '}': 
		case '(': 
		case ')': 
		case '+': 
		case '-': 
		case '*': 
		case '/':
	        	return Token(ch);        // let each character represent itself
	    case '.':
	    case '0': case '1': case '2': case '3': case '4':
	    case '5': case '6': case '7': case '8': case '9':
	        {
	            cin.putback(ch);         // put digit back into the input stream
	            double val;
	            cin >> val;              // read a floating-point number
	            return Token(number,val);   // let '8' represent "a number"
	        }
 	   default:
		if(isalpha(ch)){
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;

			cin.putback(ch);
			/*
			string s;
			cin >> s;
			*/
			if(s == declkey) return Token(let); //declaration keyboard
			return Token{name,s};
		}
	        error("Bad token");
	
    }
}

//------------------------------------------------------------------------------

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
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
	return - primary();
    case '+':case '=':
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


/*
// run-time checked narrowing cast (type conversion). See ???.
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r)!=a) error(string("info loss"));
	return r;
}
*/


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

/*	
		double d = primary();
		if(d==0) error("divide by zero");
		left = fmod(left,d);
*/

		//pagina 209 del llibre pdf, mirar narrow_cast
		int i1 = narrow_cast<int>(left); //no incloc narrow_cast, mirar-ho bé ... com fer-ho
		int i2 = narrow_cast<int>(primary());
		if(i2==0) error("% : divide by zero");
		left = i1 % i2;

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

double define_name(string var, double val);

double declaration()
// assume we have seen "let”
// handle : name = expression
// declare a variable called "name ” with the initial value "expression”
{
Token t = ts.get();
if (t.kind != name) error ("name expected in declaration");
string var_name = t.name;


Token t2 = ts.get();
if (t2.kind != '=') error("= missing in declaration of ", var_name);

double d = expression();
define_name(var_name,d);
return d;
}


double statement()
  {
  Token t = ts.get();
          switch (t.kind) {
                case let:
                        return declaration();
                  default:
			ts.putback(t);
                        return expression();
          }
  }



void calculate()
{
//double val=0;
//try{
	while (cin) 
		try{
       		cout << prompt;;          // print prompt
	        Token t = ts.get();
       		while(t.kind== print) t= ts.get();
	        if(t.kind == quit){
	               // return(0);
	               // break;
			return;
	        }
//		if(t.kind == quit) break;
	        //while(t.kind==';') t= ts.get(); //eat //if (t.kind == 'x') break; // 'q' per sortir
	        /*
		if(t.kind == print) // escriure ara
	            cout << result << val << '\n'; // print result
		*/
	        //else
       		ts.putback(t);
	        //val = expression();
        	cout << result << statement() << endl;//expression() << "\n";
	}
//}
catch(/*runtime_error*/exception& e){
	cerr << e.what()<< endl;
	clean_up_mess();
	}
}

double get_Value(string s)
    //returna el valor de la variable s
    {
        for(const Variable& v : var_table)
                    if(v.name==s)return v.value;
        error("get: undefined variable ",s);
    }
  void set_Value(string s, double d)
  //carrega a la variable s el valor d
  {
for(Variable& v : var_table)
          if(v.name==s){ 
                  v.value=d;
                  return;
		}
  error("set : undefined variable " , s);
  
}

//------------------------------------------------------------------------------

int main()
try
{
   define_name("pi", 3.1415926535);
   define_name("e", 2.7182818284);
    cout << "\npàgina 217 del llibre, TEMA 7.8.1\n We can now read and write “variables” represented as Variables in var_table." << endl;
    calculate();	
    /*while (cin) {
        cout << prompt;;          // print prompt
        Token t = ts.get();
	while(t.kind== print) t= ts.get();
	if(t.kind == quit){
		return(0);
		//break;
	}
        if(t.kind == quit) break;
	//while(t.kind==';') t= ts.get(); //eat //if (t.kind == 'x') break; // 'q' per sortir
        if(t.kind == print) // escriure ara
            cout << "= " << val << '\n'; // print result
 .       //else
        ts.putback(t);
        //val = expression();
	cout << result << expression() << "\n";
    }*/
	keep_window_open();
	return 0;
}
catch (/*runtime_error*/exception& e){//(exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
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
