#include "Kitchen.h"

// Add an order to the kitchen queue
void Kitchen::takeOrder(Order* order) {
    orderQueue.push(order);
    std::cout << "Order " << order->getOrderId() << " for table " << order->getTableId() 
              << " has been added to the kitchen queue." << std::endl;
}

// Simulate cooking the first order in the queue and prompt user to deliver it
void Kitchen::cookOrder() {
    if (!orderQueue.empty()) {
        Order* currentOrder = orderQueue.front();
        std::cout << "Cooking order " << currentOrder->getOrderId() 
                  << " for table " << currentOrder->getTableId() << "..." << std::endl;

        currentOrder->completeOrder();
        orderQueue.pop();

        std::cout << "Order " << currentOrder->getOrderId() << " is ready for delivery." << std::endl;

        delete currentOrder;
    } else {
        std::cout << "No pending orders to cook." << std::endl;
    }
}

// Check if there are any pending orders in the kitchen
bool Kitchen::hasPendingOrders() const {
    return !orderQueue.empty();
}
