#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
/*string months[] = {"Gen", "Feb", "Mar", "Abr", "Mai", "Jun",

                        "Jul", "Agt", "Set", "Oct", "Nov", "Dec"};

string days[] = {"Diu", "Dll", "Dmt", "Dmc", "Dj", "Dv",

                      "Dss"};

*/
/*

9. Create a Library class. Include vectors of Books and Patrons. Include a struct called
Transaction. Have it include a Book, a Patron, and a Date from the chapter. Make a vector of
Transactions. Create functions to add books to the library, add patrons to the library, and check
out books. Whenever a user checks out a book, have the library make sure that both the user and
the book are in the library. If they aren’t, report an error. Then check to make sure that the user
owes no fees. If the user does, report an error. If not, create a Transaction, and place it in the
vector of Transactions. Also write a function that will return a vector that contains the names
of all Patrons who owe fees.

*/


class Date{
// Private Members
//    private:
	//ha de ser public per accedir des del pare ?
	public:
        string month;
        string day;
//	int month;
//	int day;
        int diat;
        int anyt;
	int mest;
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
		diat = time->tm_mday;

        }

	int setDay(int i, int j){
		int dia=0;
		if(j==31) {
			while(dia<1 || dia > 31) {
				cout << endl << "Mes de gener, març, maig, juliol,agost, octubre i desembre" << endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
				while(!(cin >> dia)){
					if(cin.fail()){
						cin.clear();
						cin.ignore();
						cout << endl << "Error d'introducció.... El dia ha de ser un número entre 1 i 31!!!!" << endl;
					}
					else{
						diat=dia;
					}
				}
			}
		}
		else if(j==30){
			while(dia<1 || dia > 31) {
				cout << endl << "Mes d'abril, juny, setembre, novembre " << endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
                                while(!(cin >> dia)){
					if(cin.fail()){
						cin.clear();	
						cin.ignore();
						cout << endl << "Error d'introducció.... El dia ha de ser un número entre 1 i 30!!!!" << endl;
					}
					else{
						diat=dia;
					}
				}
			}
		}
		else { 
			while(dia<1 || dia > febrer) {	
				cout << endl << "més de febrer ?"<< endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
//				cin >> dia;
				while(!(cin >> dia)){
					if(cin.fail()){
						cin.clear();
						cin.ignore();
						cout << endl << "Error d'introducicó... el dia ha de ser un número entre 1 i " << febrer << "!!!!"<< endl;
					}
					else{
						diat=dia;
					}
				}
			}
		}
		return(dia);
		
	}

	int setMonth1(int traspas){
		int mes;
		cout << endl << "traspas = " << traspas << endl;
		do {
			cout << endl << "Entra el mes de l'any que demanes aquest llibre " << endl;
			while(!(cin >> mes)){
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << endl << "Error d'introducció... El més ha de ser un nombre de l'1 al 12!!!!" << endl;
				}
				else{	
					mest=mes;
				}
			}
		}while(mes<1 || mes >12);
		cout << "Número de mes k has escollit " << mes << endl;
		switch (mes)
		{
			case 1:case 3: case 5: case 7 : case 8:  case 10 : case 12 :	
				setDay(1,31);
				break;
			case 4: case 6: case 11: 
				setDay(1,30);
				break;
			case 2: 
				setDay(1,febrer);
				break;
			default: cout << endl << "mes erroni " << endl;
				break;
		}	
	}
	
	int setYear(){
		int any;
		
		cout << endl << "Entra l'any que demanes aquest llibre" << endl;
		while(!(cin >> any)){
			if(cin.fail()){
                        	cin.clear();
                                cin.ignore();
                                cout << endl << "Error d'introducció... L'any ha de ser un nombre!!!" << endl;
 
                        }
			else {
				anyt=any;
			}
		}
		if(any%4==0 && any%100!=0){ 
				cout << endl << " any de traspàs" << endl;
				febrer=29;
				//return(0);
				setMonth1(febrer);
		}
		else {
			if(any%400==0 ){ 
					cout << endl << " any de traspàs" << endl; 
					febrer=29;
					//return(0);
					setMonth1(febrer);
			}

			else {	
				cout << endl << "NORMAL" << endl;
				febrer=28;
				//return(1);
				setMonth1(febrer);
			}
		}
	}	

	int printDate(){
//		this -> day = this -> day;
//		this -> diat = this -> date;
//		this -> month = this -> month;
//		this -> year = this -> year;
		cout << endl << "dia =" << this->day << "this->diat =" << this->diat << "this->month =" << this->month << " (linea 142)this->year = " << this->anyt << endl; 
		return (0);
        }
	void getDate(){
		cout << "diat = " << diat << ", mest = " << mest << ", year =" << anyt << endl;
	}
        // Destructor
        ~Date() {}

};
class Patron {
public:
	string nom_user;
	int tarjeta_credit;
	int gastos_administratius;	


