#include "stack.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void task(Stack<double>& stack)
{
    while (stack.length())
    {
        double buffer = stack.top();
        stack.pop();

        Stack<double> asc;
        
        while (stack.length() && stack.top() < buffer)
        {
            asc.push(buffer);
            buffer = stack.top();
            stack.pop();
        }
        asc.push(buffer);

        if (asc.length() > 1)
        {
            auto size = asc.length();
            for (int i = 0; i < size; i++)
            {
                std::cout << asc.top() << ' ';
                asc.pop();
            }
            std::cout << "\n"; 
        }
    }
}

int main()
{
    std::srand(std::time(nullptr));

    Stack<double> st(((double)(rand() % 100000)) / 10000);
    for (int i = 1; i < 20; i++)
    {
        auto buffer = ((double)(rand() % 100000)) / 10000;
        st.push(buffer);
        std::cout << buffer << ' ';
    }

    std::cout << "\n";
    task(st);

    std::cout << std::endl;
}