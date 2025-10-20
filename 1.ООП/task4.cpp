#include <iostream>

// ЗАДАЧА: Библиотечная система с константными объектами
//
// ЦЕЛЬ: Закрепить работу с константными объектами,
//       константными методами и ключевым словом mutable
//
// ОПИСАНИЕ: Создать класс Book для библиотечной системы.
//           Книги могут быть константными (редкие издания) и обычными
//
// ТРЕБОВАНИЯ К КЛАССУ BOOK:
//
// ПОЛЯ (private):
// - title (string) - название книги
// - author (string) - автор книги
// - year (int) - год издания
// - is_available (bool) - доступна ли для выдачи
// - read_count (mutable int) - счетчик прочтений (должен быть mutable)
//
// КОНСТРУКТОР:
// - Принимает название, автора и год издания
// - is_available инициализируется в true
// - read_count инициализируется в 0
//
// МЕТОДЫ:
//
// Геттеры (все константные):
// - getTitle() возвращает константную ссылку на название
// - getAuthor() возвращает константную ссылку на автора
// - getYear() возвращает указатель на константу года
// - isAvailable() возвращает значение доступности
//
// Основные методы:
// - printInfo() const - выводит полную информацию о книге
// - markAsRead() const - увеличивает счетчик прочтений (работает для
// константных объектов)
// - borrowBook() - помечает книгу как недоступную (НЕ константный)
// - returnBook() - помечает книгу как доступную (НЕ константный)
// - getReadCount() const - возвращает количество прочтений
//
// ЗАДАНИЕ В MAIN():
//
// 1. Создать константный объект Book с названием "1984", автором "George
// Orwell", год 1949
// 2. Создать обычный объект Book с произвольными данными
// 3. Для константной книги:
//    - Вывести информацию о книге
//    - Отметить книгу как прочитанную (2 раза)
//    - Вывести количество прочтений
//    - Попробовать взять книгу на руки (должна быть ошибка компиляции)
//
// 4. Для обычной книги:
//    - Вывести информацию
//    - Взять книгу на руки
//    - Снова вывести информацию (изменилась доступность)
//    - Вернуть книгу
//    - Отметить как прочитанную
//    - Вывести финальную информацию
//
// ЦЕЛИ ЗАДАНИЯ:
// - Практика работы с константными объектами
// - Понимание различий между константными и неконстантными методами
// - Использование mutable для полей, изменяемых в константных методах
// - Правильное возвращение ссылок и указателей из константных методов
//
// ОЖИДАЕМЫЙ РЕЗУЛЬТАТ:
// Программа демонстрирует, какие операции разрешены для константных объектов,
// а какие - нет. Попытка вызвать неконстантный метод для константного объекта
// должна приводить к ошибке компиляции.

class Book {
private:
  std::string title;
  std::string author;
  int year;
  bool is_available;
  mutable int read_count;

public:
  Book(std::string nTitle, std::string nAuthor, int nYear)
      : title(nTitle), author(nAuthor), year(nYear), is_available(true),
        read_count(0) {}

  const std::string &getTitle() const { return title; }

  const std::string &getAuthor() const { return author; }

  const int *getYear() const { return &year; }

  bool isAvailable() const { return is_available; }

  void printInfo() const {
    std::cout << "\n----Information----\n";
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Year: " << *(getYear()) << std::endl;
    std::cout << "Status: " << (isAvailable() ? "Yes" : "No") << std::endl;
  }

  void markAsRead() const { read_count++; }

  void borrowBook() { is_available = false; }

  void returnBook() { is_available = true; }

  int getReadCount() const { return read_count; }
};

int main() {
  const Book book1{"1984", "George Orwell", 1949};
  Book book2{"Clean Code", "Robert Martin", 2008};

  std::cout << "\n=== CONST BOOK DEMO ===";
  book1.printInfo();
  book1.markAsRead();
  book1.markAsRead();
  std::cout << "Total reads: " << book1.getReadCount() << std::endl;
  // book1.borrowBook(); // Compilation error - as expected!

  std::cout << "\n=== REGULAR BOOK DEMO ===";
  book2.printInfo();
  book2.borrowBook();
  book2.printInfo();
  book2.returnBook();
  book2.markAsRead();
  std::cout << "Readed: " << book2.getReadCount() << std::endl;
  book2.printInfo();

  return 0;
}
