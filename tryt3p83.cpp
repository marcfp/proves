#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch ; }

int main()
{
	cout << "Enter the name of the person you want to write to ";
	string first;
	string second;
	cin >> first >> second;
	cout << " Hello " << first << ", " << second  << endl;
	cout << "\tHow are you?" << endl << "I am fine. i miss you." << endl;
return(0);
}
