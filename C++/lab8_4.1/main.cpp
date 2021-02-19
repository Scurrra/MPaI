#include "stack.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student
{
    std::string firstName;
    std::string secondName;
    unsigned int age;
    std::string  sex;
    unsigned int year;
    float rate;

    friend std::ostream& operator<<(std::ostream& stream, Student& student);
    friend std::istream& operator>>(std::istream& stream, Student& student);
};

std::ostream& operator<<(std::ostream& stream, Student& student)
{
    stream << student.firstName << ' ' << student.secondName << ' ' << student.age << ' ' << student.sex << ' ' << student.year << ' ' << student.rate;
    return stream;
}

std::istream& operator>>(std::istream& stream, Student& student)
{
    std::string buffer;

    getline(stream, student.firstName, ' ');
    getline(stream, student.secondName, ' ');
    
    getline(stream, buffer, ' ');
    student.age = stoi(buffer);

    getline(stream, student.sex, ' ');
    
    getline(stream, buffer, ' ');
    student.year = stoi(buffer);

    getline(stream, buffer);
    student.rate = stod(buffer);
}

int main()
{
    Student student;
    //std::cin >> student;
    //std::cout << student << "\n";

    std::ifstream in("in.txt");
    Stack<Student> students;
    while (!in.eof())
    {
        in >> student;
        students.push(student);
    }
    in.close();
    
    int n;  std::cin >> n;

    while (students.top().year != n)
    {
        students.pop();
    }
    student = students.top();
    students.pop();

    while (students.length())
    {
        if (students.top().year == n && students.top().age > student.age)
        {
            student = students.top();
        }
        students.pop();
    }

    std::ofstream out("out.txt");
    out << student;
    out.close();
}