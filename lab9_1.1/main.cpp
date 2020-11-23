#include "vector.hpp"
#include <iostream>
#include <ctime>

template<int N>
double length(Vector<N>& vector)
{
    double result(0);
    for (size_t i = 1; i <= N; ++i)
    {
        result += vector[i] * vector[i];
    }
    
    return std::pow(result, 0.5);
}

int main()
{
    double vec[5];
    for (int i = 1; i < 5; i++)
    {
        vec[i] = ((double)(rand() % 100000)) / 10000;
    }

    Vector<5> vector(vec);
    std::cout << "|"<< vector << "| = " << length(vector) << "\n";
}