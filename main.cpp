#include <iostream>
#include <fstream> 
#include <vector>

/*
 1. Start a program to work with points, discussed in §10.4. Begin by defining the data type Point
that has two coordinate members x and y.
*/
using namespace std;

struct Point{
  long int x;
  long int y;
};

void compara( vector<Point> processed_points , vector<Point> points);

    

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
    char ll1;
    char ll2;
    char ll3;
    char ll4;
    int tot=0;
    std::cout << "treu (com convertir un char a un enter amb c++)" << endl;
    while (ist.get(ll1) && ist.get(ll2) && ist.get(ll3) && ist.get(ll4)){ 
        
          long int n1= (int)ll1- '0';
          long int n3= (int)ll3- '0';
          
          
          processed_points.push_back(Point{n1,n3}); 
                         
          
    }
    
    cout << "processed_points.size() =" << processed_points.size() << " processed_points : " << endl;
    for(int i=0; i<processed_points.size();++i){
        ost << processed_points[i].x << " "<< processed_points[i].y << endl; 
        cout <<  processed_points[i].x << " "<< processed_points[i].y << endl; 
    }
    cout << "points: " << endl;
    for(int i=0;i<points.size();++i){
        cout << points[i].x << " " << points[i].y << endl;
    }
    
    compara(processed_points, points);
    ist.close();
    cout << "ESTIC FORA!!" << endl;
}
void compara( vector<Point> processed_points , vector<Point> points){
    int fals=1;
 if(processed_points.size()!=points.size()) fals=0;
 else{
        for(int i=0;i<points.size();++i){
            if(points[i].x!= processed_points[i].x || points[i].y!= processed_points[i].y) fals=0;
        }
 }
 if(fals!=1) cout << endl << "Something's wrong!" << endl;
cat 
}
