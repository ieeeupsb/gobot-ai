#include <iostream>

#include "board/board.h"

int main(void) {
    Board b = Board();

    std::cout << b.to_string() << std::endl;
    std::cout << "size: " << b.size() << " total places: " << b.size()*b.size() << '\n';

    return 0;
}
