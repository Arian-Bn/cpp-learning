#include <iostream>

class Employee {
protected:
  std::string name;
  int id;

public:
  Employee(std::string name, int id) : name(name), id(id) {}
  virtual ~Employee() = default;
  virtual double calculateSalary() const = 0;
  virtual void getInfo() const = 0;
};

class FullTimeEmployee : public Employee {
private:
  double monthlySalary;

public:
  FullTimeEmployee(std::string name, int id, double monthlySalary)
      : Employee(name, id), monthlySalary(monthlySalary) {}
  double calculateSalary() const override { return monthlySalary; }
  void getInfo() const override {
    std::cout << "Full time employee\t\t";
    std::cout << "Name: " << name << "\t" << "ID: " << id << "\t"
              << "Monthly salary: " << monthlySalary << std::endl;
  }
};

class PartTimeEmployee : public Employee {
private:
  double hourlyRate;
  int hoursWorked;

public:
  PartTimeEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
      : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
  double calculateSalary() const override { return hourlyRate * hoursWorked; }
  void getInfo() const override {
    std::cout << "Part time employee\t\t";
    std::cout << "Name: " << name << "\t" << "ID: " << id << "\t"
              << "Hourly rate: " << hourlyRate << "\t"
              << "Salary: " << calculateSalary() << std::endl;
  }
};

class Manager : public Employee {
private:
  double baseSalary;
  double bonus;

public:
  Manager(std::string name, int id, double baseSalary, double bonus)
      : Employee(name, id), baseSalary(baseSalary), bonus(bonus) {}
  double calculateSalary() const override { return baseSalary + bonus; }
  void getInfo() const override {
    std::cout << "Manager\t\t";
    std::cout << "Name: " << name << "\t" << "ID: " << id << "\t"
              << "Base salary: " << baseSalary << "\t" << "Bonus: " << bonus
              << "\t" << "Salary: " << calculateSalary() << std::endl;
  }
};

int main() {
  double sumSalary = 0;

  // Create employees
  FullTimeEmployee emp_1("John Smith", 1, 50000);
  FullTimeEmployee emp_2("Sophia Muller", 2, 45000);
  PartTimeEmployee emp_3("Maria Garcia", 3, 500, 80);
  PartTimeEmployee emp_4("David Wilson", 4, 400, 120);
  Manager emp_5("Alex Chen", 5, 70000, 15000);

  // Array of pointers to base class
  Employee *allEmp[] = {&emp_1, &emp_2, &emp_3, &emp_4, &emp_5};

  // Display all employees using polymorphism
  std::cout << "=== EMPLOYEE INFORMATION ===" << std::endl << std::endl;
  for (const auto &emp : allEmp) {
    emp->getInfo();
    sumSalary += emp->calculateSalary();
  }

  std::cout << "\nSum salary is: " << sumSalary << std::endl;

  return 0;
}
