#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	
	int debug =0;
	
	vector<string> nom;
	vector<int> edat;
	vector<int>::iterator it;
	string lletres;
	int numedat;
	bool flaglletres=true;
	bool flagnumedat=true;
	string noname="NoName";
	cout << "Insert Name, Age until user insert NoName, 0. Then write them one per line." << endl;


	cout << "Insert name and Age like \"Marc 35\"" << endl;
	while (cin >> lletres && cin >> numedat && flaglletres==true && flagnumedat==true) {
		if(lletres=="NoName"){ 
			cout << "flaglletres=false" << endl;
			flaglletres=false;
		}
		else{
			nom.push_back(lletres);
		}
		if(numedat==0){
			 cout << "numedat=false" << endl;
			flagnumedat=false;
		}
		else{
			edat.push_back(numedat);
		}
    	}
	cout << "list of people " << endl;
	for(int i=0; i < nom.size(); i++){
	    cout << "i = " << i << ", nom ="<< nom[i] << ",  edat = "<< edat[i] << endl;
	}
	cout << "Find name of people giving one score " << endl;
	string noms;
	int aixo;
	cout << "Insert name " << endl;
	cin >> noms;
	//vector<string> cerca=noms;
	for (unsigned i=0; i<nom.size(); i++)
//	    if(strcmp(nom.at(i), cerca[0])==0) cout << "Trobat!!!" << endl;
	aixo=find (nom.begin(), nom.end(),noms)-nom.begin();
	cout << " aixo = " << aixo << endl << " edat = " << edat[aixo] << endl;
	
	 if (aixo <=nom.size()){
		cout << "Age found at position '" << aixo << "' with name = " << nom[aixo] << endl;
	}
	else{
		cout << "Age not found \n";
	}
//      int bedat=edat[aixo];
      vector<int> ed;
        int ed1;
	int ed_val;
        cout<< "Insert age to found ";
        cin >> ed1;	
//	ed.clear();
        for (unsigned i=0; i<edat.size(); i++){
//          if(strcmp(nom.at(i), cerca[0])==0) cout << "Trobat!!!" << endl;
        ed_val=find (edat.begin(), edat.end(),ed1)-edat.begin();
	cout << "ed_val =" << ed_val;
        ed.push_back(ed_val);     
	ed_val=-1; 
        }
        cout << "ed.size = " << ed.size();
	for(unsigned i=0; i< ed.size(); i++)
	{
		cout << "Edat trobada =" << ed[i] << " amb el nom = " << nom[ed[i]] << " És correcte ?" << endl;
	}

return(0);
}
