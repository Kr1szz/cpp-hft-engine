#include "OrderBook.hpp"

#include <iostream>

int main() {
    OrderBook book;

    book.add_order(Order{1, Side::Buy, 2000, 10, 1});
    book.add_order(Order{2, Side::Buy, 2010, 5, 2});

    book.add_order(Order{3, Side::Sell, 2030, 7, 3});
    book.add_order(Order{4, Side::Sell, 2020, 4, 4});

    const auto best_bid = book.best_bid_price();
    const auto best_ask = book.best_ask_price();

    std::cout << "C++ HFT Order Book\n";
    std::cout << "------------------\n";

    if (best_bid.has_value()) {
        std::cout << "Best bid: "
                  << *best_bid << " ticks\n";
    }

    if (best_ask.has_value()) {
        std::cout << "Best ask: "
                  << *best_ask << " ticks\n";
    }

    if (best_bid.has_value() && best_ask.has_value()) {
        std::cout << "Spread: "
                  << (*best_ask - *best_bid)
                  << " ticks\n";
    }

    return 0;
}