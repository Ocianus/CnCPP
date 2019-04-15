#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Person {
public:
    string firstName, lastName, address, phoneNumber;
};

class Book {
public:
    string isbnNumber, authorfn, authorln, title, publishYear, pages;

    void addBook() {
        Book book;
        string line;
        ofstream books("books.txt", std::ios_base::app);

        cout << "Welcome to registration for books. Please enter the values of the book you wish"
                "to add to the shelf." << endl;

        while (books) {
            cout << "Enter 0 if you no longer wish to add more books,"
                    "if you wish to proceed adding a new book press any key: " << endl;
            getline(cin, line);
            if (line == "0") {
                break;
            }
            cout << "Enter title of the book> " << endl;
            getline(cin, title);
            cout << "Enter ISBN number> " << endl;
            getline(cin, isbnNumber);
            cout << "Enter first name of author (no middle name)> " << endl;
            getline(cin, authorfn);
            cout << "Enter the last name of the author (no middle name): " << endl;
            getline(cin, authorfn);
            cout << "Enter the number of pages: " << endl;
            getline(cin, pages);
            cout << "Enter the year the book was published: " << endl;
            getline(cin, publishYear);

            books << title << " " << isbnNumber << " " << authorfn << " " << authorln << " " << pages << " " << publishYear << endl;
            cout << "Book successfully added!" << endl;
        }
        books.close();
        ifstream fin("books.txt");

        cout << "Do you wish to list all the books in the system? If so enter 1"
                ", if not enter 0 to exit";

        getline(cin, line);
        if (line == "1") {
            while (fin) {
                getline(fin, line);
                cout << line << endl;
            }
            fin.close();
        } else {
            cout << "You chose to not list any books. Have a nice day." << endl;
        }
    }

    void listBooks() {
        ifstream books("books.txt");
        if(!books) {
            cerr << "Unable to open the file books.txt";
            exit(1);
        }

        if(books.is_open()) {
            cout << "Title - ISBN - Author - Pages - Publish date" << endl;
            cout << books.rdbuf();
        }
    }

    void removeBook() {
        string title, intitle, isbn, authorfn, authorln, pages, publishYear;
        int x = 0;

        ifstream books("books.txt");
        ofstream temp("temp.txt");

        cout << "Enter name of the book you want to erase from database >" << endl;
        cin >> intitle;

        while(books >> title >> isbn >> authorfn >> authorln >> pages >> publishYear) {
            if(intitle!=title) {
                temp << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages << ' ' << publishYear << endl;
            } if(intitle==title) {
                x = 1;
            }
        }

        books.clear();
        books.seekg(0, ios::beg);
        books.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
        if(x==0) {
            cout << "There is no book with the name you entered." << endl;
        } else {
            cout << "Book data has been deleted!" << endl;
        }
    }
};

class Librarian: public Person {
public:
    string startDate, libraryName;

    void makeLibrarian() {
        Librarian librarian1;
        string line;
        ofstream librarianw("librarian.txt", std::ios_base::app);

        cout << "Welcome to registration. Please fill in the information below: " << endl;

        while(librarianw) {
            cout << "Enter 0 if you no longer wish to add more members,"
                    "if you wish to proceed adding new member press any key: " << endl;
            getline(cin, line);
            if(line == "0") {
                break;
            }
            cout << "Enter the librarian's first name > " << endl;
            getline(cin, firstName);
            cout << "Enter the librarian's last name > " << endl;
            getline(cin, lastName);
            cout << "Enter the librarian's address > " << endl;
            getline(cin, address);
            cout << "Enter the librarian's phone number > " << endl;
            getline(cin, phoneNumber);
            cout << "Enter the name of the city the library the employee will be working at is located > " << endl;
            getline(cin, libraryName);

            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            librarian1.startDate = asctime(ti);
            librarianw << firstName << " " << lastName << " " <<  address << " " << phoneNumber << " " << libraryName << " " << librarian1.startDate;
            cout << "Librarian successfully added!" << endl;
        }
        librarianw.close();
        ifstream librarianr("librarian.txt");

        cout << "Do you wish to list all the librarians? If so enter 1"
                ", if not enter 0 to exit > ";
        getline(cin, line);
        if (line == "1") {
            while(librarianr) {
                getline(librarianr, line);
                cout << line << endl;
            }
            librarianr.close();
        } else {
            librarianr.close();
            cout << "You chose to not list any librarians. Have a nice day." << endl;
        }
    }

    void listLibrarians() {
        ifstream fout("librarian.txt");
        if(!fout) {
            cerr << "Unable to open the file librarian.txt";
            exit(1);
        }

        if(fout.is_open()) {
            cout << "First and last name - Address - Phone number - Date hired" << endl;
            cout << fout.rdbuf();
        }
    }

