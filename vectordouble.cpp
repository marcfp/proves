#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<double> temps; 
	for (double temperatures; cin >> temperatures;)
		temps.push_back(temperatures); 

	// calculate mean temperature
	double sum = 0; 
	for (double x : temps) sum += x; 
	cout << "The average temperature is : " << sum / temps.size() << "\n"; 

	// calculate median temperature 
	sort(temps.begin(), temps.end(), temps); 
	cout << "The median temperature is : " << temps[temps.size() / 2 ] << "\n";  


	return 0; 


return(0);
}