	void llegir_digit(string &valor, int &tarajeta_credit){
                locale loc;
                bool b=false;
                while(b==false){
                        cout << endl << "Entra el número de tarjeta" << endl;
                        cin >> valor; //tarjeta_credit;
                        if(isdigit(valor[0],loc)){
                        //tarjeta_credit)) {
                                stringstream(valor) >> tarjeta_credit; //= atoi(valor);
				cout << endl << "tarjeta_credit = " << tarjeta_credit << endl;
                                b=true;
                        }

                }

	}

	void llegir_lletra(string &valor, string &nom_user){
/*
		http://www.cplusplus.com/reference/cctype/isalpha/
		http://www.cplusplus.com/reference/locale/isalnum/
		http://www.cplusplus.com/reference/locale/isdigit/
*/
	}

	void setNomUser(){
		cout << endl << "Entra el nom d'usuari que s'ha deixat el llibre" << endl;
		cin >> nom_user;
	}
	string getNomUser(){
		return (this->nom_user);
	}
	void set_tarjeta(){
		string valor;
		
		llegir_digit(valor,tarjeta_credit);
	}	
	double get_tarjeta(){
		return(this->tarjeta_credit);
	}
	/*int*/
	void set_gastos_admin(){
		cout << endl << "Entra si existeixen gastos administratius " << endl;
		while(!(cin >> gastos_administratius)){
			cin.clear();
			cin.ignore();
			cout << endl << "Has d'introduir-me un número" << endl;
		}
//		return(gastos_administratius);
	}
/*	int set_gastos_admin()	{
		cout << endl << "Entra els gastos d'administració " << endl;
		cin >> gastos_administratius;
		
		return(this->gastos_administratius);
	}
*/
	string get_gastos_admin() {
		return ("Els gastos d'administració d'aquest llibre són " + this->gastos_administratius) ;
	}
	bool si_no_gastos_admin(){
		int i=-1;
		while(i<0 || i>1){
			cout << endl<< "Té gastos administratius ?(0 no, 1 si)" << endl;
			while(!(cin >> i)){
				cin.clear();
				cin.ignore();
				cout << endl << "Has d'introduir un 1 o un 0" << endl;
			}
		}
		cout << endl << " i = " << i << endl;
		if(i==1) return true; 
		else {
			cout << endl << "sense gastos d'aministració?" << endl;
			return false;
		}
		
	}
	~Patron() {}
};
class Book {
  public:
    //setters
	string isdn;
	string title;
	string autor;
	Date date;
	Patron p;
	bool checked;
	enum Genere{ nonfiction=1, periodical=2, biography=3, children=4, error=5 } genere; //store genere
	
