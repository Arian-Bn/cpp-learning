#include <iostream>
#include <math.h>

class Shape {
public:
  virtual double area() const { return 0.0; }

  virtual double perimeter() const { return 0.0; }

  virtual ~Shape() {}

  void printInfo() const {
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
  }
};

class Rectangle : public Shape {
public:
  Rectangle(double width, double height) : width(width), height(height) {}

  double area() const override { return width * height; }

  double perimeter() const override { return width + height; }

private:
  double width;
  double height;
};

class Circle : public Shape {
public:
  Circle(double radius) : radius(radius) {}

  double area() const override { return PI * radius * radius; }

  double perimeter() const override { return PI * radius * 2; }

private:
  double radius;
  const double PI = 3.14159;
};

class Triangle : public Shape {
public:
  Triangle(double side) : side(side) {}

  double area() const override { return (side * side * sqrt(3)) / 4.0; }

  double perimeter() const override { return 3 * side; }

private:
  double side;
};

int main() {
  Rectangle rect(5, 3);
  Circle circle(4);
  Triangle triangle(6);

  std::cout << "Direct calls:" << std::endl;
  std::cout << "Rectangle are: " << rect.area() << std::endl;
  std::cout << "Circle area: " << circle.area() << std::endl;

  Shape *shapes[3];
  shapes[0] = new Rectangle(5, 3);
  shapes[1] = new Circle(4);
  shapes[2] = new Triangle(6);

  for (int i = 0; i < 3; i++) {
    std::cout << "Shape " << i << " area: " << shapes[i]->area() << std::endl;
    std::cout << "Shape " << i << " perimeter: " << shapes[i]->perimeter()
              << std::endl;
    shapes[i]->printInfo();
    std::cout << "---" << std::endl;
  }

  return 0;
}
