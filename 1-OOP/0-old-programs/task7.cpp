#include <iostream>

/*
ЗАДАЧА: "Умный Счётчик" (SmartCounter)

ЦЕЛЬ: Реализовать класс SmartCounter, демонстрирующий использование:
1. Ключевого слова 'this' для работы с текущим объектом
2. Дружественных функций для доступа к приватным членам

ТРЕБОВАНИЯ К КЛАССУ:

1. ПРИВАТНЫЕ ЧЛЕНЫ:
   - int value: целочисленное значение счетчика

2. ПУБЛИЧНЫЕ МЕТОДЫ:
   - Конструкторы:
        SmartCounter() - инициализация 0
        SmartCounter(int) - инициализация переданным значением
   - increment(): увеличивает value на 1, возвращает *this
   - decrement(): уменьшает value на 1, возвращает *this
   - reset(): сбрасывает value в 0, возвращает *this
   - getValue(): возвращает текущее значение

3. ДРУЖЕСТВЕННАЯ ФУНКЦИЯ:
   - compare(): принимает два константных объекта SmartCounter,
     возвращает ссылку на объект с большим значением value

ОЖИДАЕМОЕ ПОВЕДЕНИЕ:
- Методы increment/decrement/reset позволяют цепочку вызовов через return *this
- Дружественная функция compare имеет доступ к приватному полю value
- Программа демонстрирует работу цепочки вызовов и сравнения объектов

ПРИМЕР ИСПОЛЬЗОВАНИЯ:
SmartCounter counter(5);
counter.increment().increment().decrement(); // value = 6
counter.reset().increment();                 // value = 1

SmartCounter a(7), b(10);
const SmartCounter& winner = compare(a, b); // winner = b (value = 10)
*/

class SmartCounter {

  friend const SmartCounter &compare(const SmartCounter &,
                                     const SmartCounter &);

private:
  int value;

public:
  SmartCounter() { this->value = 0; }

  SmartCounter(int value) { this->value = value; }

  SmartCounter &increment() {
    this->value += 1;
    return *this;
  }

  SmartCounter &decrement() {
    this->value -= 1;
    return *this;
  }

  int getValue() const { return value; }

  SmartCounter &reset() {
    this->value = 0;
    return *this;
  }
};

const SmartCounter &compare(const SmartCounter &firstValue,
                            const SmartCounter &secondValue) {
  return (firstValue.value >= secondValue.value) ? firstValue : secondValue;
}

int main() {
  SmartCounter counter(5);

  counter.increment().increment().decrement();
  std::cout << counter.getValue() << std::endl;

  counter.reset().increment();
  std::cout << counter.getValue() << std::endl;

  SmartCounter a(7);
  SmartCounter b(10);

  const SmartCounter &winner = compare(a, b);
  std::cout << "The counter with the larger value is: " << winner.getValue()
            << std::endl;

  return 0;
}
