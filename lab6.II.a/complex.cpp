#include "complex.hpp"

Complex::Complex(double real, double img)
{
    this->real = real;
    this->img = img;
}

void Complex::operator=(Complex other)
{
    this->real = other.real;
    this->img = other.img;
}

Complex::Complex(){}
//Complex::~Complex(){}

Complex Complex::operator+(Complex& other) const
{
    return Complex(this->real + other.real, this->img + other.img);
}

Complex Complex::operator-(Complex& other) const
{
    return Complex(this->real - other.real, this->img - other.img);
}

Complex Complex::operator*(Complex& other) const
{
    return Complex(this->real * other.real - this->img * other.img, 
                    this->img * other.real + this->real * other.img);
}

Complex Complex::operator/(Complex& other) const
{
    return Complex((this->real * other.real + this->img * other.img) / (other.real * other.real + other.img * other.img),
                    (this->img * other.real - this->real * other.img) / (other.real * other.real + other.img * other.img));
}

std::ostream& operator>> (std::istream& stream, Complex& number)
{
    std::string buffer;

    getline(stream, buffer, ' ');

    if (buffer.find('i') == std::string::npos)
    {
        std::string err = "Wrong input format! '" + buffer + "'";
        throw std::logic_error(err); 
    }
    
    number.real = stod(buffer);

    if (buffer.find('+') != std::string::npos)
    {
        buffer.erase(0, buffer.find('+'));
    }
    else
    {
        buffer.erase(0, buffer.find('-'));
    }
    
    number.img = stod(buffer);
}

std::ostream& operator<< (std::ostream& stream, Complex& number)
{
    stream << number.real;
    number.img >= 0? stream << '+' << number.img : stream << '-' << abs(number.img);
    stream << 'i';
    return stream;
}