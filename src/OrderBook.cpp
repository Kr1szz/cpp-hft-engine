#include "OrderBook.hpp"

#include <stdexcept>

void OrderBook::add_order(const Order& order) {
    // Reject duplicate or out-of-order sequences.
    if (last_timestamp_.has_value() &&
        order.timestamp <= *last_timestamp_) {
        throw std::invalid_argument(
            "Order sequence must increase"
        );
    }

    switch (order.side) {
        case Side::Buy:
            bids_[order.price].push_back(order);
            break;

        case Side::Sell:
            asks_[order.price].push_back(order);
            break;

        default:
            throw std::invalid_argument(
                "Invalid order side"
            );
    }

    last_timestamp_ = order.timestamp;
}

std::optional<std::int64_t>
OrderBook::best_bid_price() const noexcept {
    if (bids_.empty()) {
        return std::nullopt;
    }

    return bids_.begin()->first;
}

std::optional<std::int64_t>
OrderBook::best_ask_price() const noexcept {
    if (asks_.empty()) {
        return std::nullopt;
    }

    return asks_.begin()->first;
}

std::optional<Order>
OrderBook::best_bid_order() const noexcept {
    if (bids_.empty()) {
        return std::nullopt;
    }

    return bids_.begin()->second.front();
}

std::optional<Order>
OrderBook::best_ask_order() const noexcept {
    if (asks_.empty()) {
        return std::nullopt;
    }

    return asks_.begin()->second.front();
}