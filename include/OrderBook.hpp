#pragma once 

#include "Order.hpp"
#include <list>
#include <map>

class OrderBook{
  public: 
    bool addOrder ( const Order& order);
    bool cancelOrder ( OrderId id);

    Price bestBid() const;
    Price bestAsk() const;

    bool empty() const;
};
