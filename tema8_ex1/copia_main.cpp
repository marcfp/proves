  //
// This is example code from Chapter 7.2 "Input and output" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//
  // This is example code from Chapter 7.2 "Input and output" of
  // "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
  //
  /*
	  
	  Declaration:
		  "let" Name "=" Expression
          Statement :
                  Declaration 
                  Expression <- fet
                  Print <- fet
                  pow <- 
                  let -> # <- 
                  Quit <- fet
                  
                  
          Print : 
                  ; 	<- fet
		  \n 	<- fet
          Quit:
                  q <- fet
                  quit <- fet

          Calculation Statement
          Expression :
                  Term
                  Expression + Term
                  Expression - Term
          Term :
                  Primary
                  Term * Primary
                  Term / Primary
                  Term % Primary <- fet
                  Term ! Primary <- falta
                  
                  
          Primary :
                  Number
                  ( Expression ) 
                  - Primary
                  + Primary
                  sqrt Primary <- falta
          Number :
                  Floating-point-literal
  -------------------------------------------------------------
  -> Input comes from cin through the Token_stream called td <-
  -------------------------------------------------------------
  pagina 239<- 7.7 Recovering from errors.
  */

//#include "std_lib_facilities.h"
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------


//int debug = 1; //debug
int debug = 0; //NO debug
const char number='8';
const char print=';';
const char enter='\n';
const char result='=';
const string prompt ="--/|> ";
//const string result = "= ";

const char name='a';
const char let='l';
const char arrel='r';
const string declarrel="Sqrt";

const char ajuda='h';
const string ajuda_interrogant="?";
const string ajuda_mayus="help";
const char quit='q';
const string paraula_quit="quit";
const string quit_interrogant="?";



const char constant='c';
const string paraula_const="const";


const char Roma='R';
const string declkey="let";
const string declI="I";
const string declV="V";
const string declX="X";
const string declL="L";
const string declC="C";
const string declD="D";
const string declM="M";

//------------------------------------------------------------------------------
class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch){}		//, value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)     // make a Token from a char and a double
        :kind(ch), name(n) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c); //per mirar al buffer de lectura del Token i ignorar caracters erronis
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
//------------------------------------------------------------------------------
class Variable {
public:
  string name;
  double value;
  char constant;
  Variable(string nm, double val, char constantono)//, char cons) //inicialitzo la variable
  :name(nm), value(val), constant(constantono) {}
  Variable();
  char get_constant();
};
char Variable::get_constant()
{
  return(this->constant); //myself!!!
}
Variable::Variable()
{

}

//------------------------------------------------------------------------------

class Symbol_table: public Variable{
public:
  Variable var_table_st;
Symbol_table(string nm, double val, char constantono);
  //Symbol_table(string nm, double val, char constantono);
  //Symbol_table();
  
  
};
Symbol_table::Symbol_table(string nm, double val, char constantono): Variable(nm, val, constantono)
{

}
//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}
//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()>

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) { 
		error("putback() into a full buffer");
		
		}
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

void Token_stream::ignore(char c) //c representa el tipus de token
{
  if(full && c== buffer.kind){ //mirem el buffer primer
    full=false;
    return;
  }
  full=false; //no ple el buffer;
  
  char ch=0;
  while(cin>>ch) 
    if(ch==c) return;
}

//------------------------------------------------------------------------------
//llegeix text 
//Es formen els tokens aqui
Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    cin >>  noskipws >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    //getline(cin, ch);

    if(debug==1)cout << " ch = " << ch << endl;
    //if(isspace(ch)) return Token(print);
    switch (ch) {
	
        case enter:
	case print:    // for "print"
	//case quit:    // for "quit"  //commented becouse we want	 complete word
	case result:
	case '(': 
	case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/':
	case '%': 
	case '!': //take special tokens 
	case 'L': //token let, load variables
	case 'R':
	    return Token(ch);        // let each character represent itself
	    //#####################################################################################################################
	    //taken number tokens
	case '.':
	case '0': 
	case '1': 
	case '2': 
	case '3': 
	case '4':
	case '5': 
	case '6': 
	case '7': 
	case '8': 
	case '9':
	    {
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;  	            // read a floating-point number
		if(debug==1)cout << " val = " << val << endl;
		return Token(number,val);   // let '8' represent "a number"
	    }	
	default:
	    if(isalpha(ch) || ch=='?'){
	      string s;
	      s += ch;
	      while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_' || ch=='?')) s+=ch;
	      cin.putback(ch);
	      
	      if(s == declkey) return Token{let}; //declaration keyboard
	      if(debug==1)cout << endl<< " s = " << s << endl;
	      if(s==declarrel) return Token{arrel};
	      if(s==ajuda_mayus) return Token{ajuda};
	      if(s==ajuda_interrogant) return Token{ajuda};
	      if(s==paraula_quit) return Token{quit};
	      //const char *kk=(const char*)s;
	      /*if(strcmp(kk,quit_interrogant.c_str())==0) {
		cout << "ajuda ? surto per error per ara" << endl;
		return Token{quit};
	      }*/
	      if(s==quit_interrogant) return Token{quit};
	      if(s==paraula_const){
		cout << "Constant word finded" << endl;
		return Token{constant};
	      }
	      if(s == declI || s == declV || s == declX || s == declL || s == declC || s == declD || s == declM ) return Token{Roma};
	      
	      return Token{name,s};
	    }
	    error("Bad token");
	  
	
    }
}


