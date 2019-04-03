#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Member {
public:
    string firstName;
    string lastName;
    string memberID;
    string phoneNumber;
    string address;
    string registrationDate;

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
        string fname, lname, add, pnumber, line;

        fout.open("sample.txt");
        cout << "Welcome to registration. Please fill in the information below: " << endl;
        while(fout) {
            cout << "Enter 0 if you no longer wish to add more members,"
                    "if you wish to proceed adding new member press any key: " << endl;
            getline(cin, line);
            if(line == "0") {
                break;
            }
            cout << "Enter your first name: " << endl;
            getline(cin, fname);
            cout << "Enter your last name: " << endl;
            getline(cin, lname);
            cout << "Enter your address: " << endl;
            getline(cin, add);
            cout << "Enter your phone number: " << endl;
            getline(cin, pnumber);

            fout << "First name: " <<fname << endl;
            fout << "Last name: " << lname << endl;
            fout << "Address: " << add << endl;
            fout << "Phone: " << pnumber << endl;
            fout << "MemberID: " << id << endl;
            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            member1.registrationDate = asctime(ti);
            fout << "Time registered: " << member1.registrationDate << endl;
            id++;
        }
        fout.close();
        ifstream fin;
        fin.open("sample.txt");

        while(fin) {
            getline(fin, line);
            cout << line << endl;
        }
        fin.close();
    }
};

class Renter {
public:
    string firstName;
    string lastName;
    bool depositum;
    string phoneNumber;
    string address;
    string rentTime;

    void getRenterInfo() {
        cout << "Renter information" << endl;
        cout << "____________________" << endl;
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Phonenumber name: " << phoneNumber << endl;
        cout << "Address name: " << address << endl;
        cout << boolalpha;
        cout << "Depositum " << depositum << endl;
    }

    void makeRenter() {
        Renter renter1;
        ofstream fout;
        string fname, lname, add, pnumber, line, depositum;


        fout.open("sample.txt");
        cout << "Welcome to registration. Please fill in the information below: " << endl;
        while(fout) {
            cout << "Enter 0 if you no longer wish to add more renters,"
                    "if you wish to proceed adding new renter press any key: " << endl;
            getline(cin, line);
            if(line == "0") {
                break;
            }
            cout << "Enter your first name: " << endl;
            getline(cin, fname);
            cout << "Enter your last name: " << endl;
            getline(cin, lname);
            cout << "Enter your address: " << endl;
            getline(cin, add);
            cout << "Enter your phone number: " << endl;
            getline(cin, pnumber);
            /**
             * Bedre om det blir skrevet ut true eller false
             */
            cout << "Has the renter payed depositum? " << endl;
            getline(cin, depositum);

            fout << "First name: " <<fname << endl;
            fout << "Last name: " << lname << endl;
            fout << "Address: " << add << endl;
            fout << "Phone: " << pnumber << endl;
            fout << "Depositum payed: " << depositum << endl;
            time_t tt; struct tm * ti; time(&tt); ti = localtime(&tt);
            renter1.rentTime = asctime(ti);
            fout << "Time registered: " << renter1.rentTime << endl;
        }
        fout.close();
        ifstream fin;
        fin.open("sample.txt");

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