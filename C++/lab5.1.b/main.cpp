#include <iostream>
#include "library.hpp"

int main()
{
    Item it(*(new int(1234567)));
    Book book("Brown", "Inferno", "Doubleday", *(new int(2013)), *(new int(1234568)));
    Magazin mag("Ubuntu User", *(new int(1)), *(new int(1)), *(new int(2009)), *(new int(134569)));

    it.show();
    std::cout << "\n";
    book.show();
    std::cout << "\n";
    mag.show();
    std::cout << "\n";

    book.Take();
    std::cout << "\n";
    book.show();
}