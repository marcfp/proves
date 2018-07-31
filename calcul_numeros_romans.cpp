#include <iostream>

#include <string>
#include <iconv.h>
#include <wchar.h>
using namespace std;

int debug=1; //1 debug 0 net
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
//val=0;
//return(val);
 int result = 0;
   const int LEN = this->cadena.length();
   int conti=0;
   int contx=0;
   //falta contl;
   int contc=0;
   int contd=0;
   int contm=0;
   int cont5m=0;
      
   /*
    repassar X ... fer repassada de I V X L C D i M
    sobretot V X L 
   */
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
         if      (this->cadena[i+1] == 'D') { 
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

/*int as_int(const string& roman) //assume roman is uppercase //calculate without classes
{
      int result = 0;
   const int LEN = roman.length();
   int conti=0;
   int contx=0;
   //falta contl;
   int contc=0;
   int contd=0;
   int contm=0;
   int cont5m=0;
      
  
   setlocale(LC_ALL, "ca_ES.UTF-8");
   if(debug==1)cout << " roman = " << roman <<  " LEN = " << LEN << endl;   
   
   for (int i = 0; i < LEN; ++i)
   {
      if (roman[i] == 'I' && i != LEN-1)
      {
         if      (roman[i+1] == 'V' && roman[i-1]!='I') { 
	   result +=    4; 
	   if(roman[i+2] == 'I' && roman.length()>=3) { 
	     cout << endl << "mal format IVI ?" << endl; 
	     return 0;
	     
	  }
	  if(debug==1)cout << "I suma 4 result =" << result << endl; 
	  i++;	   
	} //IV leap V char
         else if (roman[i+1] == 'X') { result +=    9; if(debug==1)cout << "I suma 9 result = " << result << endl;i++; } //IX leap X char
         else if (roman[i+1] == 'I' && roman[i+2] == 'I' && i+2<=LEN-1) { 
		result +=    3; 
		conti++;
		i+=2;
		if(debug==1)cout << endl << "suma 3 bucle I" << endl;
		if(conti>2) { cout << "Masses lletres I seguides!!!" << endl; return 0; }
		if(debug==1)cout << "I suma 3 result =" << result << endl;	   
	      }
	      else if(roman[i+1] == 'I' && i+1<=LEN-1){
		result +=    2; 
		conti++;
		i++;
		if(debug==1)cout << endl << "suma 2 bucle I" << endl;
		if(conti>2) { cout << "Masses lletres I seguides!!!" << endl; return 0; }
		if(debug==1)cout << "I suma 2 result =" << result << endl;	   
	      }
	      else if(roman.find('I')!=roman.rfind('I')){
		  result=0;
		  cout  << endl << "número mal format" << endl;
		  return (0);
	      }
      }
      else if (roman[i] == 'X' && i != LEN-1)
      {	
	  if(debug==1)cout << " roman.find('X') = " << roman.find('X') << " \t roman.rfind('X') =" << roman.rfind('X') << endl;
	  if(( roman[i+2]=='X' && roman[i+1]=='X' && roman[i]=='X')&& roman.length()>=3 && roman.find('X')-roman.rfind('X')==-3){
	    if(debug==1)cout << "suma 30 XXX" << endl;		
	    result += 30;
	    i += 2;
	    contx=4;
	  }
	  else if(roman.find('X')==roman.rfind('X')-1 || roman[i+1]=='X' && roman[i]=='X'){
		  if(debug==1)cout << "suma 20 XX" << endl;
		  result += 20;
		  i++;
		  contx=2;
		}
		else if(roman[i]=='X' && roman[i+1]=='I' && roman[i+2]=='X'){
		      result +=19;
		      if(debug==1) cout << endl << "bucle suma 19 X" << endl;
		      i=i+2;
		     }
		    else if((roman[i+1] == 'L' && roman.find('L')==roman.rfind('L')) && (roman[i]=='X') ) { 
			    result +=   40; 
			    if(debug==1)cout << endl << " bucle X suma 40" << endl;
			    i++; 			    	   
			  }
			  else if(roman[i+1]=='V'){
			    if(debug==1)cout << "suma 15" << endl; 
			    result += 15;
			    i++;
			      }
			      else if(roman.find('X')==roman.rfind('X') && roman[i]=='X' && roman[i+1]=='C'){
				    if(debug==1)cout << "suma 90 X" << endl;
				    result += 90;
				    i++;
				    contx=1;
				  }
			    else if(roman.find('X')==roman.rfind('X') && roman[i]=='X'){
				    if(debug==1)cout << "suma 10 X" << endl;
				    result += 10;
				    contx=1;
				  }
				  if(roman[i+1]=='C'){
				    if(debug==1)cout << "suma 90 X " << endl;
				    result +=90;
				    i++;
				  }
				  else {
				    if(debug==1)cout << " contx = " << contx << endl;
				  }
      }
      else if(roman[i] =='L' && i!= LEN-1){
	if(debug==1)cout << endl << "suma 50" << endl;
	result +=50;
	if(roman[i+1]=='V' && roman[i+4]=='I' && roman[i+3]=='I' && roman[i+2]=='I'){
	  result +=8;
	  i+=4;
	}
	else if(roman[i+1]=='V' && roman[i+2]=='I' && roman[i+3]=='I'){
	      result +=7;
	      i+=3;
	      }
	      else if(roman[i+1]=='V' && roman[i+2]=='I'){
	      result +=6;
	      i=i+2;
	      }
	      else if(roman[i+1]=='X' && roman[i+2]=='X' && roman[i+3]=='X' ){
		result +=30;
		if(roman[i+4]=='X'){
		  cout << "  masses X!! número erroni" << endl;
		  result=0;
		  return(0);
		}
		i=i+3;
	      }
	      else if(roman[i+1]=='X' && roman[i+2]=='X'  ){
		result +=20;
		i=i+2;
	      }
	      else if(roman[i+1]=='X' ){
		result +=10;
		i=i+1;
	      }
	
	
      }
      else if (roman[i] == 'C' && i != LEN-1)
      {
	if(debug==1)cout << endl << "C suma 100" << endl;
	result +=100;
	contc++;
	
	if(contc>3){
	  cout << endl << "Número mal format" << endl;
	  result=0;
	  return(0);
	}
         if      (roman[i+1] == 'D') { 
		    result +=  300; 
		    i++; 
		    if(debug==1)cout << endl << "suma 400" << endl; 
		    if(contd>0) {
			  cout << endl << " LLetra D repetida! Número mal format!" << endl;
			  result=0;
			  return (0);
		    }
	   
	} //CD leap D char
         else if (roman[i+1] == 'M') { result +=  800; i++; if(debug==1)cout << endl << "suma 900" << endl;} //CM leap M char
         else if (roman[i+1] == 'L') { result +=  50; if(debug==1)cout << endl << "suma 150" << endl;if(roman[i+2]!='L') i++; }                  
      }
      else if(roman[i]=='D' && i != LEN -1){
	if(debug==1)cout << endl << "suma 500" << endl;
	result +=500;
	contd++;
	if(contd>1){
	  cout << endl << "Número mal format, Repetició D" << endl;
	  result=0;
	  return(0);
	}
      }
      else if (roman[i] == 'M' && i != LEN-1)
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
      else if (roman[i] == 'I' && roman.length()>=3 && i>=3 && roman[i-2]!='I' && roman[i-1]!='I')      { 
	result +=    1; 
	cout << endl << "suma 1 If I i="<< i << endl;	
	conti++;
      }
      else if (roman[i] == 'V')      { 
	if(roman[i-1]!='I' && roman[i+1]=='I' && roman[i+2]!='V'){
	  result +=    5; 
	  if(debug==1)cout << endl << "suma 5" << endl;
	  
	}	
	else {
	   result +=    5; 
	   if(debug==1) cout << endl << "suma 5 else " << endl;
	}
      }
      else if (roman[i]=='X'){
		result += 10;
		if(debug==1)cout << endl << "suma 10" << endl;
	
	    }
	    else if (roman[i]=='L'){
		  result += 50;
		  if(debug==1)cout << endl << "suma 50" << endl;	
		  }
		  else if(roman[i]=='C'){
		    result +=100;
		    if(debug==1)cout << endl << "suma 100" << endl;	
		  } 
		  else {
		    cout << "90 roman[i]==" << roman[i] << endl;
		    if(roman[i]=='I' && roman[i+1]=='I'&& roman[i+2]=='I'){ 
		      result+=2;
		      i=i+3;
		    }else if(roman[i]=='I' && roman[i+1]=='I'){ 
			    result+=1;
			    i=i+2;			     
			  }else if(roman[i]=='I' && i<=LEN-1 ){ 
				  result+=1;
				  i++;
				}
		  }
      
   }
   return result;
}
*/
int main()
{
  Numero_roma r;
  

    try{
      
      
	string test;//falla per tema codificació de caracters, utf8
	test="MMMDCCCXCIX";//"LV";//"MMMDCCCXCIX";  //falla per tema codificació de caracters, utf8;
	
	  
	if(debug==1)cout << " test = " << test << endl;
	//cout << test << " as Roman is as arabic number : " << as_int(test) << endl;//falla per tema codificació de caracters, utf8r.
	
	r.set_string(test);
	
	cout << r.get_string() << " as Roman is as arabic number : " << r.as_int(test) << " calculated with classes"<< endl;
	
   }
   catch(exception e){
     cout << "exception e = " <<e.what() << endl;
     cout << "error" << endl; 
     return 2;
   }
	return 0;
}