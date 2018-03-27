#include <iostream>
#include <fstream> 
#include <vector>

/*
 1. Start a program to work with points, discussed in §10.4. Begin by defining the data type Point
that has two coordinate members x and y.
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
    
    vector<Point> points;
    int x;
    int y;
    //cin >> x >> y ;
    cout << endl << "Per sortir un 0 algun dels punts i sortiràs" << endl;
    while(cin >> x >> y ){
        cout << "x = " << x << " i y =" << y << endl;
        
       
        if(x==0 || y==0) break;
        else  {
                points.push_back(Point{x,y});
                ost << "x = " << x << ", y = " << y << endl;
        }
    }
    
    

    
    for(int i=0; i<points.size();++i)
	ost << "'" << points[i].x << "','"<< points[i].y << "'" << endl;
    
    ost.close();
    
    return 0;
}
