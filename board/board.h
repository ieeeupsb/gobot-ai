#ifndef BOARD
#define BOARD

#include <optional>
#include <vector>
#include <string>


#include "stone.h"

class Board {
    private:
        int size_ = 9;
        std::vector<std::optional<Stone>> board_ = {};
        void set(int row, int col, std::optional<Stone> val);

    public:
        Board();
        int size() const;
        // Returns the element at given row and col. Both are 0-based. Throws std::out_of_range if out of bounds.
        std::optional<Stone> at(int row, int col) const;
        // Helper for printing the board
        std::string to_string() const;
        // Print the board
        void print() const;
        // Only place S when the intersection is empty and in-bounds. If the spot is occupied, you should remove first. Returns false if occupied.
        bool place(int row, int col, Stone s);
        void remove(int row, int col);
        bool in_bounds(int row, int col) const;
};

#endif
