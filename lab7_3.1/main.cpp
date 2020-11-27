#include "matrix.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<double>> m1 = {{0, 1}, {2, 3}}, m2 = {{0, 1}, {0, 2}};
    
    Matrix M1(m1), M2(m2), M3 = mmult(M1, M2);


}