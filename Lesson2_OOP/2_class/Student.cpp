#include <cassert>
#include <iostream>
#include <stdexcept>

// TODO: Define "Student" class
class Student {
public:
  // constructor
  Student(std::string name, int grade, float Gpa)
      : name_(name), grade_(grade), Gpa_(Gpa) {
    Validate();
  }
  // accessors
  std::string Name() { return name_; }
  int Grade() { return grade_; }
  float GPA() { return Gpa_; }
  // mutators
  void Name(std::string name) { name_ = name; }
  void Grade(int grade) { grade_ = grade; }
  void GPA(float GPA) { Gpa_ = GPA; }

private:
  // name
  std::string name_;
  // grade
  int grade_;
  // GPA
  float Gpa_;
  // Validate
  void Validate() {
    if (grade_ > 12 || grade_ < 0 || Gpa_ < 0.0 || Gpa_ > 4.0) {
      throw std::invalid_argument("invalid initial value");
    }
  }
};

// TODO: Test
int main() {
  Student student1("KJS", 7, 3.5);

  std::cout << "name : " << student1.Name() << " "
            << "grade : " << student1.Grade() << " "
            << "GPA : " << student1.GPA() << "\n";

  Student student2("Jermaine Lamarr Cole", 12, 0.1);

  std::cout << "name : " << student2.Name() << " "
            << "grade : " << student2.Grade() << " "
            << "GPA : " << student2.GPA() << "\n";
}