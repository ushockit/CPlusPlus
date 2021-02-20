#include "StudentsStorage.h"

StudentsStorage* StudentsStorage::instance = nullptr;

StudentsStorage::StudentsStorage()
{
    students.push_back(Student("Vasya", "Pupkin", "", Date(2000, 10, 05)));
    students.push_back(Student("Petya", "Ivanov", "", Date(1987, 04, 11)));
    students.push_back(Student("Kolya", "Sidorov", "", Date(2005, 01, 19)));
    students.push_back(Student("Dima", "Stepanov", "", Date(1992, 11, 25)));
    students.push_back(Student("Masha", "Rudova", "", Date(1980, 9, 01)));
    students.push_back(Student("Gogi", "Kurochkin", "", Date(1994, 06, 05)));
}

StudentsStorage* StudentsStorage::getInstance()
{
    if (instance == nullptr) {
        instance = new StudentsStorage();
    }
    return instance;
}

const std::vector<Student>& StudentsStorage::getStudents() const
{
    return students;
}

Student* StudentsStorage::searchStudentByLastName(string lastName)
{
    auto it = std::find_if(students.begin(), students.end(), [lastName](const Student& student) {
        return student.getLastName() == lastName;
    });
    return it != students.end() ? &(*it) : nullptr;
}
