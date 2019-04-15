#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#pragma warning(disable:4996) // Disabling warnings, making it possible to run

using namespace std;

// Function declarations
void mainSite();
void memberSite();
void librarianSite();

// Main-method
int main() {
    mainSite();
    return 0;
}

// Class Person
class Person {
public:
    string firstName, lastName, address, phoneNumber;
};

// Class Librarian
class Librarian : public Person {
public:
    string startDate, salary, libraryID;

    // Function makeLibrarian -> adding a librarian to textfile
    void makeLibrarian() {
        Librarian librarian;
        ofstream f_out; // Output file stream object
        string line;

        f_out.open("librarian.txt", std::ios_base::app); // Open file named "librarian.txt"
        cout << "***********************************\n";
        cout << "Welcome to registration. Please fill in the information below." << endl;

        while (f_out) {
            cout << "Enter 0 if you no longer wish to add more members, if you wish to proceed adding new member press any key > " << endl;
            cout << "If you want to go back to the previous menu, enter 2 > " << endl;
            getline(cin, line);
            if (line == "0") {
                break;
            } else if (line == "2") {
                system("CLS");
                cout << "Going back...\n" << flush;
                librarianSite();
            }
            cout << "Enter the librarian's first name > (Only firstname, no middlename)" << endl;
            getline(cin, firstName);
            cout << "Enter the librarian's last name > (Only lastname, no middlename)" << endl;
            getline(cin, lastName);
            cout << "Enter the librarian's address > (For example: Sesamestreet 45)" << endl;
            getline(cin, address);
            cout << "Enter the librarian's phone number > " << endl;
            getline(cin, phoneNumber);
            cout << "Enter the name of the city which the library is located in > (For example: Ski)" << endl;
            getline(cin, libraryID);
            time_t tt; struct tm* ti; time(&tt); ti = localtime(&tt); librarian.startDate = asctime(ti); // Formating date/getting current localtime
            f_out << firstName << " " << lastName << " " << address << " " << phoneNumber << " " << libraryID << " " << librarian.startDate;
            cout << "Librarian successfully added!" << endl;
        }
        f_out.close(); // Close file associated with this stream

        // If the user wants to list members after adding to textfile
        ifstream f_in; // Input file stream object
        f_in.open("librarian.txt"); // Open file named "librarians.txt"
        cout << "Do you wish to list all the librarians? If so enter 1, if not enter 0 to exit > ";
        getline(cin, line);
        if (line == "1") {
            while (f_in) {
                getline(f_in, line);
                cout << line << endl;
            }
            f_in.close(); // Close file associated with this stream
        } else if(line == "0") {
            system("CLS");
            cout << "You chose to not list any librarians. Going back to previous site...\n" << flush;
            librarianSite();
        }
    }

