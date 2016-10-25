#include<iostream>
using namespace std;
int main()
{
	char lletra;
	cout << "\n Escric la lletra i el seu valor enter al costat" ;
//	while (lletra <='z')
	for (lletra ='a'; lletra <='z';++lletra)
	{
		int i = lletra; //cast automatic
		cout << "\n lletra " << lletra << " equival al enter "<< i << "\n" ;
//		++lletra ;
	}
	
	return (0);
}
