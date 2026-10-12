#include "Order.hpp"

#include <cassert>

int main() {
    const Order order{
        1,
        Side::Buy,
        2005,
        100,
        1
    };

    assert(order.id == 1);
    assert(order.side == Side::Buy);
    assert(order.price == 2005);
    assert(order.quantity == 100);
    assert(order.timestamp == 1);

    return 0;
}