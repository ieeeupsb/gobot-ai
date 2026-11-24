#ifndef GAME_STATE
#define GAME_STATE

#include "board/board.h"
#include "board/stone.h"
#include "move.h"
#include <optional>

class GameState {
    private:
        Board board_;
        Stone turn_;
        // Intersection forbidden on the next turn due to simple Ko
        std::optional<Move> ko_point_;
        int consecutive_passes_;
        // Extra points for White, since it always starts second
        double komi_;

    public:
        GameState();
        // Inspect the board without copying it
        const Board* board() const;
        // Current player to place a stone
        Stone turn() const;
        bool is_game_over() const;
        // Checks bounds, empty cell, Ko and suicide. Pass is always valid if the game isn't over
        bool is_legal(const Move& m) const;
        // All legal moves (used by MCTS and RandomPlayer)
        std::vector<Move> legal_moves() const;
        // Validates and applies m
        bool play(const Move& m);
        Stone winner() const;
};

#endif
