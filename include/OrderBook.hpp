#pragma once

#include "Order.hpp"

#include <cstdint>
#include <deque>
#include <functional>
#include <map>
#include <optional>

class OrderBook {
public:
    void add_order(const Order& order);

    std::optional<std::int64_t>
    best_bid_price() const noexcept;

    std::optional<std::int64_t>
    best_ask_price() const noexcept;

    std::optional<Order>
    best_bid_order() const noexcept;

    std::optional<Order>
    best_ask_order() const noexcept;

private:
    using PriceLevel = std::deque<Order>;

    // Highest bid first.
    std::map<
        std::int64_t,
        PriceLevel,
        std::greater<std::int64_t>
    > bids_;

    // Lowest ask first.
    std::map<
        std::int64_t,
        PriceLevel
    > asks_;

    // Enforce strictly increasing arrival sequences.
    std::optional<std::uint64_t> last_timestamp_;
};