	void setGenere(){
		int genere_escollit =-1;
		bool entrat=false;
		while((genere_escollit<1 || genere_escollit>4)&& entrat==false)
		{
			cout << endl << "Quin genere esculls ? (1..4)" << endl;
			cin >> genere_escollit;
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Input error... Program needs numbers!";
				
			} 
			else {
				if(genere_escollit>0 && genere_escollit<5){
					 entrat=true;
				}
				else {
					cout << endl << "Aquí hi ha hagut algun erro,r comproba-ho" << endl;
				}
			}
		} 
		cout << "genere escollit = " << genere_escollit;
		switch(genere_escollit)
		{	
			case 1: this->genere=nonfiction;break;
			case 2: this->genere=periodical;break;
			case 3: this->genere=biography;break;
			case 4: this->genere=children;break;
			default: this->genere=error;break;
		}
	}

	void getGenere(){
		cout << "this->generes = " << this->genere << endl;
		switch(this->genere)
		{
			case 1: cout << endl << "Aquest llibre pertan a la no ficció" << endl ; break;
			case 2: cout << endl << "Aquest llibre pertan al genere \"periodical\"" << endl ; break;
			case 3: cout << endl << "Aquest llibre pertan al gènere de \"biography\"" << endl ; break;
			case 4: cout << endl << "Aquest llibre pertan al gènere de \"children\"" << endl ; break;
			case 5: cout << endl << "Aquí hi ha algún error, comproba-ho" << endl; break;
			
		}
	}

	void setChecked (){
		int check=-1;
		bool entrat=false;
		while ((check<0 || check>1)&& entrat==false)
		{
			cout << endl << "S'ha deixat el llibre ?(1 si, 0 no)" << endl;
			while(!(cin >> check)){
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Has d'entrar un 1 o un 0, gràcies";
			}
		}	
		this->checked = check;
	}

	int getChecked(){
		cout << "checked = " << this->checked << endl;
		return ((int)this->checked);
	}	
	
	void getAny(){
		cout << endl << "Aquest és any és de traspàs ?" << endl;
		
	}

	string getsIsdn(){
		return(this->isdn);
	}
	void getIsdn(){
		cout << endl << "get Isdn of book " << this->isdn << endl;
	}
	
	void setIsdn(){
		int isdn1=-1;
		int isdn2=-1;
		int isdn3=-1;
		string isdn4="-1";
		bool correcte=false;
		string tot;
		cout << endl << "set Isdn of book " << endl;
		cout << endl << "input Isdn of the Book like : \"number number number (letter or number)\"" << endl;
		while(correcte==false){
			cin >> isdn1 >>  isdn2 >>  isdn3 >>  isdn4 ;
			tot =  to_string(isdn1) +  to_string(isdn2) +  to_string(isdn3) + isdn4;
			if(isdn1!=-1 && isdn2!=-1 && isdn3!=-1 && isdn4!="-1") correcte=true;
			else{
				cout << "ISDN " << tot << " entrat per sortir, surtint del programa" << endl;
				break;
			}
		}
		this->isdn = tot;
	}	
	
	string getTitle(){
		return ( this->title);
	}
	
	void setTitle(){
		char titole[512];
		//cout << endl << "set Tittle of book " << endl;
		cout << endl << "Input Title of the Book" << endl;
		cin.getline(titole,128);
		//cout << endl << "titol llegit = " << titole << endl;
		this->title = titole;
		//cout << endl << "carrego titol a this->title = " << this->title << " i title = " << title << endl;
	}

	void setAutor(){
		char autore[512];
		cin.clear();
		//cout << endl << "set Autor of book" << endl;
		cout << endl << "input Autor of book " << endl;
		cin.ignore(512,'\n');
		cin.getline(autore,128);
//		if(cin.fail) throw 
		this->autor = autore;
		//cout << endl << "carrego auto a this->autor = " << this->autor << " i autor = " << autor << endl;
	}

	string getAutor(){
//		cout << endl << "this->autor :" << this->autor << endl << " autor = " << autor  << endl;
		return (this->autor);
	}
	~Book() {}

};

	 ostream & operator << (ostream & os,  Book& book) //print
         {
                 cout << endl << "Imprimeix ISDN ="<< book.getsIsdn() << endl ;
		cout << "title = " << book.getTitle() << endl;
		cout << "autor = " << book.getAutor() << endl;
		 
         }
 
         ostream & operator == (Book & book1, Book & book2) // iguals?
         {
                 cout << endl << "Són iguals els isdn? " << endl;
		 string b1=book1.getsIsdn();
		string b2=book2.getsIsdn();
		if(b1.compare(b2) !=0) cout << "Els isdn són diferents" << endl;
		else cout << " L'isdn és el mateix dels dos llibres "<< endl;
         }

	ostream & operator != (Book & book1, Book & book2) // iguals?
        {
                cout << endl << "Són diferents els isdn? " << endl;
                string b1=book1.getsIsdn();
                string b2=book2.getsIsdn();
                if(b1.compare(b2) !=0) cout << "Els isdn són diferents" << endl;
                else cout << " L'isdn és el mateix dels dos llibres "<< endl;
        } 


 struct Transaction{
         Book bookt;
         Patron patront;
         Date datet;
 };



 class Library {
         public:
         Date date;
         vector<Book> vbook;
         vector<Patron> vpatron;
         vector<Transaction> vtransaction;


         void add_Books(){
                cout << endl << "Add books to library " << endl;
		/*
			string isdn;
		        string title;
		        string autor;
		        Date date;
		        Patron p;
		        bool checked;   
		        enum Genere{ nonfiction=1, periodical=2, biography=3, children=4, error=5
		*/
               //vbook.push_back("11","11","autor","1","1",1,1);
		/* He de fer setters ? */

         }
         void add_Patrons(){
         	cout << endl << "Add patrons to library" << endl;
		/*
			string nom_user;
		        int tarjeta_credit;
		        int gastos_administratius;
		*/
//		vpatron.push_back("patron",1,1);
		/* He de fer setters ? */
         }

 };

