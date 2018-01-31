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
//    private:
	//ha de ser public per accedir des del pare ?
	public:
        string month;
        string day;
        int date;
        int year;
    // Public Members
  //  public:
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
		this -> day = this -> day;
		this -> date = this -> date;
		this -> month = this -> month;
		this -> year = this -> year;
		return (0);
        }
        // Destructor
        ~Date() {}
};
class Book {
  public:
    //setters
	int64_t isdn;
	string title;
	string autor;
	Date date;

	void getIsdn(){
		cout << endl << "get Isdan of book " << endl;
		cout << endl << this->isdn << endl;
	}
	void setIsdn(){
		int isdn;
		cout << endl << "set Isdn of book " << endl;
		cout << endl << "input Isdn of the Book" << endl;
		cin >> isdn;
		this->isdn = isdn;
	}	
	void getTitle(){
		cout << endl << "get Title of book " << endl;
		cout << endl << this->title << endl;
	}
	void setTitle(){
		string c;
		cout << endl << "set Tittle of book " << endl;
		cout << endl << "input Title of the Book" << endl;
		cin >> c;
		this->title = c;
	}
	void setAutor(){
		string c;
		cout << endl << "set Autor of book" << endl;
		cout << endl << "input Autor of book " << endl;
		cin >> c;
		this->autor = c;
	}
	void getAutor(){
		cout << endl << "get Autor of book" << endl;
		cout << endl << this->autor << endl;
	}
};


