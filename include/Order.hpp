#pragma once

#include <cstdint>

enum class Side {
    Buy,
    Sell
};

struct Order {
    std::uint64_t id;
    Side side;
    std::int64_t price;       // Integer price ticks
    std::uint32_t quantity;
    std::uint64_t timestamp;  // Arrival sequence
};