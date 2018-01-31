#include <iostream>
#include <ctime>
#include <string>

using namespace std;
string months[] = {"Gen", "Feb", "Mar", "Abr", "Mai", "Jun",

                        "Jul", "Agt", "Set", "Oct", "Nov", "Dec"};

string days[] = {"Diu", "Dll", "Dmt", "Dmc", "Dj", "Dv",

                      "Dss"};

class Date{
	    // Private Members
    private:
        string month;
        string day;
        int date;
        int year;
    // Public Members
    public:
        // Default Constructor
        Date() { 
                const int BASE_YEAR = 1900;
                time_t timer;
                tm * time;
                std::time(&timer);
                time = localtime(&timer);
                date = time->tm_mday;
		month = months[time->tm_mon];
                day = days[time->tm_wday];
                year = time->tm_year + BASE_YEAR;
        }

        //void printDate(void) { 
	int printDate(){
            std::cout <<
			//return (
			  "Data actual :  " 
                      << this->day << ", " << this->date << " de "
                      << this->month  << " del " << this->year; //);
		return (0);
        }

        // Destructor
        ~Date() {}
};
class Book {
  public:
    //setters
	int64_t isdn;
	std::string title;
	std::string autor;
	Date date;
//	Date copyrightdate; // = new Date(30,1,2018);
/*	unsigned int dia, mes;
	int ano;
	
	do{
		cout << "\n Introdueix el dia : " ;
		cin >> dia;
		cout << "\n Intrudueix el mes : " ;
		cin >> mes;
		cout << "\n Introdueix l'any : " ;
		cin >> ano;
	}while (!esCorrecta(dia, mes, ano));
*/
};


