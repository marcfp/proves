#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
//#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	int i;
	double num=0;

//	std::setw(2);
//	std::setprecision(5);

	for(i=0;i<10;++i){
		num=num+pow(2,i);
//		cout.precision(5);
		cout.setf( std::ios::fixed, std:: ios::floatfield );
		cout << "quadrat " << i << endl << "número de grans d'aquest quadrat " /*<< setw(5)*/ << pow(2,i) << endl << "Número total de grans " << num << endl << "#############################################################################" ;
	}
	
}
