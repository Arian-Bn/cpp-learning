#include <iostream>

class BasicCalculator {
public:
  // Base method that adds two numbers
  int calculate(int a, int b) { return a + b; }

  // Method that shows calculation using the current calculate() method
  void showCalculation(int a, int b) {
    std::cout << a << " + " << b << " = " << calculate(a, b) << std::endl;
  }
};

class AdvanceCalculor : public BasicCalculator {
public:
  // This hides the base class calculate() method
  // It multiplies instead of adding
  int calculate(int a, int b) { return a * b; }

  // Demonstrates method hiding and accessing the hidden base method
  void demonstrateHiding(int a, int b) {
    // Calls the hiding method (current class version)
    std::cout << "Multiplication (current): " << calculate(a, b) << std::endl;

    // Explicitly calls the hidden base class method
    std::cout << "Addition (base class): " << BasicCalculator::calculate(a, b)
              << std::endl;

    // Calls inherited method - uses BasicCalculator::calculate() inside
    // because calculate() is not virtual (static binding)
    showCalculation(a, b);
  }
};

int main() {
  AdvanceCalculor calc;
  calc.demonstrateHiding(1, 2);

  return 0;
}
