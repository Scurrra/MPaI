#include "stack.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

void task(Stack<double>& stack)
{
    while (stack.length())
    {
        double buffer = stack.top();
        stack.pop();

        Stack<double> asc;
        
        do
        {
            asc.push(buffer);
            buffer = stack.top();
            stack.pop();
        }   while (stack.length() && stack.top() < buffer);
        
        if (asc.length() == 1)
        {
            continue;
        }
        
        auto size = asc.length();
        for (int i = 0; i < size; i++)
        {
            std::cout << asc.top() << ' ';
            asc.pop();
        }
        std::cout << "\n";
    }
}

int main()
{
    std::srand(std::time(nullptr));

    Stack<double> st(((double)(rand() % 100000)) / 10000);
    for (int i = 1; i < 100; i++)
    {
        st.push(((double)(rand() % 100000)) / 10000);
    }

    std::cout << "\n";
    task(st);

    std::cout << std::endl;
}