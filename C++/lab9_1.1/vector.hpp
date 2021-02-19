#ifndef VECTOR
#define VECTOR

#include <math.h>
#include <stdexcept>
#include <iostream>

template<int N>
class Vector
{
private:
    double values[N];
public:
    Vector(double values[N])
    {
        for (int i = 0; i < N; ++i)
        {
            this->values[i] = values[i];
        }
    }  
    ~Vector()   {}

    double operator[](int n) const { return n > 0 && n <= N ? values[n-1] : throw std::logic_error("Out of range"); }
    Vector<N> operator+(Vector<N>& other)
    {
        double result[N];
        for (int i = 0; i < N; ++i)
        {
            result[i] = values[i] + other[i];
        }
        
        return Vector<N>(result);
    }
    Vector<N> operator-(Vector<N>& other)
    {
        double result[N];
        for (int i = 0; i < N; ++i)
        {
            result[i] = values[i] + other[i];
        }
        
        return Vector<N>(result);
    }
    template<typename T>
    Vector<N> operator*(T& other)
    {
        double result[N];
        for (int i = 0; i < N; ++i)
        {
            result[i] = values[i] * other;
        }
        
        return Vector<N>(result);
    }
    template<typename T>
    Vector<N> operator/(T& other)
    {
        double result[N];
        for (int i = 0; i < N; ++i)
        {
            result[i] = values[i] / other;
        }
        
        return Vector<N>(result);
    }
    void operator=(Vector<N>& other)
    {
        for (int i = 0; i < N; ++i)
        {
            values[i] = other.values[i];
        }
    }
    
    friend std::ostream& operator<<(std::ostream& stream, Vector<N>& vector)
    {
        stream << '(';
        for (int i = 1; i < N; ++i)
        {
            stream << vector[i] << ',';
        }
        stream << vector[N] << ')';
        
        return stream;
    }
};




#endif