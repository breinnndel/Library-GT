#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    Book(std::string title, std::string author) : title(title), author(author) {}
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        for (const auto& book : books) {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << std::endl;
        }
    }

private:
    std::vector<Book> books;
};

int main() {
    Library library;
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    library.addBook(Book("1984", "George Orwell"));

    std::cout << "Books in the library:" << std::endl;
    library.displayBooks();

    return 0;
}