#ifndef STACK_H
#define STACK_H

#include <functional>

template<class T>
struct Node
{
    T value;
    Node<T>* next;
};

template<class T>
class Stack
{
private:
    Node<T>* topNode = new Node<T>;
    int size;
public:
    Stack(T value)
    {
        topNode->value = value;
        size = 1;
    }

    Stack()
    {
        size = 0;
    }

    void push(T value)
    {
        if (size > 0)
        {
            Node<T>* temp = new Node<T>;
            temp->value = value;
            temp->next = topNode;
            topNode = temp;    
            size++;
        }
        else if (size == 0)
        {
            *this = Stack(value);
        }
    }

    void pop()
    {
        topNode = topNode->next;
        size--;
    }

    T top() const
    {
        return topNode->value;
    }

    int length() const    { return size; }
    
    friend Stack<T> merge(Stack<T> first, Stack<T> second, std::function<bool(T, T)> comp)
    {
        Stack<T> result;
        while (first.length() && second.length())
        {
            if (comp(first.top(), second.top()))
            {
                result.push(first.top());
                first.pop();
            }
            else
            {
                result.push(second.top());
                second.pop();
            }
        }
    
        while (first.length())
        {
            result.push(first.top());
            first.pop();
        }
    
        while (second.length())
        {
            result.push(second.top());
            second.pop();
        }

        return result;
    }
};

// template<class T>
// Stack<T> merge(Stack<T>& first, Stack<T>& second, std::function<bool(T&, T&)> comp)
// {
//     Stack<T> result;
//     while (first.length() && second.length())
//     {
//         if (comp(first.top(), second.top()))
//         {
//             result.push(first.top());
//             first.pop();
//         }
//         else
//         {
//             result.push(second.top());
//             second.pop();
//         }
//     }
    
//     while (first.length())
//     {
//         result.push(first.top());
//         first.pop();
//     }
    
//     while (second.length())
//     {
//         result.push(second.top());
//         second.pop();
//     }

//     return result;
// }

#endif