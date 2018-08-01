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
		  let -> #
		  Quit
		  surt
		  roman numbers in progress (function correct)
	  Print :
		  ;
	  Quit:
		  quit
		  surt
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
		  Term ! Primary
		  
		  
	  Primary :
		  Number
		  ( Expression ) 
		  - Primary
		  + Primary
		  sqrt Primary
	  Number :
		  Floating-point-literal
  -------------------------------------------------------------
  -> Input comes from cin through the Token_stream called td <-
  -------------------------------------------------------------
  */

#include "std_lib_facilities.h"

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
	    while(cin>>ch){
		    //cout << " c=" <<  endl;
		    if(ch==c) return;
	    }
    }


    /*
     romans
    */
    
class Numero_roma{
  string cadena;
  int val;
public:
  int as_int(string text);
  void set_string(string text);
  string get_string();
};

void Numero_roma::set_string(string text)//maked with classes
{
    cadena=text;
}
string Numero_roma::get_string() //maked with classes
{
  return cadena;
}

int Numero_roma::as_int(string text)//calculated with classes
{
   int result = 0;
   const int LEN = this->cadena.length();
   int conti=0;
   int contx=0;
   //falta contl;
   int contc=0;
   int contd=0;
   int contm=0;
   int cont5m=0;
      
   setlocale(LC_ALL, "ca_ES.UTF-8");
   if(debug==1)cout << " this->cadena = " << this->cadena <<  " LEN = " << LEN << endl;   
   
   for (int i = 0; i < LEN; ++i)
   {
      if (this->cadena[i] == 'I' && i != LEN-1)
      {
         if      (this->cadena[i+1] == 'V' && this->cadena[i-1]!='I') { 
	   result +=    4; 
	   if(this->cadena[i+2] == 'I' && this->cadena.length()>=3) { 
	     cout << endl << "mal format IVI ?" << endl; 
	     return 0;	     
	  }
	  if(debug==1)cout << "I suma 4 result =" << result << endl; 
	  i++;	   
	} //IV leap V char
         else if (this->cadena[i+1] == 'X') { result +=    9; if(debug==1)cout << "I suma 9 result = " << result << endl;i++; } //IX leap X char
         else if (this->cadena[i+1] == 'I' && this->cadena[i+2] == 'I' && i+2<=LEN-1) { 
		result +=    3; 
		conti++;
		i+=2;
		if(debug==1)cout << endl << "suma 3 bucle I" << endl;
		if(conti>2) { cout << "Masses lletres I seguides!!!" << endl; return 0; }
		if(debug==1)cout << "I suma 3 result =" << result << endl;	   
	      }
	      else if(this->cadena[i+1] == 'I' && i+1<=LEN-1){
		result +=    2; 
		conti++;
		i++;
		if(debug==1)cout << endl << "suma 2 bucle I" << endl;
		if(conti>2) { cout << "Masses lletres I seguides!!!" << endl; return 0; }
		if(debug==1)cout << "I suma 2 result =" << result << endl;	   
	      }
	      else if(this->cadena.find('I')!=this->cadena.rfind('I')){
		  result=0;
		  cout  << endl << "número mal format" << endl;
		  return (0);
	      }
      }
      else if (this->cadena[i] == 'X' && i != LEN-1)
      {	
	  if(debug==1)cout << " this->cadena.find('X') = " << this->cadena.find('X') << " \t this->cadena.rfind('X') =" << this->cadena.rfind('X') << endl;
	  if((/*roman.find('X')==roman.rfind('X')-2 ||*/ this->cadena[i+2]=='X' && this->cadena[i+1]=='X' && this->cadena[i]=='X')&& this->cadena.length()>=3 && this->cadena.find('X')-this->cadena.rfind('X')==-3){
	    if(debug==1)cout << "suma 30 XXX" << endl;		
	    result += 30;
	    i += 2;
	    contx=4;
	  }
	  else if(this->cadena.find('X')==this->cadena.rfind('X')-1 || this->cadena[i+1]=='X' && this->cadena[i]=='X'){
		  if(debug==1)cout << "suma 20 XX" << endl;
		  result += 20;
		  i++;
		  contx=2;
		}
		else if(this->cadena[i]=='X' && this->cadena[i+1]=='I' && this->cadena[i+2]=='X'){
		      result +=19;
		      if(debug==1) cout << endl << "bucle suma 19 X" << endl;
		      i=i+2;
		     }
		    else if((this->cadena[i+1] == 'L' && this->cadena.find('L')==this->cadena.rfind('L')) && (this->cadena[i]=='X') ) { 
			    result +=   40; 
			    if(debug==1)cout << endl << " bucle X suma 40" << endl;
			    i++; 			    	   
			  }
			  else if(this->cadena[i+1]=='V'){
			    if(debug==1)cout << "suma 15" << endl; 
			    result += 15;
			    i++;
			      }
			      else if(this->cadena.find('X')==this->cadena.rfind('X') && this->cadena[i]=='X' && this->cadena[i+1]=='C'){
				    if(debug==1)cout << "suma 90 X" << endl;
				    result += 90;
				    i++;
				    contx=1;
				  }
			    else if(this->cadena.find('X')==this->cadena.rfind('X') && this->cadena[i]=='X'){
				    if(debug==1)cout << "suma 10 X" << endl;
				    result += 10;
				    contx=1;
				  }
				  if(this->cadena[i+1]=='C'){
				    if(debug==1)cout << "suma 90 X " << endl;
				    result +=90;
				    i++;
				  }
				  else {
				    if(debug==1)cout << " contx = " << contx << endl;
				  }
      }
      else if(this->cadena[i] =='L' && i!= LEN-1){
	if(debug==1)cout << endl << "suma 50" << endl;
	result +=50;
	if(this->cadena[i+1]=='V' && this->cadena[i+4]=='I' && this->cadena[i+3]=='I' && this->cadena[i+2]=='I'){
	  result +=8;
	  i+=4;
	}
	else if(this->cadena[i+1]=='V' && this->cadena[i+2]=='I' && this->cadena[i+3]=='I'){
	      result +=7;
	      i+=3;
	      }
	      else if(this->cadena[i+1]=='V' && this->cadena[i+2]=='I'){
	      result +=6;
	      i=i+2;
	      }
	      else if(this->cadena[i+1]=='X' && this->cadena[i+2]=='X' && this->cadena[i+3]=='X' ){
		result +=30;
		if(this->cadena[i+4]=='X'){
		  cout << "  masses X!! número erroni" << endl;
		  result=0;
		  return(0);
		}
		i=i+3;
	      }
	      else if(this->cadena[i+1]=='X' && this->cadena[i+2]=='X'  ){
		result +=20;
		i=i+2;
	      }
	      else if(this->cadena[i+1]=='X' ){
		result +=10;
		i=i+1;
	      }
      }
      else if (this->cadena[i] == 'C' && i != LEN-1)
      {
	if(debug==1)cout << endl << "C suma 100" << endl;
	result +=100;
	contc++;	
	if(contc>3){
	  cout << endl << "Número mal format" << endl;
	  result=0;
	  return(0);
	}
        if(this->cadena[i+1] == 'D') { 
		    result +=  300; 
		    i++; 
		    if(debug==1)cout << endl << "suma 400" << endl; 
		    if(contd>0) {
			  cout << endl << " LLetra D repetida! Número mal format!" << endl;
			  result=0;
			  return (0);
		    }
	   
	} //CD leap D char
        else if (this->cadena[i+1] == 'M') { result +=  800; i++; if(debug==1)cout << endl << "suma 900" << endl;} //CM leap M char
        else if (this->cadena[i+1] == 'L') { result +=  50; if(debug==1)cout << endl << "suma 150" << endl;if(this->cadena[i+2]!='L') i++; }                  
      }
      else if(this->cadena[i]=='D' && i != LEN -1){
	if(debug==1)cout << endl << "suma 500" << endl;
	result +=500;
	contd++;
	if(contd>1){
	  cout << endl << "Número mal format, Repetició D" << endl;
	  result=0;
	  return(0);
	}
      }
      else if (this->cadena[i] == 'M' && i != LEN-1)
      {
	 if(debug==1) cout << endl << "suma 1000" << endl;
	 result +=1000;
	 contm++;
	 if(contm>3){
	  result=0;
	  cout << endl << "LLetra M repetides masses cops" << endl ;
	  return(0);
	 }	 
      }
      else if (this->cadena[i] == 'I' && this->cadena.length()>=3 && i>=3 && this->cadena[i-2]!='I' && this->cadena[i-1]!='I')      { 
	result +=    1; 
	cout << endl << "suma 1 If I i="<< i << endl;	
	conti++;
      }
      else if (this->cadena[i] == 'V')      { 
	if(this->cadena[i-1]!='I' && this->cadena[i+1]=='I' && this->cadena[i+2]!='V'){
	  result +=    5; 
	  if(debug==1)cout << endl << "suma 5" << endl;	  
	}	
	else {
	   result +=    5; 
	   if(debug==1) cout << endl << "suma 5 else " << endl;
	}
      }
      else if (this->cadena[i]=='X'){
		result += 10;
		if(debug==1)cout << endl << "suma 10" << endl;	
	    }
	    else if (this->cadena[i]=='L'){
		  result += 50;
		  if(debug==1)cout << endl << "suma 50" << endl;	
		  }
		  else if(this->cadena[i]=='C'){
		    result +=100;
		    if(debug==1)cout << endl << "suma 100" << endl;	
		  } 
		  else {
		    cout << "90 roman[i]==" << this->cadena[i] << endl;
		    if(this->cadena[i]=='I' && this->cadena[i+1]=='I'&& this->cadena[i+2]=='I'){ 
		      result+=2;
		      i=i+3;
		    }else if(this->cadena[i]=='I' && this->cadena[i+1]=='I'){ 
			    result+=1;
			    i=i+2;			     
			  }else if(this->cadena[i]=='I' && i<=LEN-1 ){ 
				  result+=1;
				  i++;
				}
		  }      
   }
   val= result;
   return(val);
}
    /*
     fi romans
    */
    

