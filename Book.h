#include <iostream>
#include <ctime>
#include <string>
#include <sstream>


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
	int febrer;
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

/*		month = months[time->tm_mon];
                day = days[time->tm_wday];
                year = time->tm_year + BASE_YEAR;
*/
        }

	int setDay(int i, int j){
		int dia=0;
		if(j==31) {
			while(dia<1 || dia > 31) {
				cout << endl << "Mes de gener, març, maig, juliol,agost, octubre i desembre" << endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
				cin >> dia;
			}
//						1	3	5	7  8	10	12
		}
		else if(j==30){
			while(dia<1 || dia > 31) {
				cout << endl << "Mes d'abril, juny, setembre, novembre " << endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
                                cin >> dia;
			}
		}
		else { 
			while(dia<1 || dia > febrer) {	
				cout << endl << "més de febrer ?"<< endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
				cin >> dia;
			}
		}
		
	}
	int setMonth1(int traspas){
		int mes;
		cout << endl << "traspas = " << traspas << endl;
		do {
			cout << endl << "Entra el mes de l'any que demanes aquest llibre " << endl;
			cin >> mes;
		}while(mes<1 || mes >12);
		cout << "Número de mes k has escollit " << mes << endl;
		switch (mes)
		{
			case 1:case 3: case 5: case 7 : case 8:  case 10 : case 12 :	
				this->setDay(1, 31);
				break;
			case 4: case 6: case 11: 
				this->setDay(1,30);
				break;
			case 2: 
				this->setDay(1,febrer);
				break;
			default: cout << endl << "mes erroni " << endl;
				break;
		}	
	}
	int setYear(){
		int any;
		
		cout << endl << "Entra l'any que demanes aquest llibre" << endl;
		cin >> any;
		if(any%4==0 && any%100!=0){ 
				cout << endl << " any de traspàs" << endl;
				febrer=29;
				//return(0);
				this->setMonth1(febrer);
		}
		else {
			if(any%400==0 ){ 
					cout << endl << " any de traspàs" << endl; 
					febrer=29;
					//return(0);
					this->setMonth1(febrer);
			}

			else {	
				cout << endl << "NORMAL" << endl;
				febrer=28;
				//return(1);
				this->setMonth1(febrer);
			}
		}
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
	string isdn;
	string title;
	string autor;
	Date date;
	bool checked;

	void setChecked (){
		bool check=-1;
		while (check<0 || check>1) {
			cout << endl << "S'ha deixat el llibre ?(1 si, 0 no)" << endl;
			cin >> check;
		}
		this->checked = check;
	}

	int getChecked(){
		return(this->checked);
	}	

	void getAny(){
		cout << endl << "Aquest és any és de traspàs ?" << endl;
		
	}

	string getsIsdn(){
		return(this->isdn);
	}
	void getIsdn(){
		cout << endl << "get Isdan of book " << endl;
		cout << endl << this->isdn << endl;
	}
	
	string IntToString (int a)
	{
	    ostringstream temp;
	    temp<<a;
	    return temp.str();
	}	

	void setIsdn(){
		string isdn;
		cout << endl << "set Isdn of book " << endl;
		cout << endl << "input Isdn of the Book" << endl;
		cin >> isdn;
		this->isdn = isdn; //IntToString(isdn);
	//	this->isdn = to_string(isdn);
	}	
	void getTitle(){
		cout << endl << "get Title of book " << endl;
		cout << endl << this->title << endl;
	}
	void setTitle(){
		char titol[512];
		cout << endl << "set Tittle of book " << endl;
		cout << endl << "input Title of the Book" << endl;
		cin.getline(titol,512);
		cout << endl << "titol llegit = " << titol << endl;
		this->title = titol;
		cout << endl << "carrego titol a this->title = " << this->title << endl;
	}
	void setAutor(){
		char autor[512];
		cin.clear();
		cout << endl << "set Autor of book" << endl;
		cout << endl << "input Autor of book " << endl;
		cin.ignore(512,'\n');
		cin.getline(autor,512);
		this->autor = autor;
	}
	void getAutor(){
		cout << endl << "get Autor of book" << endl;
		cout << endl << this->autor << endl;
	}
};


