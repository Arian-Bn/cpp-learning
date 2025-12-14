#include <iostream>

/*
 * =============================================================================
 * ПРАКТИЧЕСКАЯ ЗАДАЧА: СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ И КУРСАМИ
 * =============================================================================
 *
 * ЦЕЛЬ: Реализовать систему управления студентами и курсами университета
 *       с использованием принципов объектно-ориентированного программирования
 *       ВСЕ КЛАССЫ РЕАЛИЗОВАТЬ В ОДНОМ ФАЙЛЕ (main.cpp)
 *
 * ТРЕБУЕМЫЕ ТЕМЫ:
 * Определение классов
 * Конструкторы и инициализация объектов
 * Управление доступом. Инкапсуляция
 * Объявление и определение функций класса
 * Конструктор копирования
 *
 * =============================================================================
 * ОПИСАНИЕ КЛАССОВ:
 * =============================================================================
 *
 * КЛАСС Student
 * --------------
 * ПОЛЯ (private):
 * - studentId: int (уникальный идентификатор студента)
 * - name: std::string (имя студента)
 * - email: std::string (email студента)
 *
 * МЕТОДЫ (public):
 * - Конструкторы: по умолчанию, параметризированный, копирования
 * - Геттеры: getId(), getName(), getEmail()
 * - Сеттеры: setName(), setEmail()
 * - displayInfo(): вывод информации о студенте
 *
 * КЛАСС Course
 * --------------
 * ПОЛЯ (private):
 * - courseCode: std::string (код курса, например "CS101")
 * - courseName: std::string (название курса)
 * - maxStudents: int (максимальное количество студентов)
 * - studentCount: int (текущее количество студентов)
 *
 * МЕТОДЫ (public):
 * - Конструкторы: по умолчанию, параметризированный, копирования
 * - Геттеры: getCourseCode(), getCourseName(), getMaxStudents(), getStudentCount()
 * - Сеттеры: setCourseName(), setMaxStudents()
 * - addStudent(): увеличение счетчика студентов (с проверкой лимита)
 * - displayInfo(): вывод информации о курсе
 *
 * =============================================================================
 * ТРЕБОВАНИЯ К РЕАЛИЗАЦИИ:
 * =============================================================================
 *
 * 1. ИНКАПСУЛЯЦИЯ:
 *    - Все поля классов должны быть private
 *    - Доступ через public методы (геттеры/сеттеры)
    *
 * 2. КОНСТРУКТОР КОПИРОВАНИЯ:
 *    - Реализовать глубокое копирование объектов
 *    - Корректно копировать все поля
 *
 * 3. ПРОВЕРКИ:
 *    - Проверка лимита студентов при добавлении на курс
 *    - Валидация данных в сеттерах
 *
 * =============================================================================
 */

class Student {
private:
    int studentId;
    std::string name;
    std::string email;

public:
    Student () : studentId(0), name(""), email("") {}

    Student(int id, std::string nName, std::string nEmail) : studentId(id), name(nName), email((nEmail)) {}

    Student (const Student& other) : studentId((other.studentId)), name(other.name), email(other.email) {}

    int getId () const {
        return studentId;
    }

    std::string getName () const {
        return name;
    }

    std::string getEmail () const {
        return email;
    }

    void setName (const std::string& nName) {
        name = nName;
    }

    void setEmail (const std::string nEmail) {
        email = nEmail;
    }

    void displayInfo () const {
        std::cout << studentId << "\t" << name << "\t" << email << std::endl;
    }
};

class Course {
private:
    std::string courseCode;
    std::string courseName;
    int maxStudents;
    int studentCount;

public:
    Course () : courseCode(""), courseName(""), maxStudents(0), studentCount(0) {}

    Course (std::string newCourseCode, std::string newCourseName, int newMaxStudent) :
            courseCode(newCourseCode), courseName(newCourseName), maxStudents(newMaxStudent) {}

    Course (const Course& other) : courseCode(other.courseCode), courseName(other.courseName), maxStudents(other.maxStudents), studentCount(other.studentCount) {}

    std::string getCourseCode () const {
        return courseCode;
    }

    std::string getCourseName () const {
        return courseName;
    }

    int getMaxStudents () const {
        return maxStudents;
    }

    int getStudentCount() const {
        return studentCount;
    }

    void setCourseName (const std::string& newCourseName) {
        courseName = newCourseName;
    }

    void setMaxStudents (int newMaxStudents) {
        maxStudents = newMaxStudents;
    }

    bool addStudent () {
        if (studentCount < maxStudents) {
            studentCount++;
            return true;
        }
        else
            return false;
    }

    void displayInfo() const {
        std::cout << courseCode << "\t" << courseName << "\tMax student: " << maxStudents << "\tCount now: " << studentCount << std::endl;
    }
};
/*
 * =============================================================================
 * СОДЕРЖАНИЕ MAIN ДЛЯ ТЕСТИРОВАНИЯ СИСТЕМЫ
 * =============================================================================
 */

