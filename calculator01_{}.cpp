
//
// This is example code from Chapter 7.2 "Input and output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
/*
	Statement :
		Declaration
		Expression
		Print
		Quit
	Print :
		;
	Quit:
		q
	Calculation Statement



	Expression :
		Term
		Expression + Term
		Expression - Term
	Term :
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary :
		Number
		( Expression ) 
		- Primary
		+ Primary
	Number :
		Floating-point-literal
-------------------------------------------------------------
-> Input comes from cin through the Token_stream called td <-
-------------------------------------------------------------
*/

#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <string>
#include<std_lib_facilities.h>

using namespace std;

#define debug 1
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
   // Token(char ch) : kind{ch} { }
//    Token() {}
    Token(char ch)    // make a Token from a char
        :kind{ch} {}
    Token(char ch, double val)     // make a Token from a char and a double
        :kind{ch}, value{val} {}
    Token(char ch, string n)
	:kind{ch}, name{n} {}
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
    bool full{false};        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

const char number ='8'; //global!!
const char quit = 'q';
const char print = ';';
const string prompt = "|=>";
const char /*string*/ result = '='; //used to indicate that what follows is a result
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
	ts.ignore(print); //pagina 216-217 del llibre, just al cambiar de pàgina
}



//------------------------------------------------------------------------------

/*inline double convertToDouble(const string& s)
{
  istringstream i(s);
  double x;
  if (!(i >> x))
    error("error de conversio ",s);//throw BadConversion("convertToDouble(\"" + s + "\")");
  return x;
}*/
double arrelquadrada(string s)
{
	
//	double prova=stod(s);
	cout  << " arrelquadrada string s = " << s << endl;
	cout <<  " s.length() = " << s.length() /* s.length()*/ << endl;
//	cout << "stod(s) = " << stod(s)	 << endl;
/*	int /*double*//* prova =atoi(s.c_str());//.c_str());
		
//	cout << " sqrt(prova) = " << sqrt(prova) << endl;
	cout << "s = " << s << " prova = " << prova << endl;

	return(prova);
	//sqrt(prova));	
//	return(sqrt(prova));
*/
//	cout << " s=" << s.c_str() << endl;
//	cout << "s1=" << s << endl;
//	cout << "prova = " << prova << endl;
//	return (prova);
	return (0);
}
double get_value(string s)// return the Value of a variable named s
{
      for(const Variable& v: var_table)
                if(v.name == s) return v.value;
        error("get: undefined variable ",s);//, s);

}

void set_value(string s, double d)
// set the Variable named s to d
{
for (Variable& v : var_table)
	if (v.name == s) {
//		cout << "Estic dins del setter Variable" << endl;
		v.value = d;
		return;
}
error("set: undefined variable ",s);//, s);
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
const string decllet = "let";

const char arrel = 'r';
const string declsqrt = "sqrt";


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
//    cout << " ch=" << ch << endl;
    switch (ch) {
		case quit:
		case print:    // for "print"
		case result: 
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
//		    cout << "ch = " << ch << endl;
	            cin.putback(ch);         // put digit back into the input stream
	            double val;
	            cin >> val;              // read a floating-point number
//		    cout << "val = " << val << endl << " number = " << number << endl;
	            return Token(number,val);   // let '8' represent "a number"
	        }
 	   default:
		if(isalpha(ch)){ //si es let, val l, entro aquí.
			string s;
//			cout << "s(abans) = " <<  s << endl;
			s += ch;
//			cout << "s(després) = " << s << endl;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))){
					 s+=ch;
//					if(debug==1)cout << endl << " ch = " << ch << endl << " s = " << s << endl << "declkey = " << declkey << endl << " s = " << s << endl;
//					cout << "s = " << s << endl;
			}
			cin.putback(ch);
			//cout << "ch = " << ch;
			if(s==decllet){
					//if(debug==1) cout << endl << "surto token{let}" << endl<< " let = " << let << endl << " ch =" << ch << endl << " s = " << s << endl << "declkey=" << declkey << endl;
					 return Token{let};
			}
			if(s==declsqrt){
//					if(debug==1) cout << "introduida sqrt ? Arrel  s = " << s << endl;//faig arrel
					cout << "faig arrel ?" << endl;
					return Token{arrel};
			}

			//if(debug==1)cout << endl << "let = " << let << "surto token{name,s}" << " name = " << name << " s = " << s << endl << " ch ='" << ch << "'" << endl << "name = '" << name << "'" << endl << " s ='" << s << "'" << endl << " let ='" << let << "'" << endl << " number = '" << number << "'" << endl;
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
    case number:             // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':
	return - primary();
    case '+':case '=':
	return primary();
    case 'r':
	cout << "r i arrelquadrada(t.name) =" << arrelquadrada(t.name) << endl;
	return(0);
    case 'a': //si 'a', recull valor!!!!
//	cout << "get_value(t.kind) = " << get_value(t.name) << endl;
	return get_value(t.name);
    default:
//	if(debug==1)cout << "t.value = " << t.value << endl << "t.kind =" << t.kind << endl;
        error("primary expected");
    }
}

