#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

	vector<string> words;

//	string a;
//	string b;
		
	int i=0;

	cout << "\n Estic al punt 7 de la pàgina 127 \n";
	cout << "\n Entra 1 número amb les unitats corresponents ( cm, m, in, ft)\n per sortir escriu \"control+d\"";
	for (string temp; cin>>temp; ) // re ad
			words.push_back(temp); // put into ve ctor
		
		cout << "Number of words: " << words.size() << '\n';
		if(words.size()>1){
			if (std::find(words.begin(), words.end(), "cm") != words.end())
			{
				cout << "\n hi ha cm ? \n";
			}
			if (std::find(words.begin(), words.end(), "m") != words.end())
        	        {
                	        cout << "\n! hi ha m  \n";
	                }
			if (std::find(words.begin(), words.end(), "in") != words.end())
	                {
        	                cout << "\n ¿hi ha in!!  \n";
                	}
			if (std::find(words.begin(), words.end(), "ft") != words.end())
	                {
        	                cout << "\n hi ha ft!!! \n";
         	       }	
		}
		else{
			cout << "És tot junt ? com ho faig ?" ;
	}
	
	
return(0);
}

