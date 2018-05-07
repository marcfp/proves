#include <iostream>
#include <fstream> 

#include <string>


#include <sstream>
#include<vector>
/*
2. Write a program that creates a file of data in the form of the temperature Reading type defined
in §10.5. For testing, fill the file with at least 50 “temperature readings.” Call this program
store_temps.cpp and the file it creates raw_temps.txt.

$10.5 = struct Reading {
int hour;
double temperature;
};
// a temperature reading
// hour after midnight [0:23]
// in Fahrenheit
Given that, we could read like this:Click here to view code image
vector<Reading> temps;
// store the readings here
int hour;
double tempera ture;
while (ist >> hour >> tempera ture) {
if (hour < 0 || 23 <hour) error("hour out of ra nge");
temps.push_back(Reading{hour,temperature});
}
*/
using namespace std;

struct Reading {
int hour;
double temperature;
};  

int main(int argc, char **argv) {

//  int valor;
  Reading val;
//  int total=0;
  fstream myfile ("numeros.txt");//a,std::ios_base::in);
  int conta=0;
  int resta=50;
  if (myfile.is_open())
  {
    cout << "fitxer obert" << endl;
    //float a;
    try{
        while(resta > 0 ){
            if(conta <24){
                myfile << conta << " " << resta << endl;
            }
            else { 
                conta=0;
                myfile << conta << " " << resta << endl;
            }
         
         conta++;
         resta--;
        }
        while (conta <50 && myfile >> val.hour && myfile >> val.temperature)
        {
                //cout << "valor = " << valor << endl ;
                //total=total+valor;
                conta++;
                cout << " val.hour = " << val.hour << " val.temperature = " << val.temperature << " conta = " << conta << endl;
                
        }
        //cout << "valor total = " << total << endl;
        
        //vector<Reading> temps;
        vector<Reading> temps;
        // store the readings here
        int hour;
        double temperature;
        while (myfile >> hour  >> temperature) {
            if (hour < 0 || 23 <hour){
                        //error("hour out of range");
                        cout << "hora fora de rang" << endl;
                        break;
            }
            else{
                    temps.push_back(Reading{hour,temperature});
            }
}
        
        
        myfile.close();
    }
    catch(exception& e){
        cout << "error de tipus ?" << e.what();
    }
  }

 else cout << "Unable to open file numeros.txt for work. create this file first with numbers seperated by spaces " << endl; 
  
    
}
