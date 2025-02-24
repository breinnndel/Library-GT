#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    string genre;
    int releaseDate;
    double rating;

    Book(string t, string a, int re, string g, double r) {
        title = t;
        author = a;
        releaseDate = re;
        genre = g;
        rating = r;
    }

    void display() {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nYear: " << releaseDate;
        cout << "\nGenre: " << genre;
        cout << "\nRating: " << rating << "\n";
    }
};

int main() {
    vector<Book> books;
    int choice;

    do {
    
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            char addMore;
            do {
                string title;
                string author;
                string genre;
                int releaseDate;
                double rating;

                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> releaseDate;
                cin.ignore();
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter rating: ";
                cin >> rating;
                cin.ignore();

                books.push_back(Book(title, author, releaseDate, genre, rating));
                cout << "\nBook added!\n";

                cout << "\nDo you want to add another book? (y/n): ";
                cin >> addMore;
                cin.ignore();

            } while (addMore == 'y' || addMore == 'Y');

        } else if (choice == 2) {
            if (books.empty()) {
                cout << "No books listed.\n";
            } else {
                for (int i = 0; i < books.size(); i++) {
                    cout << "\n------------- Book " << i + 1 << " -----------------";
                    books[i].display();
                }
            }

        } else if (choice == 3) {
            string searchTitle;
            cout << "Enter title to search: ";
            getline(cin, searchTitle);

            bool found = false;
            for (int i = 0; i < books.size(); i++) {
                if (books[i].title == searchTitle) {
                    cout << "\nBook found!\n";
                    books[i].display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found.\n";
            }

        } else if (choice != 4) {
            cout << "Invalid.\n";
        }

    } while (choice != 4);

    cout << "bye!\n";
    return 0;
}