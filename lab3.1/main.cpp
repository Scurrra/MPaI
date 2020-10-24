#include "stack.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

void task1()
{
    Stack<double> stack(((double)(rand() % 100000)) / 10000);
    for (int i = 1; i < 20; i++)
    {
        auto buffer = ((double)(rand() % 100000)) / 10000;
        stack.push(buffer);
        std::cout << buffer << ' ';
    }

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

void task2()
{
    Stack<int> first, second;
    int n;  std::cout << "Length of the 1st stack: ";
    std::cin >> n;
    
    for (auto i = 0; i < n; ++i)
    {
        int buffer;
        std::cin >> buffer;
        first.push(buffer); 
    }
    
    std::cout << "Length of the 2nd stack: ";
    std::cin >> n;
    
    for (auto i = 0; i < n; ++i)
    {
        int buffer;
        std::cin >> buffer;
        second.push(buffer); 
    }

    Stack<int> merged = merge(first, second, [](int a, int b){ return a >= b; });
    auto size = merged.length();
    for (auto i = 0; i < size; ++i)
    {
        std::cout << merged.top() << ' ';
        merged.pop();
    }
}

void task3()
{
    /* я читер, я храню длину, так что смысла нет */
    std::cout << "я читер, я храню длину, так что смысла нет\n";
}

void task4()
{
    std::map<char, char> bracketPair = {{')', '('}, {']', '['}, {'}', '{'}};
    Stack<char> brackets;
    std::cout << "Enter length of the string: ";
    int length; std::cin >> length;
    for (auto i = 0; i < length; ++i)
    {
        char buffer;
        std::cin >> buffer;

        if (buffer == '(' || buffer == '[' || buffer == '{')
        {
            brackets.push(buffer);
        }
        else
        {
            if (brackets.top() == bracketPair[buffer])
            {
                brackets.pop();
            }
            else
            {
                std::cout << "ERROR\n";
                return;
            }
        }
    }

    std::cout << "OK\n";
}

int main()
{
    std::srand(std::time(nullptr));

    std::cout << "Task 1\n";
    task1();

    std::cout << "\n\nTask 2\n";
    task2();

    std::cout << "\n\nTask 3\n";
    task3();

    std::cout << "\n\nTask 4\n";
    task4();
}