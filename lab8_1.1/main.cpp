#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int counter(std::string& s, char c)
{
    int quantity(0);

    size_t found = s.find(c);

    while (found != std::string::npos)
    {
        quantity++;
        found = s.find(c, found + 1);
    }
    
    return quantity;
}

std::vector<std::string> split(std::string& s, char delimeter = ' ')
{
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> words;

    while (getline(ss, word, delimeter))
    {
        words.push_back(word);
    }
    
    return words;
}

int main()
{
    std::string s;
    getline(std::cin, s);

    std::vector<std::string> words = split(s);

    std::cout << "Task #1\n";
    for (auto word : words)
    {
        std::cout << word[word.length() - 1];
    }
    
    std::cout << "\n\nTask #2\n";
    for (auto word : words)
    {
        if (counter(word, 'd') == 2)
        {
            std::cout << word << ' ';
        }
    }
    std::cout << "\n";
}