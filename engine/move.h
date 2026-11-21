#ifndef MOVE
#define MOVE


//can be improved to be encoded into a single uint8_t, if needed for performance reasons later on
struct Move {

    int row = 0;
    int col = 0;
    bool is_pass = false; 

    bool operator==(const Move&) const = default;   // C++20
};
//the information about the stone that is placed is retrived with the current state of the game

constexpr Move pass() { return {0, 0, 1}; }

#endif