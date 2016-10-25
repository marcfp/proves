#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;
int numero_primer(int  val);
int main()
{
    int n1,n2;
    vector<int> n;
    vector<int> primers;
    int i;
    cout << "Ingrese un numero: ";
    cin >> n1;
   for(i=1;i<=n1;i++){
	 n.push_back(i);
	}
   for(i=0;i<n.size();i++){
	int pos=numero_primer(n[i]);
	vector<int> primers;
	if(pos!=0){
		cout << endl << "pos =" << pos << endl;
		primers.push_back(pos);//com el borro ???
	}
//	if(pos!=0) n.erase(n.begin()+1);
   }
   for(i=1;i<n1;i++){
   cout << n[i] << endl;
   }
   for(i=1;i<primers.size();++i) cout << primers[i] << endl;
   return 0;
}
int numero_primer(int val )
{
	bool band= true;
	int m=2;
	
	while((band) && (m< val)){
		if(val % m ==0 ) 
			band=false;
		else
			++m;
	}
	if(band){
		cout << endl << "ES PRIMER " << endl;
		cout << "m = " << m << endl;
		 return(0);
		}
	
	cout << "m general = " << m << endl;
	return(m);
}
