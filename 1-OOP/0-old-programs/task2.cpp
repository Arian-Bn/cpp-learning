#include <iostream>

/*
ЗАДАНИЕ: Класс "Банковский счет" с инкапсуляцией

Цель задания:
Закрепить понимание принципов инкапсуляции, управления доступом и разделения
объявления и реализации методов в C++.

Теоретическая основа:
- Инкапсуляция - сокрытие внутренней реализации класса и предоставление
  контролируемого интерфейса для работы с ним
- Спецификаторы доступа: private (закрытый доступ), public (открытый доступ)
- Геттеры и сеттеры - методы для контролируемого доступа к закрытым полям
- Разделение объявления и реализации - улучшение читаемости и организации кода

Требования к реализации:

1. Создать класс BankAccount с соблюдением принципов инкапсуляции

2. Закрытые поля (private):
   - accountNumber (string) - номер счета
   - balance (double) - текущий баланс
   - ownerName (string) - имя владельца счета

3. Публичные методы (public):
   - Конструктор, принимающий номер счета, имя владельца и начальный баланс
   - deposit(amount) - пополнение счета (только положительные суммы)
   - withdraw(amount) - снятие денег (нельзя снять больше, чем есть на счету,
     и отрицательные суммы)
   - getBalance() - получить текущий баланс
   - getAccountInfo() - получить информацию о счете (номер, владелец, баланс)
   - setOwnerName(newName) - изменить имя владельца (нельзя установить пустое
имя)

4. Дополнительные требования:
   - Разделить объявление класса и реализацию методов
   - Добавить проверки для всех операций
   - Создать несколько счетов и продемонстрировать работу всех методов

5. Пример использования в main():
   BankAccount account("123456789", "Иван Иванов", 1000.0);
   account.deposit(500.0);
   account.withdraw(200.0);
   account.setOwnerName("Иван Петров");
   account.getAccountInfo();

Критерии проверки:
- Все поля класса должны быть закрыты (private)
- Должны быть реализованы все указанные методы
- Реализованы корректные проверки входных данных
- Объявление и реализация методов разделены
- Код демонстрирует работу всех методов
- Используются принципы инкапсуляции

Инструкция:
1. Создай класс BankAccount с указанными требованиями
2. Реализуй все методы с проверками
3. Раздели объявление и реализацию
4. Напиши демонстрационную программу в main()
5. Протестируй все возможные сценарии
*/

class BankAccount {
private:
  std::string ownerName;
  std::string accountNumber;
  double balance;

public:
  BankAccount(std::string nAccountNumber, std::string nOwnerName,
              double nBalance);
  void deposit(double amount);
  bool withdraw(double amount);
  double getBalance() const;
  void getAccountInfo() const;
  void setOwnerName(std::string newName);
  std::string getAccountNumber() const;
  std::string getOwnerName() const;
};

// Реализация конструктора
BankAccount::BankAccount(std::string nAccountNumber, std::string nOwnerName,
                         double nBalance) {
  // Проверка номера счета
  if (nAccountNumber.empty()) {
    accountNumber = "DEFAULT_ACC";
    std::cout << "Ошибка! Номер счёта не может быть пустым!" << std::endl;
  } else {
    accountNumber = nAccountNumber;
  }

  // Проверка имени владельца
  if (nOwnerName.empty()) {
    ownerName = "Unknown";
    std::cout << "Ошибка! Имя владельца не может быть пустым!" << std::endl;
  } else {
    ownerName = nOwnerName;
  }

  // Проверка баланса
  if (nBalance < 0) {
    balance = 0.0;
    std::cout << "Ошибка! Баланс не может быть отрицательным!" << std::endl;
  } else {
    balance = nBalance;
  }
}

void BankAccount::deposit(double amount) {
  if (amount <= 0.0) {
    std::cout << "Ошибка! Сумма пополнения должна быть положительной!"
              << std::endl;
  } else {
    balance += amount;
    std::cout << "Успешно пополнено: " << amount << std::endl;
  }
}

bool BankAccount::withdraw(double amount) {

  if (amount <= 0) {
    std::cout << "Ошибка! Cумма снятия должна быть положительной!" << std::endl;
    return false;
  }

  if (amount > balance) {
    std::cout << "Ошибка! Недостаточно средств на счёте!" << std::endl;
    return false;
  }

  balance -= amount;
  std::cout << "Успешно снято: " << amount << std::endl;
  return true;
}

double BankAccount::getBalance() const { return balance; }

void BankAccount::getAccountInfo() const {
  std::cout << "=== ИНФОРМАЦИЯ О СЧЕТЕ ===" << std::endl;
  std::cout << "Номер: " << accountNumber << std::endl;
  std::cout << "Владелец: " << ownerName << std::endl;
  std::cout << "Баланс: " << balance << std::endl;
  std::cout << "==========================" << std::endl;
}

void BankAccount::setOwnerName(std::string newName) {
  if (newName.empty()) {
    std::cout << "Ошибка! Имя владельца не может быть пустым!" << std::endl;
  } else {
    ownerName = newName;
    std::cout << "Имя владельца успешно изменено на: " << newName << std::endl;
  }
}

std::string BankAccount::getAccountNumber() const { return accountNumber; }

std::string BankAccount::getOwnerName() const { return ownerName; }

int main() {
  // Демонстрация работы класса
  std::cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА BANKACCOUNT ===" << std::endl;

  // Создание счетов
  BankAccount account1("123456789", "Иван Иванов", 1000.0);
  BankAccount account2("987654321", "Мария Петрова", 500.0);

  std::cout << "\n--- Тестирование счета 1 ---" << std::endl;
  account1.getAccountInfo();
  account1.deposit(500.0);
  account1.withdraw(200.0);
  account1.setOwnerName("Иван Петров");
  account1.getAccountInfo();

  std::cout << "\n--- Тестирование счета 2 ---" << std::endl;
  account2.deposit(-100.0);  // Тест отрицательного пополнения
  account2.withdraw(1000.0); // Тест снятия больше баланса
  account2.setOwnerName(""); // Тест пустого имени
  account2.getAccountInfo();

  std::cout << "\n--- Демонстрация геттеров ---" << std::endl;
  std::cout << "Счет 1 - Номер: " << account1.getAccountNumber()
            << ", Владелец: " << account1.getOwnerName()
            << ", Баланс: " << account1.getBalance() << std::endl;

  return 0;
}
