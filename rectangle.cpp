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
 



#include "rectangle.h" // You include the class description

// Contructor
Rectangle::Rectangle()
{
   this->l = 0;
   this->w = 0;
}

// Methods
double Rectangle::Area()
{
   return this->w * this->l;
}

double Rectangle::Perim()
{
   return 2*this->w + 2*this->l;
}
int main()
{


Rectangle rectangle;

int l=0;
int w=0;
int al=0;
int ll=0;
cout << "\nEntra l'alçada :\t";
while(al==0){
	cin >> l;
	if(!cin) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	else al++;
}

rectangle.l=l;
cout << "Entra l'amplada :\t";
while(ll==0){
	cin >> w;
	if(!cin){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	else ll++;

}
rectangle.w=w;


//rectangle.l = 3;
//rectangle.w = 5;

cout << "Area is " << rectangle.Area() << endl;
cout << "Perim is " << rectangle.Perim() << endl;
	
return(0);
}
