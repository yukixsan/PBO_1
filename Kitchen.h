#ifndef KITCHEN_H
#define KITCHEN_H

#include "Order.h"
#include <queue>
#include <iostream>

class Kitchen {
private:
    std::queue<Order*> orderQueue;

public:
    // Add an order to the kitchen queue
    void takeOrder(Order* order);

    // Simulate cooking and prompt delivery
    void cookOrder();

    // Check if there are any pending orders
    bool hasPendingOrders() const;
};

#endif
