#include <iostream>

#include "board/board.h"

int main(void) {
    Board b = Board();

    std::cout << b.to_string() << std::endl;

    return 0;
}
