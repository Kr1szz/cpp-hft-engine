#pragma once 

#include "Order.hpp"
#include "OrderBook.hpp"

#include <vector>

struct Trade  {
  OrderId makerId;
  OrderId takerId;
  Price price;
  Quantity quantiy;
};

class MatchingEngine { 
public:
  std:: vector<Trade> submitOrder(const Order& order);
}
