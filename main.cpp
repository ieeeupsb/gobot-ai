#include <cstdio>
#include <iostream>

#include "board/board.h"
#include "board/stone.h"
#include "engine/game_state.h"

int main(void) {
    Board b = Board();
    GameState g = GameState();

    std::cout << b.to_string() << std::endl;
    std::cout << "size: " << b.size() << " total places: " << b.size()*b.size() << '\n';

    printf("stone: %c\n", to_char(g.turn()));

    return 0;
}
