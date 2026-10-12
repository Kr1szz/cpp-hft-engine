#include "OrderBook.hpp"

#include <cassert>
#include <stdexcept>

int main() {
    OrderBook book;

    // Day 2: Empty book.
    assert(!book.best_bid_price().has_value());
    assert(!book.best_ask_price().has_value());

    // Day 2: Insert bids.
    book.add_order(Order{1, Side::Buy, 2000, 10, 1});
    book.add_order(Order{2, Side::Buy, 2010, 5, 2});
    book.add_order(Order{3, Side::Buy, 2010, 8, 3});
    book.add_order(Order{4, Side::Buy, 1990, 4, 4});

    // Day 2: Insert asks.
    book.add_order(Order{5, Side::Sell, 2030, 7, 5});
    book.add_order(Order{6, Side::Sell, 2020, 4, 6});
    book.add_order(Order{7, Side::Sell, 2020, 2, 7});
    book.add_order(Order{8, Side::Sell, 2040, 6, 8});

    // Day 2: Best-price lookup.
    assert(book.best_bid_price().value() == 2010);
    assert(book.best_ask_price().value() == 2020);

    // Day 3: FIFO at the best bid price.
    const auto best_bid = book.best_bid_order();

    assert(best_bid.has_value());
    assert(best_bid->id == 2);

    // Day 3: FIFO at the best ask price.
    const auto best_ask = book.best_ask_order();

    assert(best_ask.has_value());
    assert(best_ask->id == 6);

    // Day 3: Reject a duplicate arrival sequence.
    bool rejected = false;

    try {
        book.add_order(
            Order{9, Side::Buy, 2020, 1, 8}
        );
    } catch (const std::invalid_argument&) {
        rejected = true;
    }

    assert(rejected);

    // The rejected order must not change the best bid.
    assert(book.best_bid_order()->id == 2);

    return 0;
}