int main() {
    std::cout << "=== СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ И КУРСАМИ ===" << std::endl << std::endl;

    // =========================================================================
    // 1. ТЕСТИРОВАНИЕ КОНСТРУКТОРОВ
    // =========================================================================
    std::cout << "1. ТЕСТИРОВАНИЕ КОНСТРУКТОРОВ:" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    // Конструктор по умолчанию
    Student defaultStudent;
    std::cout << "Студент по умолчанию: ";
    defaultStudent.displayInfo();

    // Параметризированный конструктор
    Student student1(1, "Иван Петров", "ivan@university.com");
    Student student2(2, "Мария Сидорова", "maria@university.com");
    std::cout << "Студент 1: ";
    student1.displayInfo();
    std::cout << "Студент 2: ";
    student2.displayInfo();

    // Конструктор копирования
    Student student3 = student1;  // Копия student1
    std::cout << "Студент 3 (копия student1): ";
    student3.displayInfo();

    // Параметризированный конструктор для курсов
    Course course1("CS101", "Программирование на C++", 2);  // Лимит 2 студента
    Course course2("MATH201", "Высшая математика", 3);      // Лимит 3 студента
    std::cout << "Курс 1: ";
    course1.displayInfo();
    std::cout << "Курс 2: ";
    course2.displayInfo();

    std::cout << std::endl;

    // =========================================================================
    // 2. ТЕСТИРОВАНИЕ ГЕТТЕРОВ И СЕТТЕРОВ
    // =========================================================================
    std::cout << "2. ТЕСТИРОВАНИЕ ГЕТТЕРОВ И СЕТТЕРОВ:" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    // Тестирование сеттеров Student
    student1.setName("Иван Иванов");
    student1.setEmail("ivan.ivanov@university.com");
    std::cout << "После изменения: ";
    student1.displayInfo();

    // Тестирование геттеров Student
    std::cout << "Геттеры student2 - ID: " << student2.getId()
              << ", Имя: " << student2.getName()
              << ", Email: " << student2.getEmail() << std::endl;

    // Тестирование сеттеров Course
    course1.setCourseName("Продвинутое программирование на C++");
    course1.setMaxStudents(5);
    std::cout << "Курс после изменения: ";
    course1.displayInfo();

    std::cout << std::endl;

    // =========================================================================
    // 3. ТЕСТИРОВАНИЕ ДОБАВЛЕНИЯ СТУДЕНТОВ НА КУРСЫ
    // =========================================================================
    std::cout << "3. ТЕСТИРОВАНИЕ ДОБАВЛЕНИЯ СТУДЕНТОВ:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // Успешное добавление студентов
    std::cout << "Добавление student1 на course1: "
              << (course1.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;
    std::cout << "Добавление student2 на course1: "
              << (course1.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;

    // Попытка добавить сверх лимита
    std::cout << "Добавление student3 на course1 (превышение лимита): "
              << (course1.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;

    // Добавление на другой курс
    std::cout << "Добавление student1 на course2: "
              << (course2.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;
    std::cout << "Добавление student2 на course2: "
              << (course2.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;
    std::cout << "Добавление student3 на course2: "
              << (course2.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;

    std::cout << std::endl;

    // =========================================================================
    // 4. ВЫВОД ИТОГОВОЙ ИНФОРМАЦИИ
    // =========================================================================
    std::cout << "4. ИТОГОВАЯ ИНФОРМАЦИЯ:" << std::endl;
    std::cout << "------------------------" << std::endl;

    std::cout << "Курс 1 после добавлений:" << std::endl;
    course1.displayInfo();

    std::cout << "Курс 2 после добавлений:" << std::endl;
    course2.displayInfo();

    std::cout << std::endl;

    // =========================================================================
    // 5. ТЕСТИРОВАНИЕ КОНСТРУКТОРА КОПИРОВАНИЯ ДЛЯ КУРСА
    // =========================================================================
    std::cout << "5. ТЕСТИРОВАНИЕ КОНСТРУКТОРА КОПИРОВАНИЯ КУРСА:" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    Course course3 = course1;  // Создаем копию course1
    std::cout << "Курс 3 (копия course1): ";
    course3.displayInfo();

    // Меняем оригинал - копия не должна измениться
    course1.setCourseName("ИЗМЕНЕННЫЙ КУРС");
    std::cout << "После изменения оригинала:" << std::endl;
    std::cout << "Оригинал course1: ";
    course1.displayInfo();
    std::cout << "Копия course3: ";
    course3.displayInfo();

    std::cout << std::endl;

    // =========================================================================
    // 6. ДОПОЛНИТЕЛЬНОЕ ТЕСТИРОВАНИЕ
    // =========================================================================
    std::cout << "6. ДОПОЛНИТЕЛЬНОЕ ТЕСТИРОВАНИЕ:" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    // Создание еще одного студента через конструктор копирования
    Student student4(student2);
    student4.setName("Копия Марии");
    std::cout << "Студент 4 (копия student2 с изменениями): ";
    student4.displayInfo();

    // Проверка граничных значений
    Course smallCourse("TEST001", "Тестовый курс", 1);
    std::cout << "Тестовый курс: ";
    smallCourse.displayInfo();
    std::cout << "Добавление студента: " << (smallCourse.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;
    std::cout << "Попытка добавить второго: " << (smallCourse.addStudent() ? "УСПЕХ" : "НЕУДАЧА") << std::endl;

    std::cout << std::endl;
    std::cout << "=== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ===" << std::endl;

    return 0;
}
