//
// This is example code from Chapter 7.2 "Input and output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
/*
	Statement :
		Declaration
		Expression
		Print
		pow
		let -> # -> declara 
		Quit
		surt
	Print :
		;
	Quit:
		quit
		surt
		exit
	Calculation Statement
	Expression :pow(
		Term
		Expression + Term
		Expression - Term
	Term :
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
		Term ! Primary
		
		
	Primary :
		Number
		( Expression ) 
		- Primary
		+ Primary
		sqrt Primary
		pow(base, exponent)
		help
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
#include <sstream>
#include<std_lib_facilities.h>

using namespace std;

#define debug 1
//------------------------------------------------------------------------------
//class Variable;

class Symbol_Table{
  
public:
  string constant;
  string name;
  double value;
  double val;
  
  double get_value(string s);
  void set_value(string s, double d);
  bool is_declared(string var);
  double define_name(string var, double val);
  double define_name_const(string var, double val);
  
  
  /*Variable*/
  Symbol_Table(string nm, double val)
		:name(nm), value(val){ }
  /*Variable*/
  Symbol_Table(string constat1, string nm, double val)
		:constant(constat1), name(nm), value(val){ }
	    
};

/*#####################Cambiat per Symbol_Table########################*/
/*class Variable
{
public:
	string constant;
	string name;
	double value;
	
	Variable(string nm, double val)
		:name(nm), value(val){ }
	Variable(string constat1, string nm, double val)
		:constant(constat1), name(nm), value(val){ }
};
*/
class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
   
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
//    void putback2(Token t, Token t2);
//    void clean_up_mess();
private:
    bool full{false};        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

const char number ='8'; //global!! //8 <- és número
const char quit = 'e';
const char print = ';';
const string prompt = "|=>";
const char  result = '='; //used to indicate that what follows is a result
//vector<Variable> var_table; //cambiat per Symbol_Table
vector<Symbol_Table> var_table;


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
          while(cin>>ch){
		  //cout << " c=" <<  endl;
                  if(ch==c) return;
	  }
  }



void clean_up_mess()
{
	ts.ignore(print); //pagina 216-217 del llibre, just al cambiar de pàgina
}



//------------------------------------------------------------------------------

double get_value(string s)// return the Value of a variable named s
{
      if(debug==1)cout << "s = " << s<< endl;
      for(const /*Variable*/ Symbol_Table& v: var_table)
                if(v.name == s) return v.value;
        error("get: undefined variable ",s);//, s);

}

void set_value(string s, double d)
// set the Variable named s to d
{
for (/*Variable*/Symbol_Table& v : var_table)
	if (v.name == s) {
		if(debug==1)cout << "Estic dins del setter Variable 2" << endl;
		v.value = d;
		return;
}
error("set: undefined variable ",s);//, s);
} 	

void set_value(string c, string s, double d)
// set the Variable named s to d
{
for (/*Variable*/Symbol_Table& v : var_table)
	if (v.name == s) {
		if(debug==1)cout << "Estic dins del setter Variable 3" << endl;
		v.value = d;
		return;
}
error("set: undefined variable ",s);//, s);
} 	


bool is_declared(string var)
  // is var already in var_table ?
  {
	for (const /*Variable*/Symbol_Table& v : var_table)
        	if (v.name == var) return true;
        return false;
  }

double define_name(string var, double val)
  // add (var,val) to var_table
  {
	if (is_declared(var)){
			      //error(var," declared twice");
	  		      char c='1';
			      do{
				cout << "Var name already exists, do you want overwrite value ?(s,S,n,N)" ;
				cin >> c;
			      }while(c!='s' && c!='n' && c!='S' && c!='N');
			      if(c!='s' && c!='S'){
					  error(var," declared twice");
			      }
			      else{
					  var_table.push_back(/*Variable*/Symbol_Table(var,val)); //falta el setter ... pagina 218
			    }	
	}
	else{
	      var_table.push_back(/*Variable*/Symbol_Table(var,val));
	}
        return val;
  }

