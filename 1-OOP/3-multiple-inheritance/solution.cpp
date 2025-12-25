#include <iostream>

class Clock {
public:
  Clock(int hour, int min) : hour(hour), min(min) {}

  void showTime() const {
    std::cout << "Current time: " << hour << ":" << min << std::endl;
  }

private:
  int hour;
  int min;
};

class FitnessTracker {
public:
  FitnessTracker(int steps) : steps(steps) {}

  void showSteps() const { std::cout << "Steps today: " << steps << std::endl; }

private:
  int steps;
};

class Notifier {
public:
  void showNotification() const {
    std::cout << "New notification!" << std::endl;
  }

  void clearNotification() const {
    std::cout << "Notifications cleared!" << std::endl;
  }
};

// Multiple inheritance from three base classes
class SmartWatch : public Clock, public FitnessTracker, public Notifier {
public:
  // Constructor initializes all base classes
  SmartWatch(int hour, int min, int steps)
      : Clock(hour, min), FitnessTracker(steps) {}

  // Method uses functionality from all parent classes
  void showAll() const {
    showTime();
    showSteps();
    showNotification();
  }
};

int main() {
  SmartWatch smart_3(10, 30, 5000);
  smart_3.showAll();
  smart_3.clearNotification();

  return 0;
}
