#include <iostream>

using namespace std;

/*
 * Задача: Реализация класса "Книга" (Book)
 *
 * Требования:
 * - Класс Book должен содержать следующие публичные поля:
 *     std::string title   — название книги
 *     std::string author  — автор книги
 *     int year            — год издания
 *     int pages           — количество страниц
 *
 * - Должны быть реализованы два конструктора:
 *     1. Конструктор по умолчанию, инициализирующий поля значениями:
 *        title = "Unknown", author = "Anonymous", year = 0, pages = 0
 *     2. Параметризованный конструктор, принимающий все четыре параметра.
 *
 * - Метод void print() выводит информацию о книге в формате:
 *        Title: <название>, Author: <автор>, Year: <год>, Pages: <страницы>
 *
 * Пример использования:
 *     Book book1;                              // использует конструктор по
 * умолчанию Book book2{"1984", "George Orwell", 1949, 328}; book1.print();
 *     book2.print();
 *
 * Ожидаемый вывод:
 *     Title: Unknown, Author: Anonymous, Year: 0, Pages: 0
 *     Title: 1984, Author: George Orwell, Year: 1949, Pages: 328
 *
 */

class Book {
public:
  string title;
  string author;
  int year;
  int pages;

  Book(const string &nTitle, const string &nAuthor, int nYear, int nPages)
      : title(nTitle), author(nAuthor), year(nYear), pages(nPages) {}

  Book() {
    title = "Unknown";
    author = "Anonymous";
    year = 0;
    pages = 0;
  }

  void print() {
    cout << "Title: " << title << ", Author: " << author << ", Year: " << year
         << ", Pages: " << pages << endl;
  }
};

int main() {
  Book book1;
  Book book2{"1984", "George Orwell", 1949, 328};

  book1.print();
  book2.print();

  return 0;
}
