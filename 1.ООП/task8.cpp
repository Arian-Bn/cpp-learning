#include <iostream>

// ЗАДАЧА: Реализовать систему доступа к секретным данным с использованием
// дружественных классов
//
// Требования:
// 1. Создать класс Secret с приватным полем secretCode
// 2. Создать класс Agent с методом getSecret(), который может читать secretCode
// 3. Сделать класс Agent дружественным для класса Secret
// 4. Продемонстрировать работу системы в main()

// Объявление класса Secret (необходимо для корректной компиляции)

class Secret;

class Agent {
public:
  Agent() {}
  int getSecret(const Secret &);
};

class Secret {
  friend class Agent;

public:
  Secret(int nSecretCode) : secretCode(nSecretCode) {}

private:
  int secretCode;
};

int Agent::getSecret(const Secret &se) { return se.secretCode; }

int main() {
  Secret secretCodeOne(404);
  Agent agent;
  std::cout << "Secret code is: " << agent.getSecret(secretCodeOne);

  return 0;
}
