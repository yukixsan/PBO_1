// Kitchen.cpp
#include "Kitchen.h"

void Kitchen::receiveOrder(const std::string& dish) {
    orderQueue.push(dish);
    std::cout << "Order received: " << dish << std::endl;
}

void Kitchen::giveOrderToWaiter() {
    if (orderQueue.empty()) {
        std::cout << "No orders to serve!" << std::endl;
        return;
    }
    std::string completedOrder = orderQueue.front();
    orderQueue.pop();
    std::cout << "Order ready for waiter: " << completedOrder << std::endl;
}
