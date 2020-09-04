#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

class Student
{
private:
    std::string surname, name, patronymic;
    std::string address, phoneNumber;
    std::string faculty;
    Date birthDay;
    int year;
public:
    Student();
    ~Student();

    void set(std::string& surname, std::string& name, std::string& patronymic,
        std::string& address, std::string& phoneNumber,
        std::string& faculty,
        Date& birthDay,
        int& year);

    std::string getFaculty() const;
    Date getBirthday() const;
    int getYear() const;
    
    void show() const;
};

#endif