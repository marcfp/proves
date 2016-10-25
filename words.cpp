#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

//int existeix=0;
vector<string> paraules;

cout << "\ndiccionari que escriu \"bleeps\" si escrius més d'una vegada una mateixa paraula \n" ;
for(string temp; cin >> temp;) 
	paraules.push_back(temp);

cout << "Número de paraules llegides  : " << paraules.size() << "\n" ;


sort(paraules.begin(), paraules.end());

for (int i=0; i<paraules.size(); ++i){
	if(i==0 || paraules[i-1] != paraules[i] ) {
						 cout << "\n" << paraules[i] << " i = " << i << "\n";
//						existeix=1;
				}
	else {
		cout << "\n BLEEP!!! \n" ;
//		 existeix= 0;
	 }
}
	//if(i==0 || paraules[i-1] != paraules[i]) cout << paraules[i] << "\n" ;
cout << "\n Language features , pàgina 126 \n"; 
return (0);
}
