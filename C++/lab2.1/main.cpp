#include <iostream>
#include "complex.hpp"
#include <vector>
#include <time.h>

std::vector<Complex> complexVectorSum(std::vector<Complex>& a, std::vector<Complex>& b)
{
    std::vector<Complex> c(a.size());

    for (int i = 0; i < c.size(); i++)
    {
        c[i] = a[i] + b[i];
    }
    
    return c;
}

int main()
{
    srand (time(NULL));

    int n;  std::cout << "Enter dim: "; std::cin >> n;
    std::vector<Complex> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = Complex(rand() % 20 - 10, rand() % 20 - 10);
        b[i] = Complex(rand() % 20 - 10, rand() % 20 - 10);
    }

    std::cout << '(';
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ") + ";

    std::cout << '(';
    for (int i = 0; i < n; i++)
    {
        std::cout << b[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ") = ";

    std::vector<Complex> c = complexVectorSum(a, b);
    
    std::cout << '(';
    for (int i = 0; i < n; i++)
    {
        std::cout << c[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ")\n";
}