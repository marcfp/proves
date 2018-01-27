#include <iostream>
#include <string>
using namespace std;
class Name_Pairs {
  public:
    //setters
    void set_nom(string);
    void set_age(double);
    
   void print();
    
    
   void read_names();
   void read_ages();
   

   void sort();    
    //getter
//    void get_values(vector<Name_Pairs>);
//   private:
//	vector<double>::iterator  it_age = age.begin();
//	vector<double>::iterator it_age_fi = age.end();
	vector<string> name;
	vector<double> age; 
};