void clean_up_mess()
  {
	  ts.ignore(print); //pagina 216-217 del llibre, just al cambiar de pàgina
  }



  //------------------------------------------------------------------------------

double get_value(string s)// return the Value of a variable named s
  {
	cout << "\n\n\nDefinir valors romans a la taula és la solució ? \n\n\n" << endl;
	cout << "s = " << s << endl;
	for(const Variable& v: var_table)
		  if(v.name == s) return v.value;
		  else cout << "\n v.name = " << v.name << "\n v.value =" << v.value << endl;
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

  double define_name(string var, double val) // add (var,val) to var_table
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
					    var_table.push_back(Variable(var,val)); 
			      }
	  
	  
	  }
	  else{
		var_table.push_back(Variable(var,val));
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

  const char pows='p';
  const string declpow = "pow";

  const char surt='s';
  const string declsurt="surt";
  const char quit1='q';
  const string declquit="quit";
  const char exit1='e';
  const string declexit="exit";

  const char decldecl='d';
  const string decldecls="declara";

  const char romaI='I';
  const string declromaI="I";
  const char romaV='V';
  const string declromaV="V";
  const char romaX='X';
  const string declromaX="X";
  const char romaL='L';
  const string declromaL="L";
  const char romaC='C';
  const string declromaC="C";
  const char romaD='D';
  const string declromaD="D";
  const char romaM='M';
  const string declromaM="M";
  /*
  const char romaI='I';
  const char romaV='V';
  const char romaX='X';
  const char romaL='L';
  const char romaC='C';
  const char romaD='D';
  const char romaM='M';5
  */

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
		  case ',':
		  case '#':
		  //case '_':
			  return Token(ch);        // let each character represent itself
	      case '.':
	      case '0': case '1': case '2': case '3': case '4':
	      case '5': case '6': case '7': case '8': case '9':
//	      case 'I':
		  {
  //		   if(debug==1) cout << "ch = " << ch << endl;
		      cin.putback(ch);         // put digit back into the input stream
		      double val;
		      cin >> val;              // read a floating-point number
  		   if(debug==1) cout << "val = " << val << endl << " number = " << number << endl;
		      return Token(number,val);   // let '8' represent "a number"
		  }
	    default:
		  if(isalpha(ch)){ //si es let, val l, entro aquí.
			  string s;
			  //if(debug==1)cout << "s(abans) = " <<  s << endl;
			  s += ch;
			  //if(debug==1)cout << "s(després) = " << s << endl;
			  while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')){ // comparar aquí si ch == _ (underscore), no ?
					  s+=ch;
  					if(debug==1){
						  cout << endl << "carrega" << endl;
						  cout << endl << " ch = " << ch << endl << " s = " << s << endl << "decllet = " << decllet << endl << " s = " << s << endl;
						  cout << "s = " << s << " he de desgranar aquesta 's' per calcular números romans, no ?" << endl;
						  }
  
			  }
			  cin.putback(ch);
//			  if(debug==1)cout << "ch = " << ch;
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
			  if(s==decllet){//let
					  if(debug==1) {
							  cout << endl << "decllet" << endl;
							  cout << endl << "surto token{let}" << endl<< " let = " << let << endl << " ch =" << ch << endl << " s = " << s << endl << "decllet=" << decllet << endl;
					  }
					  
					  return Token{let};
			  }
			  if(s==declsqrt){//arrel
/*					  if(debug==1){
							  cout << endl << "declsqrt" << endl;
							  cout << "faig arrel ?(get)" << endl;
					  }
*/
					  return Token{arrel};
			  }

			  if(s==declpow) {//pow
					  if(debug==1){
							  cout << endl << "declpow" << endl;
							  cout << "faig la potència?" << endl;
							  cout << "falta llegir la segona variable per fer l'exponencial, com ho faig ?" << endl;
							  
							  
					  }
					  return Token{pows};
					  //float i;
					  //llegir 
					  //expression 
					  //o
					  //primary
					  //o
					  //term	
					  //return (0); //Token{pows};
			  }
			  if (s==decldecls) {
			    cout << " Declara VARIABLE? (crear clase i metodes pk no es pugui sobreescriure?)" << endl;
			  }
			  /*if(s==declromaI) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=1; 
			    //Token t;
			    //t.kind{ch,val};
			    // t.value=1;
			    cout << " fer conversió de números romans a números arabs valor 1" << " \n Retornar token a amb valor 1 " << "\n val = " << val << endl;
			    //Retornar token a amb valor 1
			    return Token{romaI,val};//(number,val); //dóna primary expected ?? pk ?? t.name no conté res
			  }
			  if(s==declromaV) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=5;
			    
			    cout << " fer conversió de números romans a números arabs valor 5" << " \n Retornar token a amb valor 5 "<< endl;

			    //Retornar token a amb valor 5
			    return Token{romaV,val};
			  }
			  if(s==declromaX) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=10;
			    cout << " fer conversió de números romans a números arabs valor 10" << " \n Retornar token a amb valor 10 " << endl;
			    //Retornar token a amb valor 10
			    //return Token{romaX};
			    return Token{romaX,val};
			  }
			  if(s==declromaL) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=50;
			    cout << " fer conversió de números romans a números arabs valor 50" << " \n Retornar token a amb valor 50 "<< endl;
			    //Retornar token a amb valor 50
			    //return Token{romaL};
			    return Token{romaL,val};
			  }
			  if(s==declromaC) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=100;
			    cout << " fer conversió de números romans a números arabs valor 100" << " \n Retornar token a amb valor 100 "<< endl;
			    //Retornar token a amb valor 100
			    //return Token{romaC};
			    return Token{romaC,val};
			  }
			  if(s==declromaD) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=500;
			    cout << " fer conversió de números romans a números arabs valor 500" << " \n Retornar token a amb valor 500 "<< endl;
			    //Retornar token a amb valor 500
			    //return Token{romaD};
			    return Token{romaD,val};
			  }
			  if(s==declromaM) {
			    cin.putback(ch);         // put digit back into the input stream
			    double val;
			    val=1000;
			    cout << " fer conversió de números romans a números arabs valor 1000" << " \n Retornar token a amb valor 1000 "<< endl;
			    //Retornar token a amb valor 1000
			    //return Token{romaM};
			    return Token{romaM,val};
			  }*/
			  if(s.find("I") || s.find("V")|| s.find("X")|| s.find("L")|| s.find("C")|| s.find("D")|| s.find("M")){
			    cout << endl << "això funciona ? és així ?"  << endl;
			    Numero_roma r;
			    r.set_string(s);
			    double val=r.as_int(s);
			    cout << endl << " el valor entrat en números romans és " << val << endl;
			    return Token{'W',val};
			  }
/*			  if(debug==1){ 
					  cout << endl << "ultim debug" << endl;
					  cout << endl << "let = " << let << "surto token{name,s}" << " name = " << name << " s = " << s << endl << " ch ='" << ch << "'" << endl << "name = '" << name << "'" << endl << " s ='" << s << "'" << endl << " let ='" << let << "'" << endl << " number = '" << number << "'" << endl << " declsqrt=" << declsqrt << endl << " arrel = " << arrel << endl;
			  }
*/
			 
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
  // deal with numbers and parentheses
double primary()
  {
      Token t = ts.get();
      cout << "primary : \nt.kind = " << t.kind << "\n t.value = " << t.value << "\nt.name = "<< t.name << endl;
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
/*################################################################################################################################################*/
      case 'W': //falta retornar el resultat com a número romà
	return t.value;  // return the number's value
/*################################################################################################################################################*/
      case number:             // we use '8' to represent a number
	  return t.value;  // return the number's value
	  
      case '-':
	  return - primary();
      case '+':case '=': 
	  return primary();
      case 'r':
	  double valor; 
	  double resultat;
	  valor = primary();
	  if(valor <0) {
		  cout << " D'aquest valor, " << valor << ", NO es pot calcular l'arrel REAL" << endl;
		  return (0);
	  }
	  else {
//		if(debug==1)cout << " valor = " << valor; 
		resultat=sqrt(valor);	
//		cout << endl << " El resultat de l'arrel de "<< valor << " és " ; // << resultat << endl;
		return (resultat);
	  }
      case 'a': //si 'a', recull valor!!!!
	  if(debug==1)cout << "get_value(t.name) = " << get_value(t.name) << endl;
//	  if(debug==1)cout << "t.value = " << t.value << endl;
	  return get_value(t.name);      	
      default:
	  //if(debug==1)cout << "t.value = " << t.value << endl << "t.kind =" << t.kind << endl;
	  error("primary expected");
      }
  }

  //------------------------------------------------------------------------------
