#include "game_state.h"

#include "board/board.h"
#include "board/stone.h"
#include <optional>
#include <vector>

GameState::GameState() {
    board_ = Board();
    turn_ = Stone::Black;
    ko_point_ = std::nullopt;
    consecutive_passes_ = 0;
    komi_ = 6.5;
}

const Board* GameState::board() const {
    // TODO
}

Stone GameState::turn() const {
    return turn_;
}

bool GameState::is_legal(const Move& m) const {
    // TODO
}

std::vector<Move> GameState::legal_moves() const {
    // TODO
    // compute all moves, then apply the is_legal as filter?
}

bool GameState::is_game_over() const {
    return consecutive_passes_ >= 2;
}

bool GameState::play(const Move& m) {
    // TODO
}
