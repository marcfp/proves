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
			diat=dia;
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
			diat=dia;
		}
		else { 
			while(dia<1 || dia > febrer) {	
				cout << endl << "més de febrer ?"<< endl;
				cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
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
			diat=dia;
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
		mest=mes;
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
		anyt=any;
		if(any%4==0 && any%100!=0){ 
				cout << endl << " any de traspàs" << endl;
				febrer=29;
				setMonth1(febrer);
		}
		else {
			if(any%400==0 ){ 
					cout << endl << " any de traspàs" << endl; 
					febrer=29;
					setMonth1(febrer);
			}

			else {	
				cout << endl << "NORMAL" << endl;
				febrer=28;
				setMonth1(febrer);
			}
		}
	}	

	int printDate(){
		cout << endl << "dia =" << this->day << "this->diat =" << this->diat << "this->month =" << this->month << " (linea 142)this->year = " << this->anyt << endl; 
		return (0);
        }

	void getDate(){
		cout << "diat = " << diat << ", mest = " << mest << ", year =" << anyt << endl;
	}
  
	int getDia(){
		return(diat);
	}
	
	int getMes(){
		return(mest);
	}

	string getMesString(){
		switch(mest){
			case 1: return("Gener");break;
			case 2: return("Febrer");break;
			case 3: return("Març");break;
			case 4: return("Abril");break;
			case 5: return("Maig"); break;
			case 6: return("Juny");break;
			case 7: return("Juliol");break;
			case 8: return("Agost"); break;
			case 9: return("Setembre"); break;
			case 10: return("Octubre"); break;
			case 11: return("Novembre"); break;
			case 12: return ("Desembre"); break;
			default : return("error!!!!"); break;
		}
		return("error!!!!");
	}
	int getAny(){
		return(anyt);
	}
        // Destructor
        ~Date() {}

};
class Patron {
public:
	string nom_user;
	unsigned long tarjeta_credit;
	int gastos_administratius;	


	void llegir_digit(string &valor, unsigned long &tarajeta_credit){
                locale loc;
                bool b=false;
                while(b==false){
                        cout << endl << "Entra el número de tarjeta" << endl;
                        cin >> valor; //tarjeta_credit;
                        if(isdigit(valor[0],loc) && isdigit(valor[1],loc)&& isdigit(valor[2],loc) && isdigit(valor[3],loc)&& isdigit(valor[4],loc) && isdigit(valor[5],loc)&& isdigit(valor[6],loc) && 
				isdigit(valor[7],loc)&& isdigit(valor[8],loc) && isdigit(valor[9],loc)&& isdigit(valor[10],loc) && isdigit(valor[11],loc)&& isdigit(valor[12],loc) && isdigit(valor[13],loc)
				&& isdigit(valor[14],loc) && isdigit(valor[15],loc)){
                        //tarjeta_credit)) {
                                stringstream(valor) >> tarjeta_credit; //= atoi(valor);
				cout << endl << fixed << "tarjeta_credit = " << tarjeta_credit << endl << "valor.length()= " << valor.length() << endl;
                                b=true;
                        }
			if(valor.length()!=16){
				b=false;
				cout << endl << "Valor massa llarg o curt, no és de 16 digits" << endl;
				}

                }

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
	
	void set_gastos_admin(){
		cout << endl << "Entra si existeixen gastos administratius " << endl;
		while(!(cin >> gastos_administratius)){
			cin.clear();
			cin.ignore();
			cout << endl << "Has d'introduir-me un número" << endl;
		}
	}
	
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

	string getGenere(){
		//cout << "this->generes = " << this->genere << endl;
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
	
/*	void getAny(){
		cout << endl << "Aquest és any és de traspàs ?" << endl;
		
	
	}
*/	
	int getsAny(){
		return(this->date.anyt);
	}
	string getsDate(){
		return(this->date.diat+" del mes "+ this->date.mest);// + " de l'any " + this->date.anyt);
	}

	string getsIsdn(){
		cout << endl << "getsIsdn() = " << this->isdn;
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
			ostringstream convert1, convert2, convert3;   // stream used for the conversion
			convert1 << isdn1;
			convert2 << isdn2;
			convert3 << isdn3;
			tot =  convert1.str()+convert2.str()+convert3.str()+isdn4;
			cout << endl << "tot = " << tot << endl;
				//to_string(isdn1) +  to_string(isdn2) +  to_string(isdn3) + isdn4;
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
	 Book book;
         Date date;
         vector<Book> vbooks;//libres
         vector<Patron> vpatrons;//clients
         vector<Transaction> vtransactions;//per controlar els llibres deixats i els llibres que hi ha a la llibreria 
	 
	void push_back()
	 {	
		char c=' ';	
		Book book;
		while(c!='n' && c!='N'){
			book.setIsdn();
			string isdn=book.getsIsdn();
	                string surt="-1"; 
	                if(isdn.find(surt) == string::npos) { //si no troba -1
			 	book.setGenere();	
				book.setAutor();
				book.setTitle();
				book.setChecked();
//				cout << "getchecked = " << book.getChecked();
				if(book.getChecked()==1){ //si deixat, demana això
					book.date.setYear();
					book.p.setNomUser();
					book.p.set_tarjeta();
				}
				else {
					cout << endl << "llibre no deixat" << endl;
				}
				vbooks.push_back(book);
			
//				cout << endl << "push_back(Book *x)\n autor = " << vbooks[0].getAutor() << "\n getTitle = " << vbooks[0].getTitle() << "\n Isdn =" << vbooks[0].getsIsdn() <<  endl;
				cout << endl << "Vols introduir més llibres ?(n o N per sortir)"<< endl;
				cin >> c;
			}
			else throw invalid_argument("Argument invàlid, fora!");
		}
	 }
         
	void add_Books(){
		//char s='k';
                cout << endl << "Add books to library " << endl;
		cout << endl << "vbooks.size() =" << vbooks.size() << " isdn = " << vbooks[0].getsIsdn() << endl; //Els estic afegint, falta saber com recora-ho
		if(vbooks.size()>=1){
			for(int i=0; i<vbooks.size(); i++){
			if(vbooks[i].getChecked()!=0) cout << "La llibreria conté el llibre amb l'ISDN " << vbooks[i].getsIsdn() << " que és de l'autor " << vbooks[i].getAutor() << " i té el títol " << vbooks[i].getTitle() << /*".Aquest llibre és del gènere " << vbooks[i].getGenere(); // vbooks[i].getGenere(); <<*/ " i és en prestec de l'any : " << vbooks[i].getsAny() << ", del mes : " << vbooks[i].date.getMes() << ", que és el mes de " << vbooks[i].date.getMesString() << ", del dia :" << vbooks[i].date.getDia() << ".\n" <<  endl; 
				else cout << "La llibreria conté el llibre amb l'ISDN " << vbooks[i].getsIsdn() << " que és de l'autor " << vbooks[i].getAutor() << " i té el títol " << vbooks[i].getTitle() << endl;
	//			cout << vbooks[i].getsIsdn() << vbooks[i].getTitle() << endl;
			}
		}
		//vtbooks.push_back(s);
//		vbooks.push_back(Book()); //falta afegir ?n
//		vbooks[0].autor.push_back('b');
//="vbook";
	//	cout << "vbook[0].autor.length() = " << vbook[0].autor.length() << endl;
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
	//	vbook.push_back(Book());
		/*
			string nom_user;
		        int tarjeta_credit;
		        int gastos_administratius;
		*/
//		vpatron.push_back("patron",1,1);
		/* He de fer setters ? */
         }
	
	~Library(){}

 };

