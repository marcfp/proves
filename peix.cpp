#include<iostream>
#include<cstring>
using namespace std;
int main()
{
cout << "T'agrada el peix ?";
char s;
cin >> s;
switch(s){
	case 'n':case 'N':
		cout<< "tu t'ho perds ...\n";
		break;
	case 'y':case 'Y':
		cout << "a mi també\n" ;
		break;
	case 's':case 'S':
		cout << "ja en som 2\n";
		break;
	default:
		cout << "no entenc què m'estàs introduint\n";
		break;
}
return (0);
}
