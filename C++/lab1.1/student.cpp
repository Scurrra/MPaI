#include "student.hpp"
#include <iostream>

Student::Student(){}

Student::Student(std::string& surname, std::string& name, std::string& patronymic,
    std::string& address, std::string& phoneNumber,
    std::string& faculty,
    Date& birthDay,
    int& year)
{
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
    this->birthDay = birthDay;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->faculty = faculty;
    this->year = year;
}

Student::~Student(){}

void Student::set(std::string& surname, std::string& name, std::string& patronymic,
    std::string& address, std::string& phoneNumber,
    std::string& faculty,
    Date& birthDay,
    int& year)
{
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
    this->birthDay = birthDay;
    this->address = address;
    this->phoneNumber = phoneNumber;
    this->faculty = faculty;
    this->year = year;
}

std::string Student::getFaculty() const { return faculty; };

Date Student::getBirthday() const { return birthDay; };

int Student::getYear() const { return year; };

void Student::show() const
{
    std::cout << "  Name: " << this->surname << ' ' << this->name << ' ' << this->patronymic << ' ' << std::endl;
    std::cout << "  Was born: " << this->birthDay.month << '.' << this->birthDay.day << '.' << this->birthDay.year;
    std::cout << "  Address and phone number: " << this->address << ", " << this->phoneNumber << std::endl;
    std::cout << "  Faculty and year: " << this->faculty << ", " << this->year << std::endl;    
    std::cout << "-----------------------------------------------------------------------------------------------------\n"; 
}