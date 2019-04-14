#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Person {
public:
    string firstName, lastName, address, phoneNumber;
};

class Library {
public:
    string adress, libraryID, libraryName;

};

class Book {
public:
    string isbnNumber, author, title, publishYear, pages;

    void bookGetInfo() {
        cout << "Bookinformation" << endl;
        cout << "________________" << endl;
        cout << "ISBNnumber: " << isbnNumber << endl;
        cout << "Auther: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Number of pages: " << pages << endl;
        cout << "Year published: " << publishYear << endl;
    }

    void addBook() {
        Book book;
        ofstream fout;
        string line;

        fout.open("books.txt", std::ios_base::app);
        cout << "Welcome to registration. Please enter the values of the book you wish"
                "to add to the shelf " << endl;

        while (fout) {
            cout << "Enter 0 if you no longer wish to add more books,"
                    "if you wish to proceed adding new book press any key: " << endl;
            getline(cin, line);
            if (line == "0") {
                break;
            }
            cout << "Enter title of the book: " << endl;
            getline(cin, title);
            cout << "Enter ISBN number: " << endl;
            getline(cin, isbnNumber);
            cout << "Enter name of author (first and last name, no middle name): " << endl;
            getline(cin, author);
            cout << "Enter the number of pages: " << endl;
            getline(cin, pages);
            cout << "Enter the year the book was published: " << endl;
            getline(cin, publishYear);

            fout << title << " " << isbnNumber << " " << author << " " << pages << " " << publishYear << endl;
            cout << "Book successfully added!" << endl;
        }
        fout.close();
        ifstream fin;
        fin.open("books.txt");

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
        ifstream fout;
        fout.open("books.txt");
        if(!fout) {
            cerr << "Unable to open the file books.txt";
            exit(1);
        }

        if(fout.is_open()) {
            cout << "Title - ISBN - Author - Pages - Publish date" << endl;
            cout << fout.rdbuf();
        }
    }

    void removeBook() {
        string title, intitle, isbn, author, pages, publishYear;
        int x = 0;

        ifstream book("books.txt");
        ofstream temp("temp.txt");

        cout << "Enter name of the book you want to erase from database >" << endl;
        cin >> intitle;

        while(book >> title >> isbn >> author >> pages >> publishYear) {
            if(intitle!=title) {
                temp << title << ' ' << isbn << ' ' << author << ' ' << pages << ' ' << publishYear << endl;
            } if(intitle==title) {
                x = 1;
            }
        }

        book.clear();
        book.seekg(0, ios::beg);
        book.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
        if(x==0) {
            cout << "There is no book with the name you entered." << endl;
        } else {
            cout << "Book data has been deleted" << endl;
        }
    }
};


class Librarian: public Person {
public:
    string startDate, salary, libraryID;
    int employeeID = 1;

    void getLibrarianInfo() {
        cout << "Information regarding librarian" << endl;
        cout << "________________________________" << endl;
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Address: " << address << endl;
        cout << "Phone number " << phoneNumber << endl;
        cout << "Start date: " << startDate << endl;
        cout << "Salary: " << salary << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Works at library: " << libraryID << endl;
    }

    /**
     * EmployeeID fungerer ikke
     */
    void makeLibrarian() {
        int employeeID = 1;
        Librarian librarian1;
        ofstream fout;
        string line;

        fout.open("librarian.txt", std::ios_base::app);
        cout << "Welcome to registration. Please fill in the information below: " << endl;

        while(fout) {
            cout << "Enter 0 if you no longer wish to add more members,"
                    "if you wish to proceed adding new member press any key: " << endl;
            getline(cin, line);
            if(line == "0") {
                break;
            }
            cout << "Enter the librarian's first name: " << endl;
            getline(cin, firstName);
            cout << "Enter the librarian's last name: " << endl;
            getline(cin, lastName);
            cout << "Enter the librarian's address: " << endl;
            getline(cin, address);
            cout << "Enter the librarian's phone number: " << endl;
            getline(cin, phoneNumber);
            cout << "Enter the name of the city the library the employee will be working at is located " << endl;
            getline(cin, libraryID);

            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            librarian1.startDate = asctime(ti);
            fout << firstName << " " << lastName << " " <<  address << " " << phoneNumber << " " << employeeID << " " << libraryID << " " << librarian1.startDate;
            employeeID++;
            cout << "Librarian successfully added!" << endl;
        }
        fout.close();
        ifstream fin;
        fin.open("librarian.txt");

        cout << "Do you wish to list all the librarians? If so enter 1"
                ", if not enter 0 to exit";
        getline(cin, line);
        if (line == "1") {
            while(fin) {
                getline(fin, line);
                cout << line << endl;
            }
            fin.close();
        } else {
            fin.close();
            cout << "You chose to not list any librarians. Have a nice day." << endl;
        }

    }

