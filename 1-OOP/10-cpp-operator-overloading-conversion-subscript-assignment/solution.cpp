#include <iostream>
#include <string>

class Transcript; // Forward declaration for circular dependency

class Course {
private:
  int grades[3];   // Array to store up to 3 grades
  int gradesCount; // Number of actual grades stored (0-3)

public:
  // Constructor with default parameters (-1 means no grade)
  Course(int g1 = -1, int g2 = -1, int g3 = -1) : gradesCount(0) {
    if (g1 >= 0)
      grades[gradesCount++] =
          g1; // Post-increment: use current index, then increment
    if (g2 >= 0)
      grades[gradesCount++] = g2;
    if (g3 >= 0)
      grades[gradesCount++] = g3;
  }

  // Subscript operator for non-const objects (allows modification)
  int &operator[](int index) {
    static int error = -1; // Static variable for error handling

    // Check bounds: index must be between 0 and gradesCount-1
    if (index >= 0 && index < gradesCount) {
      return grades[index]; // Return reference for modification
    } else {
      return error; // Return reference to error value
    }
  }

  // Subscript operator for const objects (read-only)
  const int &operator[](int index) const {
    static const int error = -1;

    if (index >= 0 && index < gradesCount) {
      return grades[index];
    } else {
      return error;
    }
  }

  // Conversion operator to double (average grade)
  operator double() const {
    if (gradesCount == 0) {
      return 0.0; // No grades → average is 0
    }

    int sum = 0;
    for (int i = 0; i < gradesCount; i++)
      sum += grades[i];

    return static_cast<double>(sum) /
           gradesCount; // Cast to double for precise division
  }

  // Explicit conversion to bool (pass/fail status)
  explicit operator bool() const {
    return static_cast<double>(*this) >= 60.0; // Pass if average >= 60
  }

  // Assignment operator with deep copy
  Course &operator=(const Course &other) {
    if (this == &other) // Self-assignment check
      return *this;

    // Copy all 3 grades (deep copy)
    for (int i = 0; i < 3; i++) {
      grades[i] = other.grades[i];
    }
    gradesCount = other.gradesCount; // Copy the count

    return *this; // Return reference for chaining (a = b = c)
  }

  friend class Transcript; // Grant access to private members for Transcript

  // Debug method to print course information
  void print() const {
    std::cout << "Course: ";
    for (int i = 0; i < gradesCount; i++) {
      std::cout << grades[i] << " ";
    }
    std::cout << "(count: " << gradesCount
              << ", avg: " << static_cast<double>(*this) << ")" << std::endl;
  }

  // Declaration of conversion to Transcript (defined later)
  operator Transcript() const;
};

class Transcript {
private:
  Course courseData;    // Copy of the Course object
  bool isPassed;        // Whether the course was passed
  std::string examDate; // Date of the exam

public:
  // Constructor with default values
  Transcript(const Course &course, bool passed = false,
             const std::string &date = "2024-01-30")
      : courseData(course), isPassed(passed), examDate(date) {}

  // Getters
  bool getPassed() const { return isPassed; }
  std::string getDate() const { return examDate; }
  Course getCourse() const { return courseData; }

  // Setters
  void setPassed(bool passed) { isPassed = passed; }
  void setDate(const std::string &date) { examDate = date; }

  // Conversion operator back to Course
  operator Course() const {
    return courseData; // Return a copy of the course data
  }

  // Debug method to print transcript information
  void print() const {
    std::cout << "Transcript:\n";
    std::cout << "  Passed: " << (isPassed ? "Yes" : "No") << "\n";
    std::cout << "  Date: " << examDate << "\n";
    std::cout << "  Course data: ";
    courseData.print();
  }
};

// Definition of Course to Transcript conversion (must be after Transcript
// definition)
Course::operator Transcript() const {
  bool passed =
      static_cast<bool>(*this); // Use bool conversion to determine pass status

  return Transcript(
      *this, passed,
      "2024-01-30"); // Create Transcript with auto-determined status
}

int main() {
  // Test 1: Create course and print
  Course math{75, 80, 85};
  math.print();

  // Test 2: Subscript operator (read and write)
  std::cout << "First grade: " << math[0] << std::endl;
  math[0] = 90;
  std::cout << "After change: ";
  math.print();

  // Test 3: Implicit conversion to double (average)
  double avg = math;
  std::cout << "Average: " << avg << std::endl;

  // Test 4: Explicit conversion to bool (pass/fail)
  if (static_cast<bool>(math))
    std::cout << "Course passed!" << std::endl;

  // Test 5: Assignment operator (deep copy)
  Course physics;
  physics = math;
  std::cout << "Copied course: ";
  physics.print();

  // Test 6: Course to Transcript conversion
  Transcript transcript(math, static_cast<bool>(math));
  transcript.print();

  // Test 7: Transcript to Course conversion
  Course extracted = static_cast<Course>(transcript);
  std::cout << "Extracted course: ";
  extracted.print();

  // Test 8: Failed course
  Course failed(45, 50, 55);
  if (!static_cast<bool>(failed))
    std::cout << "Failed course (as expected)" << std::endl;

  // Test 9: Invalid index handling
  std::cout << "Invalid index: " << math[10] << std::endl;

  return 0;
}
