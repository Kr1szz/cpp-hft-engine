#pragma once 

#include <cstdint>
using orderId  = std::uint64_t;
using Price = std::uint64_t;
using Quantity = std:: uint64_t;

enum class Side{
  Buy,
  Sell
};

enum class OrderType{
  Limit,
  Market
};

struct Order{
  orderID id;
  Side side;
  OrderType type;
  Price price;
  Quantity quantity;
  std::uint64_t timestamp;
};