//------------------------------------------------------------------------------
int factorial(int left)
{
//	if(debug)cout  << " dins de factorial ?\n" ;
if (left!=1 && left!=0){
		/*cout << "\nfactorial  de 1 ";
		left=1;
		return(1);*/
//		if(debug) cout << "\n factorial de  " << left << " * factorial(" << left-1 << ") = " << left*factorial(left-1) ;
                return( left* factorial(left-1));


	}
	else {
		//if(debug) cout << "left = " << left << "\n";
		if(left==0) return(1);
		//if(debug) cout << "\nfactorial  de 1 " << endl;
                return(1);
		}

}


double sqrt( double val){ //arrel
	if(val >1){
		return (sqrt(val));
	}
	else{
		cout << "\n Error!!!!!!!!!!!!! valor no vàlid" << endl;
//		cout << "\n val = " << val << "\n sqrt(val) = " << sqrt(val) << endl;
	}

return(1);
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
//	    if(debug)cout << "\nfactorial ?\n left = " << factorial((int)left) << "\n";
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
		//pagina 209 del llibre pdf, mirar narrow_cast
		//int i1 = narrow_cast<int>(left); //no incloc narrow_cast, mirar-ho bé ... com fer-ho
		//int i2 = narrow_cast<int>(primary());
		try{
		//	int i1 = narrow_cast<int>(left);
		//	int i2 = narrow_cast<int>(primary());
			double d = primary();
			if(d==0) error("divide by zero");
//			if(i2==0) error("% : divide by zero");
			left = fmod(left,d);//i1 % i2;
			t = ts.get();
			break;
		}
		catch (exception& e){
			cout << "Aquí hi ha un error ? pot ser ? e.what = " << e.what() << endl;
		}
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
            left -= term();    // evaluate Term and subtract or change sign
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
//cout << "DEBUGt.kind = " << t.kind << endl << " name =" << name << endl; //kind value i name
///cout << "t.kind = " << t.kind << endl << "t.value = " << t.value << endl << "t.name = " << t.name << endl;
if (t.kind != name) error ("name expected in declaration");
string var_name = t.name;


Token t2 = ts.get();
if (t2.kind != '=') error("= missing in declaration of ", var_name);
//cout << "si?" << endl;
double d = expression();
//cout << " d= " << d << endl;
define_name(var_name,d);
cout << "var_name = " << var_name << "\n d =" << d << endl;
//set_value(var_name,d);
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

	while (cin) 
		try{
	       		cout << prompt;          // print prompt
	        	Token t = ts.get();
       			while(t.kind == print) t = ts.get();
		        if(t.kind == quit){
//				keep_window_open();
//				return (0);
				return;
	        	}
			ts.putback(t);
   		     	cout << result << statement() << endl; //expression() << endl;
		}
		catch(exception& e){ //si hi ha error d'introducció, surt aquí ...
//			cout << endl << "surto aqui, oi, pel let ??" << endl ;
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

//------------------------------------------------------------------------------

int main()
try
{
	//predefined names :
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k", 1000);
	cout << "\npàgina 251 del llibre, TEMA 7, punt DRILL" << endl;
	calculate();
	keep_window_open();
	  return 0;
}
catch (exception& e){
    cerr << "error: " << e.what() << endl;
    keep_window_open("~~");
    return (1);
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open("~~");
    return (2);
}

//------------------------------------------------------------------------------
