#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

union Info
{
    Date birth;
    std::string faculty;
    Info() {}
    ~Info() {}
};

enum Field { Faculty, Birth };

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

    Info& get(Field& criterion) const;
    
    void show() const;
};

#endif