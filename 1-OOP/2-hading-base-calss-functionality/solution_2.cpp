#include <iostream>
#include <string>

class Animal {
protected:
  std::string name; // Base class protected field

public:
  void makeSound() const { std::cout << "Some generic sound" << std::endl; }

  // Constructor with default parameter
  Animal(const std::string &name_ = "Unknown") : name(name_) {}

  // Public getter for protected field
  std::string getName() const { return name; }
};

class Dog : public Animal {
private:
  std::string name; // Hides Animal::name - field hiding

public:
  // Initialize both base and derived fields
  Dog(const std::string &nameAn, const std::string &nameDo)
      : Animal(nameAn), name(nameDo) {}

  // Method hiding - hides Animal::makeSound()
  void makeSound() const { std::cout << "Woof!" << std::endl; }

  // Demonstrate field hiding with scope resolution
  void showNameDirect() const {
    std::cout << "Base name (Animal::name): " << Animal::name << std::endl;
    std::cout << "Derived name (Dog::name): " << name << std::endl;
  }

  // Demonstrate both field and method hiding
  void showBothName() const {
    // Access base field via getter
    std::cout << "Animal name via getter: " << Animal::getName() << std::endl;
    std::cout << "Dog name (direct): " << name << std::endl;

    // Demonstrate method hiding
    std::cout << "Dog sound (current class): ";
    makeSound(); // Calls Dog::makeSound()

    std::cout << "Animal sound (base class): ";
    Animal::makeSound(); // Explicitly calls Animal::makeSound()
  }
};

int main() {
  Dog dog("GenericAnimal", "Rex");

  // Show field hiding
  dog.showNameDirect();

  std::cout << "\nMethod hiding demonstration:" << std::endl;
  std::cout << "Current method makeSound(): ";
  dog.makeSound(); // Calls hiding method

  std::cout << "Base class method makeSound(): ";
  dog.Animal::makeSound(); // Explicit base class call

  // Comprehensive demonstration
  std::cout << "\nComplete demonstration:" << std::endl;
  dog.showBothName();

  return 0;
}
