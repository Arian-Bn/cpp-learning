#include <iostream>

/**
 * ЗАДАЧА: Класс Student с глубоким копированием
 *
 * ЦЕЛЬ: Продемонстрировать важность глубокого копирования при работе
 *       с динамической памятью в конструкторе копирования.
 *
 * ОПИСАНИЕ ПРОБЛЕМЫ:
 * - При поверхностном копировании объектов с указателями
 * - Оба объекта указывают на одну область памяти
 * - Изменения в одном объекте влияют на другой
 * - При удалении одного объекта второй остаётся с висячим указателем
 *
 * РЕШЕНИЕ:
 * - Реализовать конструктор копирования с глубоким копированием
 * - Создавать новый массив в куче для каждого объекта
 * - Копировать все элементы из исходного массива
 *
 * КЛЮЧЕВЫЕ МОМЕНТЫ:
 * 1. Динамическое выделение памяти в конструкторе
 * 2. Глубокое копирование в конструкторе копирования
 * 3. Корректное освобождение памяти в деструкторе
 * 4. Демонстрация независимости объектов после копирования
 */

class Student {
private:
  std::string name;
  int *grades;
  int gradesCount;

public:
  // Основной конструктор
  Student(std::string newName, int *newGreades, int newCount)
      : name(newName), gradesCount(newCount) {
    grades = new int[gradesCount];
    for (unsigned i = 0; i < gradesCount; i++)
      *(grades + i) = *(newGreades + i);
  }

  // Конструктор копирования (глубокое копирование)
  Student(const Student &oth) : name(oth.name), gradesCount(oth.gradesCount) {
    grades = new int[gradesCount];
    for (unsigned i = 0; i < gradesCount; i++)
      *(grades + i) = *(oth.grades + i);
  }

  // Деструктор
  ~Student() { delete[] grades; }

  // Установка оценки по индексу
  void setGrade(int index, int value) {
    if (index >= 0 && index < gradesCount)
      *(grades + index) = value;
  }

  // Вывод информации о студенте
  void print() {
    std::cout << name << "\t";

    for (unsigned i = 0; i < gradesCount; i++) {
      std::cout << *(grades + i) << "\t";
    }

    std::cout << std::endl;
  }
};

int main() {
  // Исходные данные первого студента
  int grades1[] = {4, 5, 4};

  // Создание объектов
  Student student_1("Tom", grades1, 3);
  Student student_2 = student_1;

  // Демонстрация исходного состояния
  std::cout << "До изменения:" << std::endl;
  student_1.print();
  student_2.print();

  // Изменение оценки только у первого студента
  student_1.setGrade(2, 2);

  // Демонстрация независимости объектов
  std::cout << "\nПосле изменения оценки у первого студента:" << std::endl;
  student_1.print();
  student_2.print();

  std::cout << "\nДемонстрация завершена: объекты независимы!" << std::endl;

  return 0;
}

