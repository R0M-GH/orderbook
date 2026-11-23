#pragma once

#include <cstdint>
#include <vector>

enum class OrderType {
    GoodTillCancel,
    FillAndKill
};

enum class Side {
    Buy,
    Sell
};

using Price = int32_t;
using Quantity = uint32_t;
using OrderId = uint64_t;

struct LevelInfo {
    Price price_;
    Quantity quantity_;
};

using LevelInfos = std::vector<LevelInfo>;

class OrderbookLevelInfos {
    public:
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
    : bids_{ bids }
    , asks_{ asks }
    { }

    const LevelInfos& GetBids() const { return bids_; }
    const LevelInfos& GetAsks() const { return asks_; }

    private:
    LevelInfos bids_, asks_;
};

class Order {
    public:
    Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
    : orderType_{ orderType }
    , orderId_{orderId }
    , side_{ side }
    , price_{ price }
    , initialQuantity_{ quantity }
    , remainingQuantity_{ quantity }
    { }

    OrderType GetOrderType() const { return orderType_; }
    OrderId GetOrderId() const { return orderId_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return initialQuantity_ - remainingQuantity_; }



    private:
    OrderType orderType_;
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity initialQuantity_, remainingQuantity_;
};