    void removeLibrarian() {
        string name, fname, lname, phone, address1, address2, date1, date2, date3, date4, date5, date6, date7;
        int x = 0;

        ifstream librarian("librarian.txt");
        ofstream temp("temp.txt");

        cout << "Enter name of the librarian you want to erase from database >" << endl;
        cin >> fname;

        while(librarian >> name >> lname >> phone >> address1 >> address2 >> date1 >> date2 >> date3 >> date4 >> date5 >> date6 >> date7) {
            if(fname!=name) {
                temp << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                     << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ' << date6 << ' ' << date7 <<endl;
            } if(fname==name) {
                x = 1;
            }
        }

        librarian.clear();
        librarian.seekg(0, ios::beg);
        librarian.close();
        temp.close();
        remove("librarian.txt");
        rename("temp.txt", "librarian.txt");
        if(x==0) {
            cout << "There is no librarian with the name you entered." << endl;
        } else {
            cout << "Librarian data has been deleted!" << endl;
        }
    }
};

class Member: public Person {
public:
    string registrationDate, memberID;

    void makeMember() {
        Member member1;
        ofstream fout;
        string line;

        fout.open("member.txt", std::ios_base::app);
        cout << "Welcome to registration for members. Please fill in your personal information below: " << endl;

        while(fout) {
            cout << "Enter 0 if you no longer wish to add more members,"
                    "if you wish to proceed adding a new member press any key: " << endl;
            getline(cin, line);
            if(line == "0") {
                break;
            }
            cout << "Enter the members first name: " << endl;
            getline(cin, firstName);
            cout << "Enter the members last name: " << endl;
            getline(cin, lastName);
            cout << "Enter the members address: " << endl;
            getline(cin, address);
            cout << "Enter the members phone number: " << endl;
            getline(cin, phoneNumber);

            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            member1.registrationDate = asctime(ti);
            fout << firstName << " " <<  lastName << " " << address << " " << phoneNumber  << " " << member1.registrationDate;
            cout << "Member successfully added!" << endl;
        }
        fout.close();
        ifstream fin;
        fin.open("member.txt");

        cout << "Do you wish to list all the members? If so enter 1"
                ", if not enter 0 to exit";
        getline(cin, line);
        if(line == "1") {
            while (fin) {
                getline(fin, line);
                cout << line << endl;
            }
            fin.close();
        } else {
            cout << "You chose to not list any members. Have a nice day." << endl;
            fin.close();
        }
    }

    void listMembers() {
        ifstream fout;
        fout.open("member.txt");
        if(!fout) {
            cerr << "Unable to open the file member.txt";
            exit(1);
        }

        if(fout.is_open()) {
            cout << "First and last name - Address - Phone number  - Date registered" << endl;
            cout << fout.rdbuf();
        }
    }

    void removeMember() {
        string name, fname, lname, phone, address1, address2, date1, date2, date3, date4, date5;
        int x = 0;

        ifstream member("member.txt");
        ofstream temp("temp.txt");

        cout << "Enter name of the member you want to erase from database >" << endl;
        cin >> fname;

        while(member >> name >> lname >> phone >> address1 >> address2 >> date1 >> date2 >> date3 >> date4 >> date5) {
            if(fname!=name) {
                temp << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                     << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 <<endl;
            } if(fname==name) {
                x = 1;
            }
        }

        member.clear();
        member.seekg(0, ios::beg);
        member.close();
        temp.close();
        remove("member.txt");
        rename("temp.txt", "member.txt");
        if(x==0) {
            cout << "There is no member with the name you entered." << endl;
        } else {
            cout << "Member data has been deleted" << endl;
        }
    }
};

class BookHandler {
public:
    string fname, name, lname, phone, address1, address2, date1, date2, date3, date4, date5;
    string title, isbn, authorfn, authorln, pages, publishYear;
    string search, line, registrationDate;
    int x = 0;

