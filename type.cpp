#include<iostream>
using namespace std;
int main()
{
/*	char c ='x';
	int i1 = c;
	int i2 = 'x';
	char c2 = i1;
	cout << c << ' << i1 << ' << c2 << '\n' ;
*/
	int a = 20;
	char c = a;
	int b = c;
	if(a!=b)
		cout << "oops!:  " << a << "!=" << b <<"\n";
	else
		cout << "Wow!! We have large characters\n";

	return (0);
}
