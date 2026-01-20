#include <iostream>
#include <memory>
#include <string>

class Animal {
private:
  std::string name;

public:
  // Constructor with const reference parameter
  Animal(const std::string &name) : name(name) {}

  // Virtual function for polymorphism behavior
  virtual void makeSound() const { std::cout << name << std::endl; }

  // Virtual destructor for proper cleanup
  virtual ~Animal() {
    std::cout << "Animal " << name << " deleted." << std::endl;
  }

  // Getter method
  std::string getName() const { return name; }
};

class Dog : public Animal {
public:
  Dog(const std::string &name) : Animal(name) {}

  // Override virtual function
  virtual void makeSound() const override {
    std::cout << getName() << " Says: Gov-Gov!" << std::endl;
  }
  virtual ~Dog() { std::cout << "Deleted " << getName() << std::endl; }
};

class Cat : public Animal {
public:
  Cat(const std::string &name) : Animal(name) {}
  virtual void makeSound() const override {
    std::cout << getName() << "Says: Muo-Mou" << std::endl;
  }
  virtual ~Cat() { std::cout << "Deleted " << getName() << std::endl; }
};

int main() {
  // Array for smart pointers to base class
  std::unique_ptr<Animal> animals[2];

  // Dynamic allocation with polymorphism
  animals[0] = std::make_unique<Dog>("Rex");
  animals[1] = std::make_unique<Cat>("Whiskers");

  // Demonstrates dynamic binding
  for (const auto &animal : animals)
    animal->makeSound();

  return 0;
  // Smart pointers automatically delete objects here
  // Virtual destructors ensure proper cleanup order
}