    void loanBook() {
        BookHandler bookHandler;
        ifstream finbook("books.txt"), fin("books.txt"), finmember("member.txt");
        ofstream fout("loanedBooks.txt", std::ios_base::app), temp("temp.txt");

        string element1;
        bool exists = false;
        int y = 0, offset, choice, length;

        fin.seekg(0, ios::end);
        length = fin.tellg();

        if(length == 0) {
            cout << "There is currently no books available at the library at the current time. Please come back later." << endl;
            exit(1);
        }

        cout << "Enter the title of the book you wish to rent> " << endl;
        cin >> search;

        while (!finbook.eof()) {
            getline(finbook, line);
            if ((offset = line.find(search, 0)) != string::npos) {
                cout << "The book '" << search << "' has been found!" << endl;
                exists = true;
            }
        }

        if (!exists) {
            cout << "No book with the title you've entered was found!" << endl;
        }

        while (exists) {
            cout << "Do you wish to rent the book? Type 1 if you wish to rent it, 0 if not" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter your first and last name if you're a member> " << endl;
                    cin >> fname;
                    cin >> lname;

                    while (finmember >> name >> lname >> phone >> address1 >> address2 >> date1 >> date2 >> date3
                                     >> date4 >> date5) {
                        if (fname == name) {
                            y = 1;
                            fout << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                                 << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << " | ";
                        }
                        if (fname == name) {
                            x = 1;
                        }
                    }

                    if (y == 1) {
                        while (fin >> title >> isbn >> authorfn >> authorln >> pages >> publishYear) {
                            if (search == title) {
                                time_t tt;
                                struct tm *ti;
                                time(&tt);
                                ti = localtime(&tt);
                                bookHandler.registrationDate = asctime(ti);
                                fout << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages
                                     << ' ' << publishYear << ' ' << " | Loaned from: " << bookHandler.registrationDate << endl;
                            }

                            if(search != title) {
                                temp <<  title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages
                                     << ' ' << publishYear;
                            }

                            if (search == title) {
                                x = 1;
                            }
                        }
                    }

                    fin.clear();
                    fin.seekg(0, ios::beg);
                    fin.close();
                    finbook.close();
                    finmember.close();
                    fout.close();
                    temp.close();
                    remove("books.txt");
                    rename("temp.txt", "books.txt");

                    if (x == 0) {
                        cout << "Name or title not found, try again!" << endl;
                    } else {
                        cout << "Name and title found, the loan has been completed!" << endl;
                    }
                    exists = false;
                    break;
                case 0:
                    cout << "You chose to not rent a book, you will be redirected back now.." << endl;
                    exit(1);
                default:
                    break;
            }
        }
    }

    void deliverBook() {
        int offset, choice;
        fstream frwbooks("books.txt", std::ios_base::app), frwloans("loanedBooks.txt"), loans("loanedBooks.txt");
        ifstream finmember("member.txt");
        ofstream temp("temp.txt");
        bool memberExists = false;
        string element1, element2, element3, element4, element5, element6, element7, element8;

        cout << "Hello, what is the title of the book would you like to deliver? >" << endl;
        cin >> title;

        bool bookExists = false;

        while (!frwloans.eof()) {
            getline(frwloans, line);
            if ((offset = line.find(title, 0)) != string::npos) {
                cout << "The book '" << title << "' has been found!" << endl;
                bookExists = true;
            }
        }

        if (!bookExists) {
            cout << "There is no book with the title '" << title
                 << "' currently loaned by anyone. Are you sure you typed the title correct?" << endl;
            //exit(1);
        }

        while (bookExists) {
            int userInput;
            cout << "All data has been found, do you wish to complete the retun? Press 1 if yes, 0 if no `>" << endl;
            cin >> userInput;
            switch (userInput) {
                case 1:
                    cout << "Enter your first and last name> " << endl;
                    cin >> fname;
                    cin >> lname;

                    while (loans >> name >> lname >> address1 >> address2 >> phone >> date1 >> date2 >> date3 >> date4
                                    >> date5 >> title >> isbn >> authorfn >> authorln >> pages >> publishYear
                                    >> element1 >> element2 >> element3 >> element4 >> element5 >> element6 >> element7
                                    >> element8) {
                        if (fname != name) {
                            temp << name << ' ' << lname << ' ' << address1 << ' ' << address2 << ' ' << phone << ' ' << date1
                                 << ' ' << date2 << ' ' << date3 << ' '
                                 << date4 << ' ' << date5 << ' ' << title << ' ' << isbn << ' ' << authorfn
                                 << ' ' << authorln << ' ' << pages << ' '
                                 << publishYear << ' ' << element1 << ' ' << element2 << ' ' << element3 << ' ' << element4
                                 << ' ' << element5 << ' ' << element6 << ' ' << element7 << ' ' << element8;
                        }
                        if (fname == name) {
                            frwbooks << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages << ' ' << publishYear << endl;
                            x = 1;
                        }
                    }

                    frwloans.clear();
                    frwloans.seekg(0, ios::beg);
                    frwloans.close();
                    loans.close();
                    temp.close();
                    frwbooks.close();
                    remove("loanedBooks.txt");
                    rename("temp.txt", "loanedBooks.txt");

                    if (x == 0) {
                        cout << "An error occoured while attempting to return the book. Please try again!" << endl;
                    } else {
                        cout << "The book has been successfully returned! Have a nice day!" << endl;
                    }
                    break;
                case 0:
                    cout << "You chose to not return the book, you will be redirected back now.." << endl;
                    break;
                default:
                    break;
            }
            break;
        }
    }

    void listCurrentLoans() {
        ifstream loaned("loanedBooks.txt");
        if(!loaned) {
            cerr << "Unable to open the file loanedBooks.txt";
            exit(1);
        }

        if(loaned.is_open()) {
            cout << "First and last name - Address - Phone number - Date og registration - Title - ISBN - Author - Pages - Publish Year - Date loaned " << endl;
            cout << loaned.rdbuf();
        }
    }
};

int main() {
    Member member1;
    //member1.makeMember();
    //member1.removeMember();
    //member1.listMembers();

    Librarian librarian;
    //librarian.makeLibrarian();
    //librarian.listLibrarians();
    //librarian.removeLibrarian();

    Book book;
    //book.addBook();
    //book.removeBook();
    //book.listBooks();

    BookHandler bookHandler;
    bookHandler.loanBook();
    //bookHandler.deliverBook();
    //bookHandler.listCurrentLoans();
    return 0;
}