//------------------------------------------------------------------------------
 
double expression();    // declaration so that primary() can call expression()s
//------------------------------------------------------------------------------
double declaration();

 
//------------------------------------------------------------------------------
double define_name(string var, double val, char c);//, char cons);
void set_value(string s, double d, char c);
//------------------------------------------------------------------------------


double declaration() //declaració de variables
{
  Token t = ts.get();
  if(t.kind != name ) error("Name expected in declaration ");
  string var_name = t.name;
  
  Token t2 = ts.get();
  if (t2.kind!='=')error("= missing in declaration of ", var_name);
  
  double d = expression();
  define_name(var_name,d,'v');//,'n');
  set_value(var_name,d,'v');
  return d;
}

double declaration_constant() //declaració de variables constants
{
  Token t = ts.get();
  if(t.kind != name ) error("Name expected in declaration ");
  string var_name = t.name;
  
  Token t2 = ts.get();
  if (t2.kind!='=')error("= missing in declaration of ", var_name);
  
  double d = expression();
  define_name(var_name,d,'c');//,'n');
  set_value(var_name,d,'c');
  return d;
}

//------------------------------------------------------------------------------


double statement()
{
    Token t = ts.get();
    switch(t.kind){
      case let:
	return declaration();
      case constant:
	cout << "Defineixo variable constant \n declaration" << endl;
	return declaration_constant();
      default:
	ts.putback(t);
	return expression();
      
    }
}


//------------------------------------------------------------------------------
double get_value(string s); //agafo valor de variable
//------------------------------------------------------------------------------
double factorial(double numero){
  if(numero<0){
    numero=0;
    return 0;
  }
  else if(numero ==0){ 
	  numero=1;
	  return numero;
	}
	else if(numero==1){
//		cout << " numero*factorial(numero-1) = " << numero*factorial(numero-1)<< endl;
	      //numero=numero+numero*1;
	      return numero;
	      }
	      else if(numero >1){
//			  cout << " numero*factorial(numero-1) = " << numero*factorial(numero-1)<< endl;
		      return numero=numero*factorial(numero-1);
		    }
 
 
  
}
// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    if(debug==1)cout << endl << "t.kind =" << t.kind << endl;
    switch (t.kind) { //type of token t.kind
    case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case 'a'://variables definides?
      return get_value(t.name); //recull valor de variable definida, ja que n'hi ha vàries
    //case '\n':
    case enter:
    case number:            // we use '8' to represent a number
    
        return t.value;  // return the number's value
        
    case '-': //negative numbers
      return - primary();
    case '+':
      return primary();
    case 'r':
    {
      if(debug==1)cout << "calcul de l'arrel" << endl;
      double d = primary();
      //t = ts.get();( << endl;
      if(d<0) {cout << "Arrel no real" << endl;
	      sqrt(-d);
      }
      else return sqrt(d);
      
    }
    case 'h':
    {
	cout << endl << "aquí ha d'anar l'ajuda de la calculadora" << endl;
	cout << endl << " per sortir, escriu Quit; " << endl;
	cout << endl << " per calcular l'arrel escriu sqrt seguit de l'expressió" << endl;
	cout << endl << " per exemple sqrt 25; o sqrt(25); o sqrt(25+120-240+120);" << endl;
	cout << endl << " per guardar variables: let nom_variable=expressió" << endl;
	cout << endl << " per exemple let x=y+25^3;" << endl;
	cout << endl << "	llavors si fem let y=3" << endl;
	cout << endl << "aquí ha d'anar l'ajuda de la calculadora" << endl;
	cout << endl << "aquí ha d'anar l'ajuda de la calculadora" << endl;
	cout << endl << "aquí ha d'anar l'ajuda de la calculadora" << endl;
	
	//return(0);
	break;
    }
    case 'q':
      cout << "surt amb Quit ?" << endl;
      
      break;
    /*case 'R':
        cout << "Roman Number " << endl;
return Token{name,s};t	cout << "t.name =" << t.name << " t.value = " << t.value << endl;
	break;*/
    
    case 'c':
	if(debug==1)cout << "definir variables constants funcio declaration ?" << endl;
	break;
    case '!':
	    {
	      //cout << endl << "calculo el factorial" << endl;
	      double d = primary();
	      cout << "NO FUNCIONA, HE DE RECOLLIR EL NÚMERO, MIRAR PER \'RECULAR\' EL TOQUEN " << " d = " << d << endl << " t.value= " << t.value << endl;
	      if(d>=1) 	      cout << " el factorial de " << d << " és " <<  factorial(d) << endl;
	      else cout << " Aquest cálcul no es pot afectuar" << endl;
      
	      break;
	    }
    default:
        error("primary expected"); 
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) cout << /*error(*/"divide by zero";//);
                left /= d;
                t = ts.get();
                break;
            }
        case '%':
	    {
	      int i1=narrow_cast<int>(left);
	      int i2=narrow_cast<int>(primary());
	      if(i2==0) error("%: divide by zero");
	      left=i1%i2;
	      /*double d = primary();
	      if(d==0) error("%: divide by zero");
	      left = fmod(left,d);	     */
	      t=ts.get();
	      break;
	  }
	
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}
//------------------------------------------------------------------------------
//vector<Variable> var_table;//definició de vector de variables amb funcions i accions


