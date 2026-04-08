#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <ctime>
#include <stack>
#include <limits>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>
using namespace std;

enum class OrderType{
    GoodTillCancel,
    FillAndKill
};

enum class Side{
    Buy,
    Sell
};

using Price = int32_t;
using Quantity = uint32_t;
using OrderId = uint64_t;

struct LevelInfo{
    Price price_;
    Quantity quantity_;
};

using LevelInfos = vector<LevelInfo>;

class OrderbookLevelInfos{
    private:
        LevelInfos bids_;
        LevelInfos asks_;
    
    public:
        OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
            : bids_{ bids }
            , asks_{ asks }
        { }
        const LevelInfos& GetBids() const { return bids_; }
        const LevelInfos& GetAsks() const { return asks_; }
};

class Order{
    private:
        OrderId orderId_;
        OrderType orderType_;
        Side side_;
        Price price_;
        Quantity initialQuantity_;
        Quantity remainingQuantity_;
    public:
        Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
            : orderType_{ orderType }
            , orderId_{ orderId }
            , side_{ side }
            , price_{ price }
            , initialQuantity_{ quantity }
            , remainingQuantity_{ quantity }
        {}
        OrderId GetOrderId() const { return orderId_; }
        Side GetSide() const { return side_; }
        OrderType GetOrderType() const { return orderType_; }
        Side GetSide() const { return side_; }
        Quantity GetInitialQuantity() const { return initialQuantity_; }
        Quantity GetRemainingQuantity() const { return remainingQuantity_; }
        Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }
        
        void Fill(Quantity quantity){
            if(quantity > GetRemainingQuantity()){
                throw logic_error("Order (" + to_string(GetOrderId()) + ") cannot be filled for more than its remaining quantity.");
            }
        }

};

int main(){
    return 0;
}