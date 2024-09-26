#ifndef KITCHEN_H
#define KITCHEN_H

#include "Order.h"
#include <queue>
#include <iostream>

class Kitchen {
private:
    std::queue<Order*> orderQueue; // Queue to manage orders being processed
    int nextOrderId = 1;           // Auto-incrementing order ID

public:
    // Add an order to the kitchen queue
    void takeOrder(int tableId, const std::string& item);

    // Simulate cooking and prompt delivery
    void cookOrder();

    // Check if there are any pending orders
    bool hasPendingOrders() const;
};

#endif