vector<Symbol_table> var_table_st; ///error: use of deleted function ‘Symbol_table::Symbol_table()’

//Symbol_table::Symbol_table sym_table;



double get_value(string s)
{

  for(const Variable& v:var_table_st)
    if(v.name==s)return v.value;
  error("get: Undefined variable ", s);
}
 
void set_value(string s, double d, char c) //set the Variable named s to d
{
  for (Variable& v:var_table_st)
    if(v.name == s){      
      if (v.constant!='c'){ //comprobo si és constant o no	
	v.value=d;
      }
      else {
	cout << endl << "Constant, no es pot reescriure " << endl;
      //else cout << "no modificable" << endl;
	error("no writable CONSTANT %s!!\n",s);
      }
      return;
    }
    error("set : undefined variable",s);
}

bool is_declared(string var) //is var already in var_table?
{
  for (const Variable& v:var_table_st)
    if(v.name == var) return true;
  return false;
}

//------------------------------------------------------------------------------

double define_name(string var, double val, char c) //add (var,val) to var_table
{
 /* 
  if(is_declared(var) && cons=='s') error(var, "declared twice");
  do {
    if(cons!='s') {
      cout << "És un valor constant ? (s per constant, n mutable)" << endl;
      cin >> cons;
    }
  }while(cons!='s' && cons!='n');
  var_table.push_back(Variable{var,val,cons });
  return val;
  */
 if (is_declared(var) && c=='v'){
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
				  char valor=constant;//Variable::constant;
				  if(!is_declared(var)) var_table_st.push_back(Symbol_table(var,val,'v'));
				  else {
 				    cout << " valor = " << valor << " Constant, no es pot sobreescriure!!!" << endl;
				    exit;
				  }
                              }


          }
          else{
		if(!is_declared(var)) var_table_st.push_back(Symbol_table(var,val,'c'));
		else cout << " no es poden sobreesciure constants!!" << endl;
          }
          return val;

}


// deal with + and - 
//crida term i Token_stream.ge t
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

void clean_up_mess(){ //ignorar caracters erronis
  /*while(true){
    Token t= ts.get();
    if(t.kind==print) return;
  }*/
  //es pot comentar pk tenim el metode Token_stream::ignore(char c);
  //i amb un ts.ignore(print); funciona
   ts.ignore(print); 
}




void calculate()
{
  while (cin) 
      try{
        cout << prompt;          // print prompt
	Token t = ts.get();
	while(t.kind==print) t=ts.get(); //eat ; print
	if(t.kind==quit){ //exit
	  
	  keep_window_open();	
	  clean_up_mess();
	  return;
	}
	ts.putback(t);
	cout << statement() << endl;	
      }
      catch (exception& e){
	cerr << e.what() << endl;
	clean_up_mess();
      }
}
//------------------------------------------------------------------------------

int main()

try
{   
    cout << "\n1. Modify the calculator program from Chapter 7 to make the input stream an explicit parameter (as shown in §8.5.8), rather than simply using cin. Also give the Token_stream constructor (§7.8.2) an istream& parameter so that when we figure out how to make our own istreams (e.g.,attached to files), we can use the calculator for those. Hint: Don’t try to copy an istream." << endl;
    
    define_name("pi",3.1415926535,'c');
    define_name("e",2.7182818284,'c');
    
    //set_value("pi",3.1415926535,'s');
    
    //set_value("e",2.7182818284,'s');
        
    calculate();
   
    return (0);
}
catch (runtime_error& e) {
    cerr << e.what() << endl;
    //cout << "Please enter the character ~ to close the window" << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception!\n";
    keep_window_open("~~");
    return 2;
}

