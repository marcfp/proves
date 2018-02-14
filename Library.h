/*      
                                 
 9. Create a Library class. Include vectors of Books and Patrons. Include a struct called
 Transaction. Have it include a Book, a Patron, and a Date from the chapter. Make a vecto
 Transactions. Create functions to add books to the library, add patrons to the library, 
 out books. Whenever a user checks out a book, have the library make sure that both the u
 the book are in the library. If they aren’t, report an error. Then check to make sure th
 owes no fees. If the user does, report an error. If not, create a Transaction, and place
 vector of Transactions. Also write a function that will return a vector that contains th
 of all Patrons who owe fees.            
                                       
 */    


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
 
         }
	 void add_Patrons(){
		cout << endl << "Add patrons to library" << endl;

	 }
	
 };

