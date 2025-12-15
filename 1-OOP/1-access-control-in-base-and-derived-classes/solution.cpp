#include <iostream>

class Book {
protected:
  std::string title; // Accessible in derived classes

private:
  std::string author; // Only accessible within Book class

public:
  Book(std::string title, std::string author) {
    this->title = title;
    this->author = author;
  }

  void printInfo() const {
    std::cout << "Title: " << title << ", Author: " << author << std::endl;
  }
};

class TextBook : public Book { // Public inheritance - keeps access levels
private:
  std::string subject; // TextBook-specific data

public:
  TextBook(std::string title, std::string author, std::string subject)
      : Book(title, author) { // Initialize base class
    this->subject = subject;
  }

  void printFullInfo() const {
    // Can access 'title' (protected) but NOT 'author' (private)
    std::cout << "Title: " << title << ", Subject: " << subject << std::endl;
  }
};

int main() {
  Book book1("Book1", "Author1");
  book1.printInfo();

  TextBook textBook1("Book2", "Author2", "Subject1");
  textBook1.printFullInfo();
  textBook1.printInfo(); // Works because of public inheritance

  return 0;
}
