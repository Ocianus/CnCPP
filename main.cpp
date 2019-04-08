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
    string adress, employeeID, libraryID;

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
            cout << "Enter ISBN number: " << endl;
            getline(cin, isbnNumber);
            cout << "Enter name of the author: " << endl;
            getline(cin, author);
            cout << "Enter title of the book: " << endl;
            getline(cin, title);
            cout << "Enter the number of pages: " << endl;
            getline(cin, pages);
            cout << "Enter the year the book was published: " << endl;
            getline(cin, publishYear);

            fout << "ISBN number: " << isbnNumber << endl;
            fout << "Author: " << author << endl;
            fout << "Title: " << title << endl;
            fout << "Number of pages: " << pages << endl;
            fout << "Publish year: " << publishYear << endl;
            //fout << "Date added to library: " << libraryID << endl;
            //time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            //librarian1.startDate = asctime(ti);
            fout << endl;
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
            cout << fout.rdbuf();
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
            cout << "Enter your first name: " << endl;
            getline(cin, firstName);
            cout << "Enter your last name: " << endl;
            getline(cin, lastName);
            cout << "Enter your address: " << endl;
            getline(cin, address);
            cout << "Enter your phone number: " << endl;
            getline(cin, phoneNumber);
            cout << "Enter the library the employee will be working at " << endl;
            getline(cin, libraryID);

            fout << "First name: " <<firstName << endl;
            fout << "Last name: " << lastName << endl;
            fout << "Address: " << address << endl;
            fout << "Phone: " << phoneNumber << endl;
            fout << "EmployeeID: " << employeeID << endl;
            fout << "Works at library: " << libraryID << endl;
            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            librarian1.startDate = asctime(ti);
            fout << "Time hired: " << librarian1.startDate << endl;
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
            cout << fout.rdbuf();
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
        cout << "Welcome to registration. Please fill in the information below: " << endl;
        while(fout) {
            cout << "Enter 0 if you no longer wish to add more members,"
                    "if you wish to proceed adding new member press any key: " << endl;
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

            fout << "First name: " <<firstName << endl;
            fout << "Last name: " << lastName << endl;
            fout << "Address: " << address << endl;
            fout << "Phone: " << phoneNumber << endl;
            fout << "MemberID: " << id << endl;
            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            member1.registrationDate = asctime(ti);
            fout << "Time registered: " << member1.registrationDate << endl;
            id++;
            cout << "Member successfully added!" << endl;
        }
        fout.close();
        ifstream fin;
        fin.open("member.txt");

        cout << "Do you wish to list all the librarians? If so enter 1"
                ", if not enter 0 to exit";
        getline(cin, line);
        if(line == "1") {
            while (fin) {
                getline(fin, line);
                cout << line << endl;
            }
            cout << "You chose to not list any librarians. Have a nice day." << endl;
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
            cout << fout.rdbuf();
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

            fout << "First name: " <<firstName << endl;
            fout << "Last name: " << lastName << endl;
            fout << "Address: " << address << endl;
            fout << "Phone: " << phoneNumber << endl;
            fout << "Depositum payed: " << depositum << endl;
            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            renter1.rentTime = asctime(ti);
            fout << "Time registered: " << renter1.rentTime << endl;
            cout << "Renter successfully added!" << endl;
        }

        fout.close();
        ifstream fin;
        fin.open("renter.txt");

        cout << "Do you wish to list all the librarians? If so enter 1"
                ", if not enter 0 to exit";
        getline(cin, line);

        if(line == "1") {
            while(fin) {
                getline(fin, line);
                cout << line << endl;
            }
            cout << "You chose to not list any librarians. Have a nice day." << endl;
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
            cout << fout.rdbuf();
        }
    }

    /**
     * removeRenter() fungerer ikke
     */

/*
    void removeRenter() {
        string line, name;
        cout << "Please enter the name of record you want to delete: ";
        cin >> name;
        ifstream myfile;
        myfile.open("renter.txt");
        ofstream temp;
        temp.open("temp.txt");
        while(getline(myfile, line)){
            if (line.substr(0, name.size()) != name) {
                temp << line << endl;
            }
            cout << "The record with the name " << name << " has been deleted if it existed" << endl;
            myfile.close();
            temp.close();
            remove("renter.txt");
            rename("temp.txt", "renter.txt");

            //system("pause");
        }
    }
*/

    /*
    void removeRenter() {
        string deleteLine;
        string line;

        ifstream fin;
        fin.open("renter.txt");
        ofstream temp;
        temp.open("temp.txt");
        cout << "Enter the last name of the renter you wish to remove";
        cin >> deleteLine;
        while(getline(fin, line)) {
            line.replace(line.find(deleteLine),deleteLine.length(),"");
            temp << line << endl;
        }
        temp.close();
        fin.close();
        remove("renter.txt");
        rename("temp.txt", "renter.txt");
        cout << endl;
    } */
};

int main() {
    Renter renter1;
    //renter1.makeRenter();
    //renter1.getRenterInfo();
    //renter1.removeRenter();

    //Member member1;
    //member1.makeMember();

    //Librarian librarian;
    //librarian.makeLibrarian();
    //librarian.listLibrarians();

    Book book;
    book.addBook();
    return 0;
}









/*

void menu();
void bookRent();


void menu() {
    int choice;
    bool menuOn = true;

    while (menuOn != false) {
        cout << "***\n";
        cout << " 1 - Rent a book\n";
        cout << " 2 - \n";
        cout << " 3 - \n";
        cout << " 4 - \n";
        cout << " 5 - Exit\n";
        cout << "Enter a number and press enter\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Directing you to renting site...\n" << flush;
                bookRent();
                break;
            case 2:
                cout << "";
                break;
            case 3:
                cout << "";
                break;
            case 4:
                cout << "";
                break;
            case 5:
                cout << "Exiting program...\n";
                menuOn = false;
                break;
            default:
                cout << "Not a valid choice.";
                cout << "Choose agian.";
                cin >> choice;
                break;
        }
    }
}

void bookRent() {
    system("CLS");
    cout << "Choose the book you want to rent: ";
    bool bookRentMenu = true;
    int choice;
    while (bookRentMenu != false) {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "";
                break;
            default:
                cout << "Not a valid choice.";
                cout << "Choose agian.";
                cin >> choice;
                break;
        }
    }
*/