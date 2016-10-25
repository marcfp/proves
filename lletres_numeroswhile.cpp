#include<iostream>
using namespace std;
int main()
{
	char lletra ='a';
	cout << "\n Escric la lletra i el seu valor enter al costat" ;
	while (lletra <='z')
	{
		int i = lletra; //cast automatic
		cout << "\n lletra " << lletra << " equival al enter "<< i << "\n" ;
		++lletra ;
	}
	
	return (0);
}
