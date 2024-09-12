#ifndef KITCHEN_H
#define KITCHEN_H

#include <iostream>
#include <queue>
#include <string>

class Kitchen {
public:
    // Function to receive an order
    void receiveOrder(const std::string& dish);

    // Function to give the completed order to the waiter
    void giveOrderToWaiter();

private:
    std::queue<std::string> orderQueue; // Queue to store the orders
};

#endif // KITCHEN_H
