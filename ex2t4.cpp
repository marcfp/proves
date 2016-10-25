#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<double> temps;
	for(double temp ; cin >> temp;)
		temps.push_back(temp);

	double sum=0;
	for(double x:temps) sum+=x;
	cout << "Average temperature : " << sum/temps.size() << endl;

	sort(temps.begin(), temps.end());
	cout << "Median temperature: " << temps[temps.size()/2] << endl;
return(0);
}
