#include <iostream>

/*
 * Задача: Класс SmartCounter с цепочками вызовов
 *
 * Цель: Реализовать класс счётчика, поддерживающий цепочки методов (method
 * chaining) с использованием ключевого слова this.
 *
 * Требования:
 * - Конструкторы с параметром и по умолчанию
 * - Методы add(), subtract(), multiply(), reset() должны возвращать ссылку на
 * текущий объект
 * - Метод getValue() для получения значения
 * - Метод print() для вывода значения
 * - Поддержка цепочек вызовов: obj.add(5).subtract(3).multiply(2)
 *
 * Пример использования:
 * SmartCounter counter(10);
 * counter.add(5).subtract(3).multiply(2).print(); // Вывод: Counter: 24
 *
 * Реализация демонстрирует:
 * - Использование this для обращения к полям класса
 * - Возврат *this для построения цепочек методов
 * - Const-корректность методов
 * - Списки инициализации в конструкторах
 */

class SmartCounter {
private:
  int value;

public:
  SmartCounter(int startValue) : value(startValue) {}

  SmartCounter() : value(0) {}

  SmartCounter &add(int value) {
    this->value += value;
    return *this;
  }

  SmartCounter &subtract(int value) {
    this->value -= value;
    return *this;
  }

  SmartCounter &multiply(int value) {
    this->value *= value;
    return *this;
  }

  SmartCounter &reset() {
    this->value = 0;
    return *this;
  }

  int getValue() const { return value; }

  void print() const { std::cout << "Counter: " << value << std::endl; }
};

int main() {
  SmartCounter num1{20};
  SmartCounter num;

  num1.add(10).subtract(5).multiply(4).print();
  num.add(20).print();
  num.reset();
  std::cout << "Counter: " << num.getValue() << std::endl;

  return 0;
}
