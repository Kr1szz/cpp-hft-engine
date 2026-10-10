#include "Order.hpp"

#include <iostream>

int main() {
    const Order buy_order{
        1,
        Side::Buy,
        2005,
        100,
        1
    };

    const Order sell_order{
        2,
        Side::Sell,
        2010,
        50,
        2
    };

    std::cout << "C++ HFT Matching Engine\n";
    std::cout << "-----------------------\n";

    std::cout << "Buy order ID: "
              << buy_order.id << '\n';

    std::cout << "Buy price (ticks): "
              << buy_order.price << '\n';

    std::cout << "Buy quantity: "
              << buy_order.quantity << '\n';

    std::cout << "Sell price (ticks): "
              << sell_order.price << '\n';

    std::cout << "Sell quantity: "
              << sell_order.quantity << '\n';

    if (buy_order.price >= sell_order.price) {
        std::cout << "Orders can potentially match.\n";
    } else {
        std::cout << "No price match yet.\n";
    }

    return 0;
}