double define_name_const(string var, double val)
  // add (var,val) to var_table
  {
	if (is_declared(var)){
		error(var," declared twice");
	    }
	else{
		var_table.push_back(/*Variable*/Symbol_Table(var,val)); //falta el setter ... pagina 218
	}
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
const char let = '#';
const string decllet = "#";

const char arrel = 'r';	
const string declsqrt = "sqrt";

const char pows = 'p';
const string declpow = "pow";

const char surt='s';
const string declsurt="surt";
const char quit1='q';
const string declquit="quit";
const char exit1='e';
const string declexit="exit";
const char constat='c';
const string declconstat1="declara";


const char espaip=' ';
const string espaipitjat=" ";

const char ajudap='h';
const string declajuda="help";
// name token
// declaration token
// declaration keyword

Token Token_stream::get() //buscar espais i retorns de carro '\n' amb la llibreria isspace(ch) -> cert si espai
//lectura de dades des del teclat i composició del Token
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    //cin >> ch;    // note that >> skips whitespace (spsmace, newline, tab, etc.)
    cin.get(ch); //recull el PRIMER valor llegit
    while(isspace(ch)){ //mentre sigui espai ....
		if(ch == '\n') //si el caracter és intro, retorna resultat
			return Token{print};
		else 
			cin.get(ch); //si no es intro, recull valor llegit.
    }
//    cout << " ch=" << ch << endl;
    switch (ch) {      
	return (ch);
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
		case ',':
		case '#':
		//case '_':
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
	    //case espaip:
	    //  cout << "recullo espai pitjat" << endl;
	      
 	   default:
		if(isalpha(ch)){ //si es let, val l, entro aquí.
			string s;
			//if(debug==1)cout << "s(abans) = " <<  s << endl;
			//ch='(' quan faig pow 
			/*if(ch=='(') {
			    //cin.putback(ch);
			    cout << endl << "(ch =='(')=1!!! " << endl;
			}*/
			cout << endl << "ch = " << ch << endl << "al calcular potencia, es llegeix un ( de més ... mirar per a què passa això, en sqrt no passa, per exemple ... pk ?" ;
			s += ch;
			//if(debug==1)cout << "s(després) = " << s << endl;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')){ // comparar aquí si ch == _ (underscore), no ?
					 s+=ch;
/*					if(debug==1){
						cout << endl << "carrega" << endl; 						cout << endl << " ch = " << ch << endl << " s = " << s << endl << "decllet = " << decllet << endl << " s = " << s << endl; 						cout << "s = " << s << endl;
						}
*/
			}
			cin.putback(ch);
			//cout << "ch = " << ch;
			if(s==declajuda){
			    if(debug==1) cout << "AJUDA!!!!"<< endl;
			    return Token{ajudap};
			}
			if(s==declsurt){
			      if(debug==1)cout << "SURT?" << endl;
			      return Token{surt};
			}			
			if(s==declquit){
			      if(debug==1)cout << "QUIT?" << endl;
			      return Token{quit1};
			}
			if(s==declexit){
			      if(debug==1)cout << "EXIT?" << endl;
			      return Token{exit1};
			}
			if(s==espaipitjat){
			      //if(debug==1) cout << "espai pitjat recollit!!!" << endl;
			      return Token{espaip};
			}
			if(s==decllet){//let
					if(debug==1) {
							cout << endl << "decllet" << endl;
							cout << endl << "surto token{let}" << endl<< " let = " << let << endl << " ch =" << ch << endl << " s = " << s << endl << "decllet=" << decllet << endl;
					}
					
					 return Token{let};
			}
			if(s==declsqrt){//arrel
					if(debug==1){
							cout << endl << "declsqrt" << endl;
							 cout << "càlcul de l'arrel " << endl;
					}					
					return Token{arrel};
			}
			if(s==declpow) {//pow
					if(debug==1){
							cout << endl << "declpow" << endl;
							cout << "surto Token{pows}" << endl;
							//cout << "falta llegir la segona variable per fer l'exponencial, com ho faig ?" << endl;						
					}
					return Token{pows};
					
			}			
			if (s==declconstat1) {
					if(debug==1)cout << endl << " Declara VARIABLE? (crear clase i metodes pk no es pugui sobreescriure?)" << endl;
					return Token{constat};
			}						
			return Token{name,s};
		}
		//cout << "ch =" << ch << endl;
	        error("Bad token");	
    }
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()



