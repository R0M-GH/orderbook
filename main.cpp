#include <iostream>
#include <memory>
#include <stdexcept>

#include "Orderbook.h"

using namespace std;

int main() {
    // Level testing
    OrderbookLevelInfos test{
        {{100, 50}, {99, 30}}, {{101, 20}},
    };
    cout << test.GetBids().size() << "\n";
    cout << test.GetAsks().size() << "\n\n";

    // Order testing
    OrderPointer o = make_shared<Order>(OrderType::FillAndKill, 1, Side::Buy, 10, 10);
    try {
        cout << o->GetFilledQuantity() << "\n";
        o->Fill(7);
        cout << o->GetFilledQuantity() << "\n";
        o->Fill(4);
        cout << o->GetFilledQuantity() << "\n";
    } catch (const logic_error& e) {
        cout << e.what() << "\n\n";
    }
}