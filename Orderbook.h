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
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks) {
        bids_ = bids;
        asks_ = asks;
    }

    const LevelInfos& GetBids() const {
        return bids_;
    }

    const LevelInfos& GetAsks() const {
        return asks_;
    }

    private:
    LevelInfos bids_, asks_;
};
