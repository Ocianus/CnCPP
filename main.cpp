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
    string isbnNumber, auther, title, publishYear, publisher;

    void bookGetInfo() {
        cout << "Bookinformation" << endl;
        cout << "________________" << endl;
        cout << "ISBNnumber: " << isbnNumber << endl;
        cout << "Auther: " << auther << endl;
        cout << "Title: " << title << endl;
        cout << "Year published: " << publishYear << endl;
        cout << "Published by: " << publisher << endl;
    }
};

class Librarian: public Person {
public:
    string startDate, salary, employeeID, libraryID;

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
/*
    void makeLibrarian() {
        int id = 1;
        Librarian librarian1;
        ofstream fout;
        string line;

        fout.open("member.txt");
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
            librarian1.startDate = asctime(ti);
            fout << "Time hired: " << librarian1.startDate << endl;
            id++;
        }
        fout.close();
        ifstream fin;
        fin.open("member.txt");

        while(fin) {
            getline(fin, line);
            cout << line << endl;
        }
        fin.close();
    } */
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

        fout.open("member.txt");
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
        }
        fout.close();
        ifstream fin;
        fin.open("member.txt");

        while(fin) {
            getline(fin, line);
            cout << line << endl;
        }
        fin.close();
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


        fout.open("renter.txt");
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
        }

        fout.close();
        ifstream fin;
        fin.open("renter.txt");

        while(fin) {
            getline(fin, line);
            cout << line << endl;
        }

        fin.close();
    };
};

int main() {
    Renter renter1;
    renter1.makeRenter();
    renter1.getRenterInfo();

    //Member member1;
    //member1.makeMember();

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