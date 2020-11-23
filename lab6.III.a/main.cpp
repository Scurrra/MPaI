#include <fstream>
#include <string>
#include <iostream>
#include "complex.hpp"
#include "stack.hpp"
#include <system_error>

int main()
{
    Stack<Complex> cs;
    
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
            cs.push(buffer);
        }
        in.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::ofstream out("out.txt");

    Complex res(0, 0);
    auto size = cs.length();
    for (int i = 0; i < size; ++i)
    {
        Complex buffer = cs.top();
        res = res + buffer;
        cs.pop();
    }
    
    out << res;
    out.close();
}