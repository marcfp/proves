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
                //ost << "x = " << x << ", y = " << y << endl;
        }
    }
    
    

    
    for(int i=0; i<points.size();++i)
	ost << points[i].x << " "<< points[i].y << endl;
    
    ost.close();
    
    ifstream ist{oname};
    
    if(!ist){
        cout << "can't open ifstream file " <<oname << endl;
	    return(1);
    }
    else {
        cout << endl << " Fitxer obert" << endl;
    }
    vector<Point> processed_points;
    char n1;
    char n2;
    int tot=0;
    std::cout << "treu " << endl;
    while (ist.get(n1) && ist.get(n2)){ 
        // loop getting single characters
           // n2=n1;
        ist.seekg();
        ist.read(n2);
          std::cout << "n1 = " <<  n1 << " n2 = " << n2 << endl;
          processed_points.push_back(Point{n1,n2});
          t
    }
    
    ist.close();
    cout << "processed_points : " << endl;
    for(int i=0; i<processed_points.size();++i)
	ost << processed_points[i].x << " "<< processed_points[i].y << endl;
}
