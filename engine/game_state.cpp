#include "game_state.h"

#include "board/board.h"
#include "board/stone.h"
#include "engine/move.h"
#include <optional>
#include <vector>

GameState::GameState() {
    board_ = Board();
    turn_ = Stone::Black;
    ko_point_ = std::nullopt;
    consecutive_passes_ = 0;
    komi_ = 6.5;
}

const Board& GameState::board() const {
    return board_;
}

Stone GameState::turn() const {
    return turn_;
}

bool GameState::is_legal(const Move& m) const {
    if (is_game_over()) return false;

    if (m.is_pass) return true;

    if (
        !board_.in_bounds(m.row, m.col) ||
        board_.at(m.row, m.col).has_value() ||
        m == ko_point_
    ) return false;

    // simply valid
    // TODO: check suicide
    return true;
}

std::vector<Move> GameState::legal_moves() const {
    if (is_game_over()) return {};

    std::vector<Move> moves = {};
    for (int row = 0; row < board_.size(); row++) {
        for (int col = 0; col < board_.size(); col++) {
            Move m = {row, col};
            if (is_legal(m)) moves.push_back(m);
        }
    }
    moves.push_back(pass());

    return moves;
}

bool GameState::is_game_over() const {
    return consecutive_passes_ >= 2;
}

bool GameState::play(const Move& m) {
    // TODO
}
