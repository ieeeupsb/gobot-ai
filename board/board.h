#ifndef BOARD
#define BOARD

#include <cstddef>
#include <optional>
#include <vector>
#include <iostream>
#include <string>

#include "stone.h"

class Board {
    private:
        std::vector<std::optional<Stone>> board_ = {};
        size_t size_ = 9;

    public:
        Board() {
            for (size_t i = 0; i < size_ * size_; i++) {
                board_.push_back(std::nullopt);
            }
        };

        /**
         * Returns the element at given row and col. Both are 0-based.
         */
        std::optional<Stone> at(int row, int col) const {
            // TODO: maybe add a out of bounds check
            return board_[row * size_ + col];
        }

        std::string to_string() const {
            std::string out = "";
            out += "[\n";
            for (size_t i = 0; i < size_; i++) {
                std::string line = "  ";
                for (size_t j = 0; j < size_; j ++) {
                    if (j > 0) line += ' ';
                    line += to_char(at(i, j));
                }
                line += '\n';
                out += line;
            }
            out += "]";

            return out;
        }

        void print() const {
            std::cout << to_string() << '\n';
        }

        size_t size() const {
            return size_;
        }

        void place(int row, int col, Stone s) {
            auto curr = at(row, col);
            if (!curr.has_value()) {
                board_[row * size_ + col] = s;
            } else {
                // TODO: invalid move? idk
            }
        }

        void remove(int row, int col) {
            // TODO: is it useful?
        }
};

#endif
