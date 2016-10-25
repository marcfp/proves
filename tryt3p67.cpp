#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch ; }

int main()
{
	cout << "Please enter a floating-point value: \n ";
	double n;
	cin >> n;
	cout << " n == " << n
	 << endl << "n+1 == " << n+1 
	<< endl << "three times n == " << 3*n 
	<< endl << "twice n == " << n+n
	<< endl << "squared == " << n*n 
	<< endl << "half of n == " << n/2
	<< endl << "square root of n == " << sqrt(n)
	<< endl;
return(0);
}
