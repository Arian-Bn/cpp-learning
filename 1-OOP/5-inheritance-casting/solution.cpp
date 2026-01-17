#include <iostream>

class Person {
protected:
  std::string name;

public:
  Person(std::string name) : name(name) {}
  virtual ~Person() = default; // Virtual destructor for proper cleanup
  virtual void print() const { std::cout << name << std::endl; }

  std::string getName() const { return name; }
};

class Employee : public Person {
protected:
  std::string position;

public:
  Employee(std::string name, std::string position)
      : Person(name), position(position) {}
  void print() const override { // Override Person::print()
    std::cout << getName() << "\t" << position << std::endl;
  }

  std::string getPosition() const { return position; }
};

class Manager : public Employee {
protected:
  std::string department;

public:
  Manager(std::string name, std::string position, std::string department)
      : Employee(name, position), department(department) {}
  void print() const override {
    std::cout << getName() << "\t" << getPosition() << "\t" << department
              << std::endl;
  }
  std::string getDepartment() const { return department; }
};

int main() {
  // 1. Automatic upcast - safe conversion from derived to base
  Employee emp("Anna", "Developer");
  Person *personPtr = &emp; // Upcast: Employee* → Person* (implicit)
  personPtr->print();       // Polymorphic call to Employee::print()

  // 2. Downcast with static_cast - safe when object is actually of target type
  Employee *empPtr = static_cast<Employee *>(personPtr); // Person* → Employee*
  std::cout << empPtr->getPosition() << std::endl;

  // 3. Dangerous downcast - undefined behavior!
  Person guest("Guest");
  Person *maybeManager = &guest;

  // Static_cast allows this but object is not a Manager
  Manager *badManagerPtr = static_cast<Manager *>(maybeManager); // WRONG!

  // Calling methods on badManagerPtr would be undefined behavior
  std::cout << "Dangerous cast performed (methods not called)" << std::endl;

  return 0;
}
