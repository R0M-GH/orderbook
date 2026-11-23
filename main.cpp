#include <iostream>

#include "Orderbook.h"

using namespace std;

int main() {
    OrderbookLevelInfos test{
        {{100, 50}, {99, 30}}, {{101, 20}},
    };
    cout << test.GetBids().size() << "\n";
    cout << test.GetAsks().size() << "\n";
}