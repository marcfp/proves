#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
inline void keep_window_open(){ char ch; cin >> ch; }
void error(string s);
int main()
{
double i;
try{
cout << "Entra qualsevol cosa :  ";
cin >> i;
cout << "i = " << i<< endl;
/*if(!cin) error("Missatge d'error "); // << endl;
//return(0);
*/
if (!cin)
    {
	    throw runtime_error("Something Bad happened here");
    }
}
//catch(exception& e){
catch(exception& ){
//cout << endl << "error : " << e.what() << " i =" << i<< endl;
cout << "Entro al catch?" <<  endl ;
keep_window_open();
return(15);
}
return(0);
}
void error(string s)
{
	throw runtime_error(s);
}