    // Function for removal of librarian in textfile
    void removeLibrarian() {
        string name, fname, lname, phone, address1, address2, date2, date3, date4, date5, date6, date7;
        int x = 0;
        int choice;

        ifstream librarian("librarian.txt"); // Create and open "librarian.txt", output
        ofstream temp("temp.txt"); // Create and open "temp.txt", input

        cout << "Enter the firstname and last name of the librarian you want to erase from the system >";
        cin >> fname;
        cin >> lname;
        // While-loop
        while (librarian >> name >> lname >> address1 >> address2 >> phone >> date2 >> date3 >> date4 >> date5 >> date6 >> date7) {
            if (fname != name) {
                temp << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                     << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ' << date6 << ' ' << date7 << endl;
            } if (fname == name) {
                x = 1;
            }
        }
        librarian.clear(); // Clearing end-of-file
        librarian.seekg(0, ios::beg); // Seek to 0 characters from the beginning of the file
        librarian.close(); // Closing file associated with this stream
        temp.close(); // Closing file associated with this stream
        remove("librarian.txt"); // Removes current "librarian.txt"
        rename("temp.txt", "librarian.txt"); // renames "temp.txt" to "librarian.txt"

        if (x == 0) {
            system("CLS");
            cout << "There is no librarian with the name you entered. Going back to previous site..\n" << flush;
            cout << "Enter 7 and try again > \n" << flush;
            librarianSite();
        } else {
            cout << "Librarian data has been deleted" << endl;
            cout << "\n\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            switch (choice) {
                case 0:
                    system("CLS");
                    cout << "Exiting...\n" << flush;
                    exit(1);
                    break;
                case 1:
                    system("CLS");
                    cout << "Going back..\n" << flush;
                    librarianSite();
                    break;
                default:
                    system("CLS");
                    cout << "Not a valid choice. Choose agian.\n" << flush;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << flush;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function listLibrarians for listing librarians
    void listLibrarians() {
        ifstream f_in; // Input file stream object
        int choice;

        // If opening the file did not succeeded, prints error to user
        f_in.open("librarian.txt");
        if (!f_in) {
            cerr << "Unable to open the file librarian.txt";
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            errorHand(choice);
        }

        // If opening the file succeeded
        if (f_in.is_open()) {
            cout << "***********************************\n";
            cout << "First and last name - Address - Phone number - Date hired" << endl;
            cout << f_in.rdbuf(); // returns a pointer to the underlying basic_streambuf object for the given iostream object.

            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            switch (choice) {
                case 0:
                    system("CLS");
                    cout << "Exiting...\n" << flush;
                    exit(1);
                    break;
                case 1:
                    system("CLS");
                    cout << "Going back..\n" << flush;
                    librarianSite();
                    break;
                default:
                    system("CLS");
                    cout << "Not a valid choice. Choose agian.\n" << flush;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << flush;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function listAllPreviousLoans -> Listing all previous and active loans
    void listAllPreviousLoans() {
        ifstream log("log.txt");
        int choice;
        if (!log) {
            cerr << "Unable to open the file log.txt";

            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }

        if (log.is_open()) {
            cout << "First and last name - Address - Phone number - Date registered - Title - ISBN - Authors first and last name - Pages - Publish year - Date loaned from" << endl;
            cout << log.rdbuf();

            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }
    }

    // Function errorHand -> Makes it possible to go back or exit, saves alot of uneccessary space
    void errorHand(int choice) {
        if (choice == 1) {
            system("CLS");
            cout << "Going back...\n" << flush;
            librarianSite();
        }
        else if (choice == 0) {
            system("CLS");
            cout << "Exiting...\n" << flush;
            exit(1);
        }
    }


};

// Class member
class Member : public Person {
public:
    string registrationDate;

    // Function makeMember -> adding a member to textfile
    void makeMember() {
        Member member;
        ofstream f_out; // Output file stream object
        string line;

        f_out.open("member.txt", std::ios_base::app); // Open file named "member.txt"
        cout << "***********************************\n";
        cout << "Welcome to member registration. Please fill in the information below." << endl;

        while (f_out) {
            cout << "Enter 0 if you no longer wish to add more members and if you wish to proceed adding a new member press any key > " << endl;
            cout << "If you want to go back to the previous menu, enter 2 > " << endl;
            getline(cin, line);
            if (line == "0") {
                break;
            } else if (line == "2") {
                system("CLS");
                cout << "Going back...\n" << flush;
                librarianSite();
            }
            cout << "Enter the members first name > (Only firstname, no middlename)" << endl;
            getline(cin, firstName);
            cout << "Enter the members last name > (Only lastname, no middlename)" << endl;
            getline(cin, lastName);
            cout << "Enter the members address > (For example: Sesamestreet 45)" << endl;
            getline(cin, address);
            cout << "Enter the members phone number > " << endl;
            getline(cin, phoneNumber);
            // Formating date/getting current localtime
            time_t tt; struct tm* ti; time(&tt); ti = localtime(&tt); member.registrationDate = asctime(ti);
            f_out << firstName << " " << lastName << " " << address << " " << phoneNumber << " " << member.registrationDate;
            cout << "Member successfully added!" << endl;
        }
        f_out.close(); // Close file associated with this stream

        // If the user wants to list members after adding to textfile
        ifstream f_in; // Input file stream object
        f_in.open("member.txt"); // Open file named "member.txt"
        cout << "Do you wish to list all the members? If so enter 1, if not enter 0 to exit > ";
        getline(cin, line);
        if (line == "1") {
            while (f_in) {
                getline(f_in, line);
                cout << line << endl;
            }
            f_in.close(); // Close file associated with this stream
        } else if (line == "0") {
            system("CLS");
            cout << "You chose to not list any members. Going back to previous site...\n" << flush;
            librarianSite();
        }
    }

    // Function for removal of member in textfile
    void removeMember() {
        string name, fname, lname, phone, address1, address2, date2, date3, date4, date5, date6;
        int x = 0;
        int choice;

        ifstream member("member.txt"); // Create and open "member.txt"
        ofstream temp("temp.txt"); // Create and open "temp.txt"

        cout << "Enter the first and last name of the member you want to erase from our system > ";
        cin >> fname;
        cin >> lname;
        // While-loop for writing to file
        while (member >> name >> lname >> phone >> address1 >> address2 >> date2 >> date3 >> date4 >> date5 >> date6) {
            if (fname != name) {
                temp << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                     << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ' << date6 << endl;
            } if (fname == name) {
                x = 1;
            }
        }
        member.clear(); // Clearing end-of-file
        member.seekg(0, ios::beg); // Seek to 0 characters from the beginning of the file
        member.close(); // Closing file associated with this stream
        temp.close(); // Closing file associated with this stream
        remove("member.txt"); // Removes current "member.txt"
        rename("temp.txt", "member.txt"); // renames "temp.txt" to "member.txt"

        if (x == 0) {
            system("CLS");
            cout << "There is no member with the name you entered. Going back to previous site..\n" << flush;
            cout << "Enter 8 and try again > \n" << flush;
            librarianSite();
        } else {
            cout << "Member data has been deleted" << endl;

            cout << "\n\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            switch (choice) {
                case 0:
                    system("CLS");
                    cout << "Exiting...\n" << flush;
                    exit(1);
                    break;
                case 1:
                    system("CLS");
                    cout << "Going back..\n" << flush;
                    librarianSite();
                    break;
                default:
                    system("CLS");
                    cout << "Not a valid choice. Choose agian.\n" << flush;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << flush;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function listMembers for listing members
    void listMembers() {
        ifstream f_in; // Input file stream object
        int choice;

        // If opening the file did not succeeded, prints error to user
        f_in.open("member.txt");
        if (!f_in) {
            cerr << "Unable to open the file member.txt";
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            errorHand(choice);
        }

        // If opening the file succeeded
        if (f_in.is_open()) {
            cout << "***********************************\n";
            cout << "First and last name - Address - Phone number - Date registered" << endl;
            cout << f_in.rdbuf(); // returns a pointer to the underlying basic_streambuf object for the given iostream object.

            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            switch (choice) {
                case 0:
                    system("CLS");
                    cout << "Exiting...\n" << flush;
                    exit(1);
                    break;
                case 1:
                    system("CLS");
                    cout << "Going back..\n" << flush;
                    librarianSite();
                    break;
                default:
                    system("CLS");
                    cout << "Not a valid choice. Choose agian.\n" << flush;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << flush;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function errorHand -> Makes it possible to go back or exit, saves alot of uneccessary space
    void errorHand(int choice) {
        if (choice == 1) {
            system("CLS");
            cout << "Going back...\n" << flush;
            librarianSite();
        }
        else if (choice == 0) {
            system("CLS");
            cout << "Exiting...\n" << flush;
            exit(1);
        }
    }
};

// Class Book
class Book {
public:
    string isbnNumber, author, title, publishYear, pages;

    // Function addBook -> adding a book to textfile
    void addBook() {
        Book book;
        ofstream f_out; // Output file stream object
        string line;

        f_out.open("book.txt", std::ios_base::app); // Open file named "book.txt"
        cout << "***********************************\n";
        cout << "Welcome to registration. Please enter the values of the book you wish to add to the shelf. " << endl;

        while (f_out) {
            cout << "Enter 0 if you no longer wish to add more books, and if you wish to proceed adding new book press any key > " << endl;
            cout << "If you want to go back to the previous menu, enter 2 > " << endl;
            getline(cin, line);
            if (line == "0") {
                break;
            } else if (line == "2") {
                system("CLS");
                cout << "Going back...\n" << flush;
                librarianSite();
            }
            cout << "Enter title of the book > (For example: Antarktis)" << endl;
            getline(cin, title);
            cout << "Enter ISBN number > " << endl;
            getline(cin, isbnNumber);
            cout << "Enter name of author (first- and lastname, no middlename) > " << endl;
            getline(cin, author);
            cout << "Enter the number of pages > " << endl;
            getline(cin, pages);
            cout << "Enter the year the book was published > " << endl;
            getline(cin, publishYear);

            f_out << title << " " << isbnNumber << " " << author << " " << pages << " " << publishYear << endl;
            cout << "Book successfully added!" << endl;
        }
        f_out.close(); // Close file associated with this stream

        // If the user wants to list books after adding to textfile
        ifstream f_in; // Input file stream object
        f_in.open("book.txt"); // Open file named "book.txt"
        cout << "Do you wish to list all the books in the system? If so enter 1, if not enter 0 to exit > ";
        getline(cin, line);
        if (line == "1") {
            while (f_in) {
                getline(f_in, line);
                cout << line << endl;
            }
            f_in.close(); // Close file associated with this stream
        } else if(line == "0") {
            system("CLS");
            cout << "You chose to not list any books. Going back to previous site...\n" << flush;
            librarianSite();
        }
    }

    // Function for removal of book in textfile
    void removeBook() {
        string title, intitle, isbn, authorfn, authorln, pages, publishYear;
        int x = 0;
        int choice;

        ifstream book("book.txt"); // Create and open "book.txt"
        ofstream temp("temp.txt"); // Create and open "temp.txt"

        cout << "Enter name of the book you want to erase from database > ";
        cin >> intitle;
        // While-loop for writing to file
        while (book >> title >> isbn >> authorfn >> authorln >> pages >> publishYear) {
            if (intitle != title) {
                temp << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages << ' ' << publishYear << endl;
            } if (intitle == title) {
                x = 1;
            }
        }
        book.clear(); // Clearing end-of-file
        book.seekg(0, ios::beg); // Seek to 0 characters from the beginning of the file
        book.close(); // Closing file associated with this stream
        temp.close(); // Closing file associated with this stream
        remove("book.txt"); // Removes current "book.txt"
        rename("temp.txt", "book.txt"); // renames temp.txt to "book.txt"

        if (x == 0) {
            system("CLS");
            cout << "There is no book with the name you entered. Going back to previous site..\n" << flush;
            cout << "Enter 9 and try again > \n" << flush;
            librarianSite();
        } else {
            cout << "Book data has been deleted" << endl;

            cout << "\n\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            switch (choice) {
                case 0:
                    system("CLS");
                    cout << "Exiting...\n" << flush;
                    exit(1);
                    break;
                case 1:
                    system("CLS");
                    cout << "Going back..\n" << flush;
                    librarianSite();
                    break;
                default:
                    system("CLS");
                    cout << "Not a valid choice. Choose agian.\n" << flush;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << flush;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function listBooks for listing books
    void listBooks() {
        ifstream f_in; // Input file stream object
        int choice;

        // If opening the file did not succeeded, prints error to user
        f_in.open("book.txt");
        if (!f_in) {
            cerr << "Unable to open the file book.txt";
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            errorHand(choice);
        }

        // If opening the file succeeded
        if (f_in.is_open()) {
            cout << "***********************************\n";
            cout << "Title - ISBN - Author - Pages - Publish date" << endl;
            cout << f_in.rdbuf(); // returns a pointer to the underlying basic_streambuf object for the given iostream object

            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > ";
            cin >> choice;
            switch (choice) {
                case 0:
                    system("CLS");
                    cout << "Exiting...\n" << flush;
                    exit(1);
                    break;
                case 1:
                    system("CLS");
                    cout << "Going back..\n" << flush;
                    librarianSite();
                    break;
                default:
                    system("CLS");
                    cout << "Not a valid choice. Choose agian.\n" << flush;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << flush;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function errorHand -> Makes it possible to go back or exit, saves alot of uneccessary space
    void errorHand(int choice) {
        if (choice == 1) {
            system("CLS");
            cout << "Going back...\n" << flush;
            librarianSite();
        } else if (choice == 0) {
            system("CLS");
            cout << "Exiting...\n" << flush;
            exit(1);
        }
    }
};

// Class BookHandler -> class for loaning and returning books
class BookHandler {
public:
    string fname, name, lname, phone, address1, address2, date1, date2, date3, date4, date5, date6;
    string title, isbn, authorfn, authorln, pages, publishYear;
    string search, line, registrationDate;
    string element1, element2, element3, element4, element5, element6, element7, element8;
    int x = 0;

    // Function loanBook -> for loaning books from the system
    void loanBook() {
        BookHandler bookHandler;
        ifstream finbook("book.txt"), fin("book.txt"), finmember("member.txt"); // Input file stream object
        ofstream fout("loanedBook.txt", std::ios_base::app), temp("temp.txt"), log("log.txt", std::ios_base::app); // Output file stream object

        bool exists = false;
        int y = 0, offset, choice, length;

        cout << "***********************************\n";
        cout << "Enter the title of the book you wish to rent > " << endl;
        cin >> search;

        // While for finding book in "book.txt"
        while (!finbook.eof()) {
            getline(finbook, line);
            if ((offset = line.find(search, 0)) != string::npos) {
                cout << "The book '" << search << "' has been found!" << endl;
                exists = true;
            }
        }

        // If book does not exist in book.txt
        if (!exists) {
            cout << "No book with the title youve entered was found!" << endl;
            cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }

        // While book exist in book.txt
        while (exists == true) {
            cout << "Do you wish to rent the book? Type 1 if you wish to rent it, 0 if not > " << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter your first and last name if you're a member > " << endl;
                    cin >> fname;
                    cin >> lname;

                    // while loop for writing to file
                    while (finmember >> name >> lname >> phone >> address1 >> address2 >> date2 >> date3
                                     >> date4 >> date5 >> date6) {
                        if (fname == name) {
                            y = 1;
                            fout << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                                 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' '
                                 << date6 << ' ';
                            log << name << ' ' << lname << ' ' << phone << ' ' << address1 << ' ' << address2
                                << ' ' << date1 << ' ' << date2 << ' ' << date3 << ' ' << date4 << ' ' << date5 << ' ';
                        }
                        if (fname == name) {
                            x = 1;
                        }
                    }

                    if (y == 1) {
                        // while loop for writing to file
                        while (fin >> title >> isbn >> authorfn >> authorln >> pages >> publishYear) {
                            if (search == title) {
                                time_t tt; struct tm* ti; time(&tt); ti = localtime(&tt); bookHandler.registrationDate = asctime(ti); // Formating date/getting current localtime
                                fout << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages
                                     << ' ' << publishYear << ' ' << "| Loaned from: " << bookHandler.registrationDate;
                                log << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages
                                    << ' ' << publishYear << ' ' << "| Loaned from: " << bookHandler.registrationDate;
                            }

                            if (search != title) {
                                temp << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages
                                     << ' ' << publishYear << endl;
                            }

                            if (search == title) {
                                x = 1;
                            }
                        }
                    }
                    fin.clear(); // Clearing end-of-file
                    fin.seekg(0, ios::beg); // Seek to 0 characters from the beginning of the file
                    fin.close(); // Closing file associated with this stream
                    finbook.close(); // Closing file associated with this stream
                    finmember.close(); // Closing file associated with this stream
                    fout.close(); // Closing file associated with this stream
                    temp.close(); // Closing file associated with this stream
                    log.close(); // Closing file associated with this stream
                    remove("book.txt"); // Removes current "book.txt"
                    rename("temp.txt", "book.txt"); // Renames temp.txt to "book.txt"

                    if (x == 0) {
                        cout << "Name or title not found, try again!" << endl;
                    }
                    else {
                        cout << "Name and title found - you have successfully loaned the book '" << search << "'!" << endl;
                    }
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
                    cin >> choice;
                    errorHand(choice);
                    exists = false;
                    break;
                case 0:
                    system("CLS");
                    cout << "You chose to not rent a book, you will be redirected back now..\n" << flush;
                    memberSite();
                    break;
                default:
                    cout << "Not a valid choice. Choose agian.\n" << endl;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
        }
    }

    // Function deliverBook -> delivering books back to the system
    void deliverBook() {
        int offset, choice;
        fstream frwbooks("book.txt", std::ios_base::app); // I/O file stream object
        ifstream finmember("member.txt"); // Input file stream object
        ifstream frwloans("loanedBook.txt"); // Input file stream object
        fstream loans("loanedBook.txt"); // I/O file stream object
        ofstream temp("temp.txt"); // Output file stream object
        bool bookExists = false;
        string element1, element2, element3, element4, element5, element6, element7, element8;

        cout << "***********************************\n";
        cout << "What is the title of the book would you like to deliver? >" << endl;
        cin >> title;

        // While for finding book in "loanedBook.txt"
        while (!frwloans.eof()) {
            getline(frwloans, line);
            if ((offset = line.find(title, 0)) != string::npos) {
                cout << "The book '" << title << "' has been found!" << endl;
                bookExists = true;
            }
        }

        // If book does not exist in "loanedBook.txt"
        if (!bookExists) {
            cout << "No book with the title you have entered was found!" << endl;
            cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }

        // While book exist in "loanedBook.txt"
        while (bookExists) {
            int userInput;
            cout << "All data has been found, do you wish to complete the retun? Press 1 if yes, 0 if no >" << endl;
            cin >> userInput;
            switch (userInput) {
                case 1:
                    cout << "Enter your first and last name> " << endl;
                    cin >> fname;
                    cin >> lname;

                    // While loop for writing to files
                    while (loans >> name >> lname >> address1 >> address2 >> phone >> date2 >> date3 >> date4
                                 >> date5 >> date6 >> title >> isbn >> authorfn >> authorln >> pages >> publishYear
                                 >> element1 >> element2 >> element3 >> element4 >> element5 >> element6 >> element7
                                 >> element8) {
                        if (fname != name) {
                            temp << name << ' ' << lname << ' ' << address1 << ' ' << address2 << ' ' << phone
                                 << ' ' << date2 << ' ' << date3 << ' '
                                 << date4 << ' ' << date5 << ' ' << date6 << ' ' << title << ' ' << isbn << ' ' << authorfn
                                 << ' ' << authorln << ' ' << pages << ' '
                                 << publishYear << ' ' << element1 << ' ' << element2 << ' ' << element3 << ' ' << element4
                                 << ' ' << element5 << ' ' << element6 << ' ' << element7 << ' ' << element8;
                        }
                        if (fname == name) {
                            frwbooks << title << ' ' << isbn << ' ' << authorfn << ' ' << authorln << ' ' << pages << ' ' << publishYear << endl;
                            x = 1;
                        }
                    }

                    frwloans.clear(); // Clearing end-of-file
                    frwloans.seekg(0, ios::beg); // Seek to 0 characters from the beginning of the file
                    frwloans.close(); // Closing file associated with this stream
                    loans.close(); // Closing file associated with this stream
                    temp.close(); // Closing file associated with this stream
                    frwbooks.close(); // Closing file associated with this stream
                    remove("loanedBook.txt"); // Removes current "loanedBook.txt"
                    rename("temp.txt", "loanedBook.txt"); // Renames temp.txt to "loanedBook.txt"

                    if (x == 0) {
                        cout << "An error occoured while attempting to return the book. Please try again!" << endl;
                    }
                    else {
                        cout << "The book has been successfully returned! Have a nice day!" << endl;
                    }

                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
                    cin >> choice;
                    errorHand(choice);
                    bookExists = false;
                    break;
                case 0:
                    system("CLS");
                    cout << "You chose to not return the book, you will be redirected back now.." << flush;
                    memberSite();
                    break;
                default:
                    cout << "Not a valid choice. Choose agian.\n" << endl;
                    cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
                    cin >> choice;
                    errorHand(choice);
                    break;
            }
            break;
        }
    }

    // Listing all active loans
    void listCurrentLoans() {
        cout << "***********************************\n";
        int choice;
        ifstream loaned("loanedBook.txt");
        if (!loaned) {
            cerr << "Unable to open the file loanedBooks.txt\n";
            cout << "Do you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            if (choice == 1) {
                system("CLS");
                cout << "Going back...\n" << flush;
                librarianSite();
            }
            else if (choice == 0) {
                system("CLS");
                cout << "Exiting...\n" << flush;
                exit(1);
            }
        }

        if (loaned.is_open()) {
            cout << "First and last name - Address - Phone number - Date og registration - Title - ISBN - Author - Pages - Publish Year - Date loaned " << endl;
            cout << loaned.rdbuf();
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            if (choice == 1) {
                system("CLS");
                cout << "Going back...\n" << flush;
                librarianSite();
            }
            else if (choice == 0) {
                system("CLS");
                cout << "Exiting...\n" << flush;
                exit(1);
            }
        }
    }

    // Listing active loans by name
    void listCurrentLoansByName() {
        cout << "***********************************\n";
        ifstream loaned("loanedBook.txt");
        ifstream loanedBooks("loanedBook.txt");
        bool nameExists = false;
        int offset, choice;

        cout << "Enter your first and last name to see all active loans > " << endl;
        cin >> fname >> lname;
        search = fname + " " + lname;

        while (!loaned.eof()) {
            getline(loaned, line);
            if ((offset = line.find(search, 0)) != string::npos) {
                cout << "The name '" << search << "' has been found!" << endl;
                nameExists = true;
                break;
            }
        }

        if (!nameExists) {
            cout << "No member with the name you've entered was found!" << endl;
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }

        while (nameExists) {
            while (loanedBooks >> name >> lname >> address1 >> address2 >> phone >> date1 >> date2 >> date3 >> date4
                               >> date5 >> title >> isbn >> authorfn >> authorln >> pages >> publishYear
                               >> element1 >> element2 >> element3 >> element4 >> element5 >> element6 >> element7
                               >> element8) {
                if (search == name + " " + lname) {
                    cout << name << ' ' << lname << ' ' << address1 << ' ' << address2 << ' ' << phone << ' ' << date1
                         << ' ' << date2 << ' ' << date3 << ' '
                         << date4 << ' ' << date5 << ' ' << title << ' ' << isbn << ' ' << authorfn
                         << ' ' << authorln << ' ' << pages << ' '
                         << publishYear << ' ' << element1 << ' ' << element2 << ' ' << element3 << ' ' << element4
                         << ' ' << element5 << ' ' << element6 << ' ' << element7 << ' ' << element8 << endl;
                }

                if (fname == name) {
                    x = 1;
                }
            }
            nameExists = false;
        }
        loaned.close();
        loanedBooks.close();

        if (x == 0) {
            cout << "An error occoured while attmepting to retrieve the data!" << endl;
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }
        else {
            cout << "All active loans successfully printed!" << endl;
            cout << "\nDo you want to go back to the previous site? 1 for yes, and 0 for exiting the program > " << endl;
            cin >> choice;
            errorHand(choice);
        }
    }

    // Function errorHand -> Makes it possible to go back or exit, saves alot of uneccessary space
    void errorHand(int choice) {
        if (choice == 1) {
            system("CLS");
            cout << "Going back...\n" << flush;
            memberSite();
        } else if(choice == 0) {
            system("CLS");
            cout << "Exiting...\n" << flush;
            exit(1);
        }
    }
};

// mainSite-function -> Displaying mainsite
void mainSite() {
    int choice;
    bool menuOn = true;

    while (menuOn != false) {
        system("COLOR 9");
        cout << "***********************************\n";
        cout << "WELCOME TO FOLLO-LIBRARYSYSTEM!" << endl;
        cout << "Are you a member or a librarian?" << endl;
        cout << "If you want to register in our system, call for a librerian." << endl;
        cout << "1. I am a member" << endl;
        cout << "2. I am a librarian" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter a number and press enter > "; cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                cout << "Directing you to member site...\n" << flush;
                menuOn = false;
                memberSite();
                break;
            case 2:
                system("CLS");
                cout << "Directing you to the librarian site...\n" << flush;
                menuOn = false;
                librarianSite();
                break;
            case 3:
                system("CLS");
                cout << "Exiting...\n" << flush;
                cout << "See you agian!" << endl;
                exit(1);
            default:
                cout << "Not a valid choice. ";
                cout << "Choose agian." << endl;
                mainSite();
                cin >> choice;
                break;
        }
    }
}

// membersite-function -> Displaying membersite
void memberSite() {
    int choice;
    bool memberMenuOn = true;
    BookHandler bh;

    while (memberMenuOn != false) {
        cout << "***********************************\n";
        cout << "Hello, member!" << endl;
        cout << "1. Lend a book" << endl;
        cout << "2. Return a book" << endl;
        cout << "3. See active loans" << endl;
        cout << "4. Go back to previous site" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter a number and press enter > "; cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                cout << "Loading site for bookloan...\n" << flush;
                memberMenuOn = false;
                bh.loanBook();
                break;
            case 2:
                system("CLS");
                cout << "Loading site for bookreturn...\n" << flush;
                memberMenuOn = false;
                bh.deliverBook();
                break;
            case 3:
                system("CLS");
                cout << "Going to your active loans...\n" << flush;
                memberMenuOn = false;
                bh.listCurrentLoansByName();
                break;
            case 4:
                system("CLS");
                cout << "Going back...\n" << flush;
                mainSite();
                break;
            case 5:
                system("CLS");
                cout << "Exiting...\n" << flush;
                cout << "See you agian!" << endl;
                exit(1);
            default:
                system("CLS");
                cout << "Not a valid choice. ";
                cout << "Choose agian." << endl;
                mainSite();
                cin >> choice;
                break;
        }
    }
}

// librariansite-function -> Displaying librariansite
void librarianSite() {
    int choice;
    bool librarianMenuOn = true;
    Librarian librarian;
    Member member;
    Book book;
    BookHandler bh;

    while (librarianMenuOn != false) {
        cout << "***********************************\n";
        cout << "Hello, librarian!" << endl;
        cout << "1. Add librarian" << endl;
        cout << "2. Add member" << endl;
        cout << "3. Add books" << endl;
        cout << "4. List librarians" << endl;
        cout << "5. List members" << endl;
        cout << "6. List books" << endl;
        cout << "7. List all active loans" << endl;
        cout << "8. List all loans (previous and active)" << endl;
        cout << "9. Remove librarian" << endl;
        cout << "10. Remove member" << endl;
        cout << "11. Remove books" << endl;
        cout << "12. Go back to previous site" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter a number and press enter > "; cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                cout << "Directing you to librarianregistration...\n" << flush;
                librarianMenuOn = false;
                librarian.makeLibrarian();
                break;
            case 2:
                system("CLS");
                cout << "Directing you to memberregistration...\n" << flush;
                librarianMenuOn = false;
                member.makeMember();
                break;
            case 3:
                system("CLS");
                cout << "Directing you to bookregister...\n" << flush;
                librarianMenuOn = false;
                book.addBook();
                break;
            case 4:
                system("CLS");
                cout << "Directing you to register for librarians...\n" << flush;
                librarianMenuOn = false;
                librarian.listLibrarians();
                break;
            case 5:
                system("CLS");
                cout << "Directing you to register for members...\n" << flush;
                librarianMenuOn = false;
                member.listMembers();
                break;
            case 6:
                system("CLS");
                cout << "Directing you to register for books...\n" << flush;
                librarianMenuOn = false;
                book.listBooks();
                break;
            case 7:
                system("CLS");
                cout << "Directing you to all active loans...\n" << flush;
                librarianMenuOn = false;
                bh.listCurrentLoans();
                break;
            case 8:
                system("CLS");
                cout << "Directing you to all loans...\n" << flush;
                librarianMenuOn = false;
                librarian.listAllPreviousLoans();
                break;
            case 9:
                system("CLS");
                cout << "Delete librarian..\n" << flush;
                librarianMenuOn = false;
                librarian.removeLibrarian();
                break;
            case 10:
                system("CLS");
                cout << "Delete member..\n" << flush;
                librarianMenuOn = false;
                member.removeMember();
                break;
            case 11:
                system("CLS");
                cout << "Delete book..\n" << flush;
                librarianMenuOn = false;
                book.removeBook();
                break;
            case 12:
                system("CLS");
                cout << "Going back...\n" << flush;
                mainSite();
                break;
            case 13:
                system("CLS");
                cout << "Exiting...\n" << flush;
                cout << "See you agian!" << endl;
                exit(1);
            default:
                system("CLS");
                cout << "Not a valid choice. ";
                cout << "Choose agian." << endl;
                mainSite();
                cin >> choice;
                break;
        }
    }
}