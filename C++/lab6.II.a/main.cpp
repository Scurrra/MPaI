#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "complex.hpp"
#include <system_error>

int main()
{
    std::vector<Complex> cs;
    
    try
    {
        std::ifstream in("in.txt");
        in.exceptions(in.failbit);
        // if (!in.is_open())
        // {
        //     throw std::system_error(EEXIST, "File isn't in directory");
        // }

        while (!in.eof())
        {
            Complex buffer;
            in >> buffer;
            cs.push_back(buffer);
        }
        in.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::ofstream out("out.txt");

    Complex res(0, 0);
    for (Complex c : cs)
    {
        res = res + c;
    }
    
    out << res;
    out.close();
}