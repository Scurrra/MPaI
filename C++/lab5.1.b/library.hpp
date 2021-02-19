#ifndef LIB
#define LIB

#include <string>
#include <iostream>
#include <stdexcept>

class Item
{
protected:
    int invNumber;
    bool taken = false;
public:
    Item(int& invN) : invNumber(invN) {}
    virtual void show() const { std::cout << invNumber << " is " << (taken ? "" : "not ") << "taken.\n"; };
    bool isAvailable() const { return taken; }
    int getInvNumber() const { return invNumber; }
    void Take() { taken = !taken ? !taken : throw std::logic_error("The book is already taken"); }
    void Return() { taken = taken ? !taken : throw std::logic_error("The book isn't taken"); }
};

class Book : public Item
{
private:
    std::string author;
    std::string title;
    std::string publisher;
    int year;
public:
    Book(std::string author, std::string title, std::string publisher, int& year, int& invN) : Item(invN)
    {
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->year = year;
    }

    std::string getAuthor() const { return author; }
    std::string getTitle() const { return title; }
    std::string getPublisher() const { return publisher; }
    int getYear() const { return year; }

    void setAuthor(const std::string& author) { this->author = author; }
    void setTitle(const std::string& title) { this->title = title; }
    void setPublisher(const std::string& publisher) { this->publisher = publisher; }
    void setYear(int& year) { this->year = year; }

    void show() const override
    {
        std::cout << "Author: " << author << "\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Publisher: " << publisher << "\n";
        std::cout << "Year of publishing: " << year << "\n";
        //Item::show();
        std::cout << invNumber << " is " << (taken ? "" : "not ") << "taken.\n";
    }
};

class Magazin : public Item
{
private:
    std::string title;
    int volume;
    int number;
    int year;
public:
    Magazin(std::string title, int& volume, int& number, int& year, int& invN) : Item(invN)
    {
        this->title = title;
        this->volume = volume;
        this->number = number;
        this->year = year;
    }

    std::string getTitle() const { return title; }
    int getVolume() const { return volume; }
    int getNumber() const { return number; }
    int getYear() const { return year; }

    void setTitle(const std::string& title) { this->title = title; }
    void setVolume(int& volume) { this->volume = volume; }
    void setNumber(int& number) { this->number = number; }
    void setYear(int& year) { this->year = year; }

    void show() const override
    {
        std::cout << "Title: " << title << "\n";
        std::cout << "Vol. " << volume << " #" << number << "\n";
        std::cout << "Year of publishing: " << year << "\n";
        //Item::show();
        std::cout << invNumber << " is " << (taken ? "" : "not ") << "taken.\n";
    }
};

#endif