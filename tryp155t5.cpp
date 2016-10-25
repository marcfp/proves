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
vector<double> temps;
for(double temp; cin >>temp;)
	temps.push_back(temp);

double sum=0;
double high_temp=0;
double low_temp=0;

for(int x : temps)
{
	if(x>high_temp){
		high_temp=x;
		cout << "high_temp = " << high_temp;
	}
	if(x<low_temp){
		low_temp=x;
		cout << "low_temp = " << low_temp;
	}
	cout << " x =" << x;
	sum += x;
	cout << " sum = " << sum ;
}

cout << "Hight temperature : " << high_temp << endl;
cout << "Low temperature : " << low_temp << endl;
cout << "Avegare temperature : " << sum/temps.size() << endl;
}