int factorial(int left)
  {
  //	if(debug)cout  << " dins de factorial ?\n" ;
  if (left!=1 && left!=0){
/*		cout << "\nfactorial  de 1 ";
		left=1;
		return(1);
*/
//		if(debug) cout << "\n factorial de  " << left << " * factorial(" << left-1 << ") = " << left*factorial(left-1) ;
		  return( left* factorial(left-1));


	  }
	  else {
//		if(debug) cout << "left = " << left << "\n";
		if(left==0) return(1);
//		if(debug) cout << "\nfactorial  de 1 " << endl;
		return(1);
		}

  }


double sqrt1( double val){ //arrel
	  double prova;
	  if(val >1){
		  prova =sqrt(val);
		  if(debug==1)cout << "prova = " << prova << endl;
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
			  
		    //pàgina 208 del llibre pdf pregunta 7. What does narrow_cast do?
		      int i1 = narrow_cast<int>(left);
		      int i2 = narrow_cast<int>(primary());
		      if (i2 == 0) error("%: divide by zero");
		      left = i1 % i2;
		      t = ts.get();
		      break;
		    
/*			double d = primary();
			if(d==0) error("divide by zero");
//			if(i2==0) error("% : divide by zero");
			left = fmod(left,d);//i1 % i2;
			t = ts.get();
			break;
*/	
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

double calcul_pow()
  {

    try{
      Token t= ts.get();//pow
      Token t2 = ts.get(); //valor1

      double d=t2.value; //Read first value
      Token t3 = ts.get(); //coma 

      
      //Token t4 = ts.get(); //valor2 //forçar integer
      //float i=(int)t4.value;
      try{
	Token t4=ts.get(); //valor2 //forçar integer ?
	int i= (int)t4.value;     
	if(debug==1)cout << "i = " << i << endl << " d=" << d << endl;
	for (int j=1; j<i; j++) d=d*t2.value;
	Token t5 = ts.get();
	
	return(d);
      }
      catch(exception& e){
	cout << "no és un enter ?" << endl;
      }
    
      
      return(0);
      
    }	
    catch(exception& e){
      cout << "Error de conversió" << endl;
      return(0);
    }
  }

double declaration()
  // assume we have seen "let”
  // handle : name = expression
  // declare a variable called "name ” with the initial value "expression”
  {
  Token t = ts.get();
  //cout << "DEBUGt.kind = " << t.kind << endl << " name =" << name << endl; //kind value i name
  if(debug==1)cout << "dins declaration : t.kind = " << t.kind << endl << "t.value = " << t.value << endl << "t.name = " << t.name << endl;
  if (t.kind != name) error ("name expected in declaration");
  string var_name = t.name;


  Token t2 = ts.get();
  if ((t2.kind != '=')&&(t2.kind != '_')) error("_ or = missing in declaration of ", var_name);//aqui és on es llegeix el '_', és aquí on l'he de permetre.
  //cout << "si?" << endl;
  double d = expression();
  if(debug==1)cout << " d= " << d << endl;
  define_name(var_name,d);
  if(debug==1) cout << "var_name = " << var_name << "\n d =" << d << endl;
  set_value(var_name,d);
  return d;
}


double statement()
  {
    Token t = ts.get();
    switch (t.kind) {
	  case let:
		  return declaration();
	  case pows:
		  // cout << "statement pow" << endl << "t.kind = "<< t.kind << endl;
		  return 	calcul_pow();
	  //	cout << "ts.putback(t) = " << ts.putback(t) << endl;
  //		return (ts.putback(t)); 
	  default:
		  //cout << "passa ?" << endl ;
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
  //				keep_window_open();
  //				return (0);
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
			  if(debug==1)cout << "t.kind = " << t.kind << endl;
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
	  /*define_name("I", 1);
	  define_name("V", 5);
	  define_name("X", 10);
	  define_name("L", 50);
	  define_name("C", 100);
	  define_name("D", 500);
	  define_name("M", 1000);*/
	  define_name("pi", 3.1415926535);
	  define_name("ne", 2.7182818284);
	  define_name("k", 1000);
	  if(debug==1)cout << "\npàgina 326 del pdf,  TEMA 10, Exercise 7"<< endl;
	  if(debug==1)cout << "Exercise : " << endl << "7. Make a version of the calculator from Chapter 7 that accepts Roman numerals rather than the usual Arabic ones, for example, XXI + CIV == CXXV. (dóna resultats aràbics, no romans, falta fer la conversió a romà)" << endl;
	  /*
	  * 
	  http://www.cplusplus.com/doc/tutorial/classes/
	  http://www.cplusplus.com/doc/tutorial/templates/
	  http://www.cplusplus.com/doc/tutorial/classes2/
	  http://www.cplusplus.com/doc/tutorial/inheritance/
	  http://www.cplusplus.com/doc/tutorial/polymorphism/
	  */
	  calculate();
	  if(debug==1)cout << "Fora calculate" << endl;
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