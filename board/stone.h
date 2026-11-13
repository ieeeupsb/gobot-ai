#ifndef STONE
#define STONE

#include <cstdint>
#include <optional>

enum class Stone : uint8_t {
    White,
    Black
};

// idk the difference between inline and constexpr tbh

constexpr char to_char(Stone s) {
    switch (s) {
        case Stone::White:
            return 'W';
        case Stone::Black:
            return 'B';
        default:
            return '?';
    }
};

constexpr char to_char(std::optional<Stone> s) {
    if (s.has_value()) {
        return to_char(*s);
    }

    return 'O';
}

#endif