    void listLibrarians() {
        ifstream fout;
        fout.open("librarian.txt");
        if(!fout) {
            cerr << "Unable to open the file librarian.txt";
            exit(1);
        }

        if(fout.is_open()) {
            cout << "First and last name - Address - Phone number - Employee ID - Date hired" << endl;
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
            cout << "Librarian data has been deleted" << endl;
        }
    }
};

class Member: public Person {
public:
    string memberID, registrationDate;

    void getMemberInfo() {
        cout << "Member information" << endl;
        cout << "________________" << endl;
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Phonenumber name: " << phoneNumber << endl;
        cout << "Address name: " << address << endl;
        cout << "Member ID: " << memberID << endl;
        cout << "Registration date: " << registrationDate << endl;
    }

    void makeMember() {
        int id = 1;
        Member member1;
        ofstream fout;
        string line;

        fout.open("member.txt", std::ios_base::app);
        cout << "Welcome to member registration. Please fill in the information below: " << endl;

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
            fout << firstName << " " <<  lastName << " " << address << " " << phoneNumber << " " << id << " " << member1.registrationDate;
            id++;
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
            cout << "First and last name - Address - Phone number - Member ID - Date registered" << endl;
            cout << fout.rdbuf();
        }
    }

    void removeMember() {
        string name, fname, lname, phone, address1, address2, date1, date2, date3, date4, date5, date6;
        int x = 0;

        ifstream member("member.txt");
        ofstream temp("temp.txt");

        cout << "Enter name of the member you want to erase from database >" << endl;
        cin >> fname;

        while(member >> name >> lname >> phone >> address1 >> address2 >> date1 >> date2 >> date3 >> date4 >> date5 >> date6) {
            if(fname!=name) {
                temp << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                     << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ' << date6 <<endl;
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

class Renter: public Person{
public:
    string rentTime;
    bool depositum;

    void getRenterInfo() {
        cout << "Renter information" << endl;
        cout << "____________________" << endl;
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Phonenumber name: " << phoneNumber << endl;
        cout << "Address name: " << address << endl;
        cout << boolalpha;
        cout << "Depositum: " << depositum << endl;
        time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
        rentTime = asctime(ti);
        cout << "Registered: " << rentTime << endl;
    }

    void makeRenter() {
        Renter renter1;
        ofstream fout;
        string line, depositum;

        fout.open("renter.txt", std::ios_base::app);
        cout << "Welcome to registration. Please fill in the information below: " << endl;

        while(fout) {
            cout << "Enter 0 if you no longer wish to add more renters,"
                    "if you wish to proceed adding new renter press any key: " << endl;
            getline(cin, line);
            if(line == "0") {
                break;
            }
            cout << "Enter your first name: " << endl;
            getline(cin, firstName);
            cout << "Enter your last name: " << endl;
            getline(cin, lastName);
            cout << "Enter your address: " << endl;
            getline(cin, address);
            cout << "Enter your phone number: " << endl;
            getline(cin, phoneNumber);
            /**
             * Bedre om det blir skrevet ut true eller false
             */
            cout << "Has the renter payed depositum? " << endl;
            getline(cin, depositum);

            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            renter1.rentTime = asctime(ti);
            fout << firstName << " " << lastName << " " << address << " " << phoneNumber
            << " " << depositum << " " << renter1.rentTime;
            cout << "Renter successfully added!" << endl;
        }

        fout.close();
        ifstream fin;
        fin.open("renter.txt");

        cout << "Do you wish to list all the renters? If so enter 1"
                ", if not enter 0 to exit";
        getline(cin, line);

        if(line == "1") {
            while(fin) {
                getline(fin, line);
                cout << line << endl;
            }
            fin.close();
        } else {
            cout << "You chose to not list any renter. Have a nice day." << endl;
            fin.close();
        }
    }

    void listRenters() {
        ifstream fout;
        fout.open("renter.txt");
        if(!fout) {
            cerr << "Unable to open the file renter.txt";
            exit(1);
        }

        if(fout.is_open()) {
            cout << "First and last name - Address - Phone number - Date rented" << endl;
            cout << fout.rdbuf();
        }
    }

    void removeRenter() {
        string name, fname, lname, phone, address1, address2, date1, date2, date3, date4, date5, date6;
        int x = 0;

        ifstream renter("renter.txt");
        ofstream temp("temp.txt");

        cout << "Enter name of the renter you want to erase from database >" << endl;
        cin >> fname;

        while(renter >> name >> lname >> phone >> address1 >> address2 >> date1 >> date2 >> date3 >> date4 >> date5 >> date6) {
            if(fname!=name) {
                temp << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2 << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ' << date6 <<endl;
            } if(fname==name) {
                x = 1;
            }
        }

        renter.clear();
        renter.seekg(0, ios::beg);
        renter.close();
        temp.close();
        remove("renter.txt");
        rename("temp.txt", "renter.txt");
        if(x==0) {
            cout << "There is no renter with the name you entered." << endl;
        } else {
            cout << "Renter data has been deleted" << endl;
        }
    }
};

class BookHandler {
public:

    void loanBook() {
        int offset, choice;
        ifstream finbook;
        finbook.open("books.txt");
        ifstream finmember("member.txt");
        ofstream fout("test.txt");
        string search, line, fname;

        int x = 0;
        //string strTemp, temp, test;
        string name, lname, phone, address1, address2, date1, date2, date3, date4, date5, date6;

        cout << "Enter the title of the book you wish to rent" << endl;
        cin >> search;

            while (!finbook.eof()) {
                getline(finbook, line);
                if ((offset = line.find(search, 0)) != string::npos) {
                    cout << "The book '" << search << "' has been found!" << endl;
                    cout << "Do you wish to rent the book? Type 1 if you wish to rent it, 0 if not" << endl;
                    cin >> choice;
                    switch(choice) {
                        case 1:
                            cout << "Enter your name if youre a member" << endl;
                            cin >> fname;
                           // if(finmember.is_open()) {
                               // while (!finmember.eof()) {
                                  //  getline(finmember, line);
                               //     if ((offset = line.find(fname, 0)) != string::npos) {
                                        //cout << "Member found. The book will now be registered on your name." << endl;

                                        while (finmember >> name >> lname >> phone >> address1 >> address2 >> date1 >> date2 >> date3 >> date4 >> date5 >> date6) {
                                            if (fname == name) {
                                                fout << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2 << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ' << date6;
                                            }
                                            if (fname == name) {
                                                x = 1;
                                            }
                                        }

                                        finbook.close();
                                        finmember.close();
                                        fout.close();

                                        if (x == 0) {
                                            cout << "Name not found" << endl;
                                        } else {
                                            cout << "Name found" << endl;
                                        }
                               //     }
                                    finmember.close();
                           //     }
                           // }
                            break;
                        case 0:
                            cout << "You chose to not rent a book, you will be redirected back now.." << endl;
                            break;
                        default:
                            break;
                    }
                } else {
                    cout << "There was no book found matching the title you entered, please try again!" << endl;
                }
                break;
            }
            finbook.close();
        }

    void deliverBook() {}
};



int main() {
    Renter renter1;
    //renter1.makeRenter();
    //renter1.getRenterInfo();
    //renter1.removeRenter();

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
    return 0;
}