//------------------------------------------------------------------------------
void ajuda(){
 cout << endl << "ajuda del programa ...." << endl; 
 cout << endl << "\tper calcular el factorial : \"valor!\" on valor és un número enter" << endl; 
 cout << endl << "\tper calcular la potència : \"pow(base, exponent)\"" << endl;		
 cout << endl << "\tper calcular l'arrel quadrada : \"sqrt(valor o expressió)\"" << endl;		
 cout << endl << "per definir variables :" << endl << "\t \"declara variable=valor\"" << endl;
 cout << endl << "\tper calcular el residu d'una divisió : \"valor % (valor o expressió)\"" << endl;
 cout << endl << "per sortir pots sortir amb les següents comandes :" << endl;
 cout << endl << "\t \"quit\"" << endl;
 cout << endl << "\t \"surt\"" << endl;
 cout << endl << "\t \"exit\"" << endl;
 cout << endl << "operacions bàsiques : " << endl;
 cout << endl << "\tper multiplicar : \"valor * (valor o expressió)\"" << endl;
 cout << endl << "\tper dividir : \"valor * (valor o expressió)\"" << endl;
 cout << endl << "\tper sumar : \"valor + (valor o expressió)\"" << endl;		
 cout << endl << "\tper restar : \" valor - (valor o expressió)\"" << endl;				
 cout << endl << "\tper mostrar l'ajuda : \"ajuda\"" << endl;		
}

double calcul_pow(int i);
double sqrt1( double val);
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
	    //if(debug==1)cout << " case '{'" << endl << "t.kind = "<< t.kind << endl;
            return d;
        }
    case'(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')' ){ //&& t.kind!=',' && t.kind!=';'){
	      //cout << endl << "tpow.kind = " << t.kind << endl;
	      error("')' expected");
	    }
	    //if(debug==1)cout << " case '('" << endl << "t.kind = "<< t.kind << endl;
            return d;
        }
    case number:             // we use '8' to represent a number
      //if(debug==1)cout << " case 'number'" << endl << "t.kind = "<< t.kind << endl;
        return t.value;  // return the number's value
    case '-':
      //if(debug==1)cout << " case '-'" << endl << "t.kind = "<< t.kind << endl;
	return - primary();
    case '+':case '=': 
      //if(debug==1)cout << " case '+'" << endl << "t.kind = "<< t.kind << endl;
	return primary();
    case '%':
    case '!': 
    case '}': 
    case ')': 
    case '*': 
    case '/':
    case ',':
    case '#':
    //case pows:
      //if(debug==1)cout << " case '%,!,},),*,/,#'" << endl << "t.kind = "<< t.kind << endl;
       	return expression();
    case 'r':
	double valor; 
	double resultat;
	valor = primary();
	//if(debug==1)cout << " case 'r'" << endl << "t.kind = "<< t.kind << endl;
	if(valor <0) {
		cout << " D'aquest valor, " << valor << ", NO es pot calcular l'arrel REAL" << endl;
		return (0);
	}
	else {
		//if(debug==1)cout << " valor = " << valor; 
		//if(debug==1)cout << endl << "sqrt1 primary " << endl;
		resultat=sqrt1(valor);	
		//cout << endl << " El resultat de l'arrel de "<< valor << " és " ; // << resultat << endl;
		return (resultat);
	}
    case 'a': //si 'a', recull valor!!!!
	//if(debug==1)cout << " case 'a'" << endl << "t.kind = "<< t.kind << endl;
	//if(debug==1)cout << "get_value(t.kind) = " << get_value(t.name) << endl;
	return get_value(t.name);
    case 'h':
	//if(debug==1)cout << " case 'h'" << endl << "t.kind = "<< t.kind << endl;
	ajuda();
      return 0;
//	case pows:
		// cout << "statement pow" << endl << "t.kind = "<< t.kind << endl;
//	return 	expression();/*calcul_pow();*/
    case 'p':
	
	return calcul_pow(0);
    default:
	//if(debug==1)cout << /*"t.value = " << t.value << endl <<*/ "t.kind =" << t.kind << endl;
	//if(debug==1)cout << " case default" << endl << "t.kind = "<< t.kind << endl;
        error("primary expected");
    }
}

