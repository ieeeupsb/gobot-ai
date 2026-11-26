#include "board.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <optional>
#include <vector>

Board::Board() {
    board_.assign(size_ * size_, std::nullopt);
}

std::string Board::to_string() const {
    std::string out = "";
    out += "[\n";
    for (int row = 0; row < size_; row++) {
        std::string line = "  ";
        for (int col = 0; col < size_; col ++) {
            if (col > 0) line += ' ';
            line += to_char(at(row, col));
        }
        line += '\n';
        out += line;
    }
    out += "]";

    return out;
}

void Board::print() const {
    std::cout << to_string() << '\n';
}

int Board::size() const {
    return size_;
}

void Board::set(int row, int col, std::optional<Stone> val) {
    board_[row * size_ + col] = val;
}

std::optional<Stone> Board::at(int row, int col) const {
    if (!in_bounds(row, col)) throw std::out_of_range("Accessing inexistent board intersection");

    return board_[row * size_ + col];
}

bool Board::place(int row, int col, Stone s) {
    if (!in_bounds(row, col)) return false;

    std::optional<Stone> curr = at(row, col);
    if (!curr.has_value()) {
        set(row, col, s);
        return true;
    }

    return false;
}

void Board::remove(int row, int col) {
    if (!in_bounds(row, col)) return;

    std::optional<Stone> st = at(row, col);

    if (st.has_value()) {
        set(row, col, std::nullopt);
    }
}

bool Board::in_bounds(int row, int col) const {
    return (row < size_ && row >= 0) && (col < size_ && col >= 0);
}
