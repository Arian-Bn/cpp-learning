#include <iostream>

class Media {
private:
  std::string title;
  unsigned year;

public:
  Media(std::string title, unsigned year) : title(title), year(year) {}
  virtual ~Media() = default; // Virtual destructor for polymorphism

  virtual void printDetails() const {
    std::cout << title << "\t" << year << std::endl;
  }

  std::string getTitle() const { return title; }
  unsigned getYear() const { return year; }
};

class Book : public Media {
private:
  std::string author;
  unsigned pages;

public:
  Book(std::string title, unsigned years, std::string author, unsigned pages)
      : Media(title, years), author(author), pages(pages) {}
  virtual ~Book() = default;
  virtual void printDetails() const {
    std::cout << getTitle() << "\t" << getYear() << "\t" << author << "\t"
              << pages << std::endl;
  }

  std::string getAuthor() const { return author; }

  unsigned getPages() const { return pages; }
};

class AudioBook : public Book {
private:
  double duration;
  std::string narrator;

public:
  AudioBook(std::string title, unsigned years, std::string author,
            unsigned pages, double duration, std::string narrator)
      : Book(title, years, author, pages), duration(duration),
        narrator(narrator) {}
  virtual ~AudioBook() = default;

  virtual void printDetails() const override {
    std::cout << getTitle() << "\t" << getYear() << "\t" << getAuthor() << "\t"
              << getPages() << "\t" << duration << "\t" << narrator
              << std::endl;
  }

  double getDuration() const { return duration; }

  std::string getNarrator() const { return narrator; }
};

class Movie : public Media {
private:
  std::string director;
  int duration;

public:
  Movie(std::string title, unsigned year, std::string director, int duration)
      : Media(title, year), director(director), duration(duration) {}
  virtual ~Movie() = default;

  virtual void printDetails() const {
    std::cout << getTitle() << "\t" << getYear() << "\t" << director << "\t"
              << duration << std::endl;
  }
  std::string getDirector() const { return director; }
};

// Function demonstrating dynamic_cast usage
void processLibrary(Media *basicMedia[], int size) {
  for (unsigned i = 0; i < size; i++) {
    std::cout << "Object " << i + 1 << ": ";
    // Order matters: check from most derived to base
    if (AudioBook *bookPtr = dynamic_cast<AudioBook *>(basicMedia[i]))
      std::cout << "Narrator: " << bookPtr->getNarrator() << std::endl;
    else if (Book *bookPtr = dynamic_cast<Book *>(basicMedia[i]))
      std::cout << "Author: " << bookPtr->getAuthor() << std::endl;
    else if (Movie *moviePtr = dynamic_cast<Movie *>(basicMedia[i]))
      std::cout << "Director: " << moviePtr->getDirector() << std::endl;
    else
      std::cout << "Basic media object!"; // dynamic_cast returned nullptr

    std::cout << std::endl;
  }
}

int main() {
  const int SIZE = 4;

  Book book("1984", 1949, "George Orwell", 328);
  AudioBook audiobook("Crime and punishment", 1866, "Fyodor Dostoevsky", 592,
                      25.5, "Vasily Livanov");
  Movie movie("Inception", 2010, "Christopher Nolan", 148);

  Media basicMedia("Just Media", 2025);

  Media *library[SIZE] = {&book, &audiobook, &movie, &basicMedia};

  processLibrary(library, SIZE);

  return 0;
}