//------------------------------------------------------------------------------
int factorial(int left)
{
//	if(debug)cout  << " dins de factorial ?\n" ;
if (left!=1 && left!=0){
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


double sqrt1( double val){ //arrel
	double prova;
	if(val >1){
		prova =sqrt(val);
		if(debug==1)cout << "prova = " << prova << endl;
		return sqrt(val);
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
//	  	  if(debug)cout << "\nfactorial ?\n left = " << factorial((int)left) << "\n";
		  valor=left;
		  left=factorial(left);
		  if(debug==1)cout << "El factorial de " << (int)valor << " és " << (int)left << "\nIntro > ";
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
		try{
			 
		    int i1 = narrow_cast<int>(left);
		    int i2 = narrow_cast<int>(primary());
		    if (i2 == 0) error("%: divide by zero");
		    left = i1 % i2;
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
	case pows:
	  cout << endl << "expression" << endl;
	   break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double define_name(string var, double val);

double calcul_pow(int i)
{
cout << endl << " i =" << i << endl;
  try{
    Token t= ts.get();//pow
    Token t2 = ts.get(); //valor1
    double d=0; //Read first value
    Token t3 = ts.get(); //coma 
    
    try{
      
      Token t4=ts.get(); //valor2 //forçar integer ?
      //cout << endl << "t4.value = " << t.value << endl << "t.name =" << t.name << endl <<"t.kind=" << t.kind << endl;
      int i= (int)t4.value;     
      //if(debug==1)cout << "i = " << i << endl << " d=" << d << endl;
      d=t2.value;
      for (int j=1; j<i; j++) d=d*t2.value;
      Token t5 = ts.get();//)  
      //cout << endl << "t5.value = " << t.value << endl << "t.name =" << t.name << endl <<"t.kind=" << t.kind << endl;  
      return(d);
    }
    catch(exception& e){
      cout << "no és un enter ?" << endl;
    }
  
    
    return(d);//t2.value);
    
  }	
  catch(exception& e){
    cout << "Error de conversió" << endl;
    return(0);
  }
  return(0);
}

double declaration()
// assume we have seen "let”
// handle : name = expression
// declare a variable called "name ” with the initial value "expression”
{
Token t = ts.get();
if (t.kind != name) error ("name expected in declaration");
string var_name = t.name;
Token t2 = ts.get();
if ((t2.kind != '=')&&(t2.kind != '_')) error("_ or = missing in declaration of ", var_name);//aqui és on es llegeix el '_', és aquí on l'he de permetre.
double d = expression();
cout << " d= " << d << endl;
define_name(var_name,d);
if(debug==1) cout << "var_name = " << var_name << "\n d =" << d << endl;
set_value(var_name,d);
return d;
}

double declaration_constants()
// assume we have seen "let”
// handle : name = expression
// declare a variable called "name ” with the initial value "expression”
{
Token t = ts.get();
//if(debug==1)cout << "t.kind = " << t.kind << endl << " constat = " <<constat << endl; //<< " t.value = " << t.value << "t.name = " << t.name;
Token t1 = ts.get();
//if(debug==1)cout << "t1.kind = " << t1.kind << endl ; //<< "t1.value = " << t1.value << endl << "t1.name = " << t1.name << endl;
//if (t.kind != constat || t1.kind != name) error ("name expected in declaration or constant expected in declaration");
string var_name = t.name; //t1.name;
if ((t1.kind != '=')&&(t1.kind != '_')) error("_ or = missing in declaration of ", var_name);//aqui és on es llegeix el '_', és aquí on l'he de permetre.
double d = expression();
//if(debug==1)cout << " d= " << d << endl;
define_name_const(var_name,d);
if(debug==1) cout << "var_name = " << var_name << "\n d =" << d << endl;
set_value(var_name,d);
return d;
}

double statement()
{
  Token t = ts.get();
  switch (t.kind) {
	 case constat:
		 return declaration_constants();
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
			
		        if(t.kind == quit1){
				if(debug==1)cout << "AQUI ara hauria de sortir per  \"QUIT\"" << endl;
				return; 
	        	}
			if(t.kind== surt){
			   if(debug==1)cout << "AQUI ara hauria de sortir per \"SURT\"" << endl;
			   return;
			}
			if(t.kind== exit1){
			  if(debug==1)cout << "AQUI ara hauria de sortir per \"EXIT\"" << endl;
			   return;
			}
			ts.putback(t);
   		     	cout << result << statement() << endl; //expression() << endl;
		}
		catch(exception& e){ //si hi ha error d'introducció, surt aquí ...
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
	define_name("ne", 2.7182818284);
	define_name("k", 1000);
	if(debug==1)cout << "Exercises" << endl << "9. Suggest three improvements (not mentioned in this chapter) to the calculator. Implement one of them.(OPERACIONS amb potències, no en funciona cap!(+,-,*,/))" << endl;
	if(debug==1) cout << endl << "• Our primary study is programming.• Our output is programs/systems.• A programming language is (only) a tool." << endl;
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