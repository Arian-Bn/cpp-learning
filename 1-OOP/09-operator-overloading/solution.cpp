#include <cstdlib> // for abs()
#include <iostream>
#include <stdexcept> // for std::invalid_argument

class Fraction {
private:
  int num; // numerator
  int den; // denominator

  // Reduce fraction to lowest terms using Euclidean algorithm
  void reduce() {
    int a = abs(num);
    int b = abs(den);

    // Find greatest common divisor (GCD)
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    int gcd = a;

    // Simplify fraction
    num /= gcd;
    den /= gcd;

    // Ensure denominator is positive (sign stays in numerator)
    if (den < 0) {
      num = -num;
      den = -den;
    }
  }

public:
  // Default constructor: creates 1/1
  Fraction() : num(1), den(1) {}

  // Parameterized constructor
  Fraction(int n, int d) : num(n), den(d) {
    if (d == 0)
      throw std::invalid_argument("Denominator cannot be zero!");
    reduce(); // automatically reduce on creation
  }

  // Print fraction in "a/b" format (legacy method)
  void print() const { std::cout << num << "/" << den << std::endl; }

  // ARITHMETIC OPERATORS

  // Addition: a/b + c/d = (a*d + b*c)/(b*d)
  Fraction operator+(const Fraction &other) const {
    return Fraction{num * other.den + den * other.num, den * other.den};
  }

  // Subtraction: a/b - c/d = (a*d - b*c)/(b*d)
  Fraction operator-(const Fraction &other) const {
    return Fraction{num * other.den - den * other.num, den * other.den};
  }

  // Multiplication: (a/b) * (c/d) = (a*c)/(b*d)
  Fraction operator*(const Fraction &other) const {
    return Fraction{num * other.num, den * other.den};
  }

  // Division: (a/b) / (c/d) = (a*d)/(b*c)
  Fraction operator/(const Fraction &other) const {
    // Note: constructor will handle division by zero check
    return Fraction{num * other.den, den * other.num};
  }

  // COMPARISON OPERATORS

  // Equality: a/b == c/d if a*d == b*c
  bool operator==(const Fraction &other) const {
    return (num * other.den == den * other.num);
  }

  // Inequality
  bool operator!=(const Fraction &other) const { return !(*this == other); }

  // Less than: a/b < c/d if a*d < b*c
  bool operator<(const Fraction &other) const {
    return (num * other.den < den * other.num);
  }

  // Greater than: a/b > c/d if a*d > b*c
  bool operator>(const Fraction &other) const {
    return (num * other.den > den * other.num);
  }

  // Less than or equal (using greater than operator)
  bool operator<=(const Fraction &other) const { return !(*this > other); }

  // Greater than or equal (using less than operator)
  bool operator>=(const Fraction &other) const { return !(*this < other); }

  // COMPOUND ASSIGNMENT OPERATORS

  // Addition with assignment
  Fraction &operator+=(const Fraction &other) {
    num = num * other.den + den * other.num;
    den = den * other.den;
    reduce();
    return *this;
  }

  // Subtraction with assignment
  Fraction &operator-=(const Fraction &other) {
    num = num * other.den - den * other.num;
    den = den * other.den;
    reduce();
    return *this;
  }

  // Multiplication with assignment
  Fraction &operator*=(const Fraction &other) {
    num = num * other.num;
    den = den * other.den;
    reduce();
    return *this;
  }

  // Division with assignment
  Fraction &operator/=(const Fraction &other) {
    num = num * other.den;
    den = den * other.num;
    reduce();
    return *this;
  }

  // UNARY OPERATORS

  // Unary minus: returns negative fraction
  Fraction operator-() const { return Fraction{-num, den}; }

  // Unary plus: returns copy of fraction
  Fraction operator+() const { return *this; }

  // INCREMENT/DECREMENT OPERATORS

  // Prefix increment: adds 1 (which is den/den)
  Fraction &operator++() {
    num = num + den; // +1 = +den/den
    reduce();
    return *this;
  }

  // Prefix decrement: subtracts 1
  Fraction &operator--() {
    num = num - den; // -1 = -den/den
    reduce();
    return *this;
  }

  // Postfix increment: returns old value, then increments
  Fraction operator++(int) {
    Fraction copy(*this);
    ++(*this); // use prefix version
    return copy;
  }

  // Postfix decrement: returns old value, then decrements
  Fraction operator--(int) {
    Fraction copy(*this);
    --(*this); // use prefix version
    return copy;
  }

  // TYPE CONVERSION

  // Convert fraction to double (implicit conversion)
  operator double() const { return static_cast<double>(num) / den; }

  // ACCESSORS

  // Get numerator
  int getNum() const { return num; }

  // Get denominator
  int getDen() const { return den; }

  // FRIEND FUNCTION

  // Output stream operator (friend for direct access to private members)
  friend std::ostream &operator<<(std::ostream &, const Fraction &);
};

