#include <iostream>
#include <string>
using namespace std;
class Name_Pairs {
  public:
    //setters
    void set_nom(vector<string>);
    void set_age(vector<double>);
    
   void print();
    
    
   void read_names();
   void read_ages();
   

   void sort();    
    //getter
//    void get_values(vector<Name_Pairs>);
//   private:
	vector<string> name;
	vector<double> age; 
};


