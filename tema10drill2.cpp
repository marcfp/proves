#include <iostream>
#include <fstream> 
#include <vector>

/*
2. Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is
entered, store it in a vector of Points called original_points.
*/
using namespace std;

struct Point{
  int x;
  int y;
};

int main(int argc, char **argv) {
    
    cout << "Please enter output file name: ";
    string oname;
    cin >> oname;
    ofstream ost {oname};
    // ist is an input stre am for the file name d name
    if (!ost) {
	    cout << "can't open input file " <<oname << endl;
	    return(1);
    }
    else{
	    cout << "Fitxer obert!!" << endl;
    }
    
    vector<Point> original_points;
    int x;
    int y;
    int conta=0;
    //cin >> x >> y ;
    cout << endl << "Per sortir un 0 algun dels punts i sortiràs" << endl;
    while(cin >> x >> y and conta<=6 ){
        cout << "x = " << x << " i y =" << y << endl << "conta = " << conta << endl;
        
       
        if(x==0 || y==0 || conta==6){
	  cout << endl << "Sortida del programa per fi d'entrada o per què s'ha entrat 0 en algun dels 2 nombres demanats" << endl;
	  break;
	}
        else  {
                original_points.push_back(Point{x,y});
                ost << "x = " << x << ", y = " << y << endl;
        }
        conta++;
    }
    
    

    
    for(int i=0; i<original_points.size();++i)
	ost << "'" << original_points[i].x << "','"<< original_points[i].y << "'" << endl;
    
    ost.close();
    
    return 0;
}