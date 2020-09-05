#include <iostream>
#include "student.hpp"
#include <vector>
#include <algorithm>

void taskA(std::vector<Student>& students, std::string faculty)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getFaculty() == faculty)
        {
            students[i].show();
        }
    }
}

void taskB(std::vector<Student>& students)
{
    // faculties
    sort(students.begin(), students.end(), [](Student first, Student second){ return first.getFaculty() < second.getFaculty(); });

    for (int i = 0; i < students.size(); i++)
    {
        students[i].show();
    }

    sort(students.begin(), students.end(), [](Student first, Student second){ return first.getYear() < second.getYear(); });

    for (int i = 0; i < students.size(); i++)
    {
        students[i].show();
    }
}

void taskC(std::vector<Student>& students, int year)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getBirthday().year > year)
        {
            students[i].show();
        }
    }
}

int main()
{
    int n;  std::cout << "Number of students: ";  std::cin >> n;

    std::vector<Student> students(n);

    for (int i = 0; i < n; i++)
    {
        std::string surname;
        std::string name; 
        std::string patronymic;
        std::string address;
        std::string phoneNumber;
        std::string faculty;
        Date birthDay;
        int year;

        std::cout << "  Name: ";    std::cin >> surname >> name >> patronymic;
        std::cout << "  Was born: ";    std::cin >> birthDay.month >> birthDay.day >> birthDay.year;
        std::cout << "  Address and phone number: ";    std::cin >> address >> phoneNumber;
        std::cout << "  Faculty and year: ";    std::cin >> faculty >> year;    
        std::cout << "-----------------------------------------------------------------------------------------------------\n";

        students[i].set(surname, name, patronymic,
                        address, phoneNumber,
                        faculty,
                        birthDay,
                        year);
    }
    
    std::cout << "\n\n\nTask A\n";
    taskA(students, "MMF");

    std::cout << "\n\n\nTask B\n";
    taskB(students);

    std::cout << "\n\n\nTask C\n";
    taskC(students, 2);

    return 0;
}