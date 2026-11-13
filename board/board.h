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
        std::vector<std::optional<Stone>> board = {};
        size_t size = 9;

    public:
        Board() {
            for (size_t i = 0; i < this->size * this->size; i++) {
                this->board.push_back(std::nullopt);
            }
        };

        /**
         * Returns the element at given row and col. Both a 0-based.
         */
        std::optional<Stone> at(int row, int col) const {
            return board[row * this->size + col];
        }

        std::string to_string() const {
            std::string out = "";
            out += "[\n";
            for (size_t i = 0; i < size; i++) {
                std::string line = "  ";
                for (size_t j = 0; j < size; j ++) {
                    if (j > 0) line += ' ';
                    line += to_char(this->at(i, j));
                }
                line += '\n';
                out += line;
            }
            out += "]";

            return out;
        }

        void print() {
            std::cout << this->to_string() << '\n';
        }
};

#endif