// Output stream operator implementation
std::ostream &operator<<(std::ostream &os, const Fraction &f) {
  os << f.num << "/" << f.den;
  return os; // return stream for chaining
}

// Main demonstration function
int main() {
  std::cout << "=== FRACTION CLASS DEMONSTRATION ===\n" << std::endl;

  // 1. Create basic fractions
  std::cout << "1. Creating fractions:" << std::endl;
  Fraction half(1, 2);
  Fraction third(1, 3);
  std::cout << "   half = " << half << std::endl;
  std::cout << "   third = " << third << std::endl;

  // 2. Basic arithmetic operations
  std::cout << "\n2. Basic arithmetic:" << std::endl;
  Fraction sum = half + third;
  Fraction difference = half - third;
  Fraction product = half * third;
  Fraction quotient = half / third;

  std::cout << "   " << half << " + " << third << " = " << sum << std::endl;
  std::cout << "   " << half << " - " << third << " = " << difference
            << std::endl;
  std::cout << "   " << half << " * " << third << " = " << product << std::endl;
  std::cout << "   " << half << " / " << third << " = " << quotient
            << std::endl;

  // 3. Comparison operators
  std::cout << "\n3. Comparisons:" << std::endl;
  Fraction twoQuarters(2, 4); // same as 1/2
  std::cout << "   " << half << " == " << third << " ? " << std::boolalpha
            << (half == third) << std::endl;
  std::cout << "   " << half << " != " << third << " ? " << (half != third)
            << std::endl;
  std::cout << "   " << half << " == " << twoQuarters << " ? "
            << (half == twoQuarters) << std::endl;
  std::cout << "   " << half << " < " << third << " ? " << (half < third)
            << std::endl;
  std::cout << "   " << half << " > " << third << " ? " << (half > third)
            << std::endl;

  // 4. Compound assignment operators
  std::cout << "\n4. Compound assignments:" << std::endl;
  Fraction a(1, 2);
  std::cout << "   Start: a = " << a << std::endl;

  a += third;
  std::cout << "   After a += " << third << ": a = " << a << std::endl;

  a = Fraction(1, 2); // reset
  a -= third;
  std::cout << "   After a -= " << third << ": a = " << a << std::endl;

  a = Fraction(1, 2); // reset
  a *= third;
  std::cout << "   After a *= " << third << ": a = " << a << std::endl;

  a = Fraction(1, 2); // reset
  a /= third;
  std::cout << "   After a /= " << third << ": a = " << a << std::endl;

  // 5. Unary operators
  std::cout << "\n5. Unary operators:" << std::endl;
  Fraction f(3, 4);
  std::cout << "   Original: f = " << f << std::endl;
  std::cout << "   Unary plus: +f = " << +f << std::endl;
  std::cout << "   Unary minus: -f = " << -f << std::endl;

  // 6. Increment and decrement
  std::cout << "\n6. Increment/decrement operators:" << std::endl;
  Fraction counter(3, 4);
  std::cout << "   Start: counter = " << counter << std::endl;

  Fraction preInc = ++counter;
  std::cout << "   Prefix ++: ++counter = " << preInc
            << ", counter now = " << counter << std::endl;

  Fraction postInc = counter++;
  std::cout << "   Postfix ++: counter++ = " << postInc
            << ", counter now = " << counter << std::endl;

  Fraction preDec = --counter;
  std::cout << "   Prefix --: --counter = " << preDec
            << ", counter now = " << counter << std::endl;

  Fraction postDec = counter--;
  std::cout << "   Postfix --: counter-- = " << postDec
            << ", counter now = " << counter << std::endl;

  // 7. Type conversion
  std::cout << "\n7. Type conversion to double:" << std::endl;
  Fraction frac(3, 8);
  double decimal = frac;
  std::cout << "   Fraction: " << frac << std::endl;
  std::cout << "   As double: " << decimal << std::endl;
  std::cout << "   In expression: " << frac << " * 2.5 = " << (decimal * 2.5)
            << std::endl;

  // 8. Getters demonstration
  std::cout << "\n8. Accessing components:" << std::endl;
  Fraction example(5, 9);
  std::cout << "   Fraction: " << example << std::endl;
  std::cout << "   Numerator: " << example.getNum() << std::endl;
  std::cout << "   Denominator: " << example.getDen() << std::endl;

  // 9. Complex expression demonstration
  std::cout << "\n9. Complex expression:" << std::endl;
  Fraction x(1, 4);
  Fraction y(2, 5);
  Fraction z(3, 7);

  Fraction result = (x + y) * z - Fraction(1, 10);
  std::cout << "   (" << x << " + " << y << ") * " << z
            << " - 1/10 = " << result << std::endl;
  std::cout << "   As decimal: " << static_cast<double>(result) << std::endl;

  std::cout << "\n=== END OF DEMONSTRATION ===" << std::endl;

  return 0;
}
