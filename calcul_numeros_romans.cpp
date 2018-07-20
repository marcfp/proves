#include <iostream>

#include <string>
#include <iconv.h>

using namespace std;

int debug=1; //1 debug 0 net

int roman2decimal(const string& roman) //assume roman is uppercase
{
   int result = 0;
   const int LEN = roman.length();
   int conti=0;
   int contx=0;
   //falta contl;
   int contc=0;
   int contm=0;
   int cont5m=0;
   
   string utfV="\u01B0"; //Ѵ <- control+shit+u+0474
   string utfm="\u026F"; //ɯ <- control+shit+u+026f
   string utfd="\u0256"; //ɖ <- control+shit+u+0256
   setlocale(LC_ALL, "ca_ES.UTF-8");
   cout << " roman = " << roman <<  " LEN = " << LEN << "utfV = "<< "\u01B0" << " utfm= " << utfm << " utfd= " << utfd  << endl;
   //cout << "utf8 utfV.c_str()=" << utfV.c_str() << endl;
   for (int i = 0; i < LEN; ++i)
   {
     if(roman.compare(utfV)==0) {cout << endl << endl << " lletra del 5000 trobat" << endl << endl; result+=5000; return result;}
      if (roman[i] == 'I' && i != LEN-1)
      {
         if      (roman[i+1] == 'V' && roman[i-1]!='I') { result +=    4; cout << "I suma 4 result =" << result << endl; i++; } //IV leap V char
         else if (roman[i+1] == 'X') { result +=    9; cout << "I suma 9 result = " << result << endl;i++; } //IX leap X char
         else if (roman[i+1] == 'I' ) { 
	   result +=    1; 
	   conti++;
	   if(conti>=3) { cout << "Masses lletres I seguides!!!" << endl; return 0; }
	   if(debug==1)cout << "I suma 1 result =" << result << endl;	   
	}
      }
      else if (roman[i] == 'X' && i != LEN-1)
      {
	cout << " roman.find('X') = " << roman.find('X') << " \t roman.rfind('X') =" << roman.rfind('X') << endl;
         //if      (roman[i-1] != 'L' &&roman[i+1] == 'L'  && i-1>=0) { result +=   40; i++; } //XL leap L char
         if      (roman[i+1] == 'L'/* && roman.find('X')==roman.rfind('X')*/) { 
	   result +=   40; 
	   i++; 	   
	} //XL leap L char
         else if(roman[i+1] == 'L' && roman.find('X')!=roman.rfind('X')){
	   cout << "mal format L" << endl; 
	   return 0;	   
	}
	   else if (roman[i+1] == 'C') { result +=   90; i++; } //XC leap C char
         else                        { 
	   result +=   10;      
	   contx++;
	   if(contx>=4) { cout << "Masses lletres X seguides!!!" << endl; return 0; }
	   if(debug==1)cout << "X suma 10 result =" << result << endl;
	}
      }
      else if (roman[i] == 'C' && i != LEN-1)
      {
         if      (roman[i+1] == 'D') { result +=  400; i++; } //CD leap D char
         else if (roman[i+1] == 'M') { result +=  900; i++; } //CM leap M char
         else if (roman[i+1] == 'L') { result +=  150; if(roman[i+2]!='L') i++; }
         else                        { 
	   result +=  100;      
	   contc++;
	   if(contc>=4) { cout << "Masses lletres C seguides!!!" << endl; return 0; }
	   if(debug==1)cout << "C suma 100 result =" << result << endl;	   
	}
      }
      else if (roman[i] == 'M' && i != LEN-1)
      {
         if      (roman[i+1] == 'D') { result +=  1500; i++; } //CD leap D char
         else if (roman[i+1] == 'L') { result +=  1050; if(roman[i+2]!='L') i++; }
         else if (roman[i+1] == '\u01B0') { result +=  4000; if(roman[i+2]!='L') i++; }
         else                        { 
	   result +=  1000;      
	   contm++;
	   if(contm>=3) { cout << "Masses lletres M seguides!!!" << endl; return 0; }
	   if(debug==1)cout << "M suma 1000 result =" << result << endl;	   
	}
      }else if (roman[i] == 
	'\u01B0' && i != LEN-1)
      {
	cout << " Entro dins de comparació \"\u01B0\" " << endl;
         if      (roman[i+1] == 'D') { result +=  5500; i++; } //CD leap D char
         else if (roman[i+1] == 'L') { result +=  5050; if(roman[i+2]!='L') i++; }
         else                        { 
	   result +=  5000;      
	   cont5m++;
	   if(cont5m>=3) { cout << "Masses lletres M seguides!!!" << endl; return 0; }
	   if(debug==1)cout << "V suma 5000 result =" << result << endl;	   
	}
      }else if (roman[i] == 'I')      { result +=    1; }
      else if (roman[i] == 'V')      { 
	if(roman[i-1]!='I' && roman[i+1]=='I')result +=    5;
	else {
	  if(i+1<=LEN){
	    cout << "mal format V" << endl;
	    result=0;	  
	    return 0;
	    }
	}
      }
      else if (roman[i] == 'X')      { result +=   10; }
      else if (roman[i] == 'L')      { 
	if(roman.find_first_of('L')== roman.find_last_of('L'))	result +=   50; 
	else {
	  cout << "L mal posicionada" << endl;
	  return 0;
	}	
      }
      else if (roman[i] == 'C')      { result +=  100; }
      else if (roman[i] == 'D'){
	if(roman.find_first_of('D')==roman.find_last_of('D'))      { result +=  500; }
	else {
	  cout << "D mal posicionada" << endl;
	  return 0;
	}
      }
      else if (roman[i] == 'M')      { result += 1000; }
      else if (roman[i] == '\u01B0')     {result += 5000; }
      else { 
	cout << "número erroni"; 
	cout << " roman[i] = " << roman[i] << " \"\u01B0\"=" << "\u01B0" << endl;
	return 0;	
      } 
      
   }
   return result;
}
int main()
{

	string test = "\u01B0";//"MMMDCCCXCIX"; 
	cout << "MMMDCCCXCIX = " << roman2decimal(test) << endl;
	
	return 0;
}