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
	vector<string> words;
	string disliked= "Broccoli"; 
	string disliked1 ="Parella";
	for (string temp; cin >> temp;)
		words.push_back(temp); 
	cout << "Number of words : " << words.size() << endl;
	
	sort(words.begin(), words.end());

	for (int i = 0; i<words.size();++i)
		if(i==0 || words[i-1]!=words[i])
			if(words[i]==disliked || words[i]==disliked1)
				cout << endl << "BLEEP" <<endl;
			else cout << words[i] << endl;

	// calculate mean temperature
/*	double sum = 0; 
	for (double x : temps) sum += x; 
	cout << "The average temperature is : " << sum / temps.size() << "\n"; 

	// calculate median temperature 
	sort(temps.begin(), temps.end(), temps); 
	cout << "The median temperature is : " << temps[temps.size() / 2 ] << "\n";  

*/
	return 0; 


return(0);
}

