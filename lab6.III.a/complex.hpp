#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <stdexcept>

#define abs(a) (a < 0 ? -a : a)

class Complex
{
private:
    double real;
    double img;
public:
    Complex(double real, double img);
    //Complex(const Complex&)
    void operator=(Complex other);

    Complex();
    //~Complex();

    Complex operator+(Complex& other) const;
    Complex operator-(Complex& other) const;
    Complex operator*(Complex& other) const;
    Complex operator/(Complex& other) const;

    friend std::ostream& operator>> (std::istream& stream, Complex& number);
    friend std::ostream& operator<< (std::ostream& stream, Complex& number);
};


#endif