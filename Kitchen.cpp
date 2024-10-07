#include "Kitchen.h"
#include <iostream>

// Add an order to the kitchen queue
void Kitchen::takeOrder(Order* order) {
    orderQueue.push(order);
    std::cout << "Order " << order->getOrderId() << " for table " << order->getTableId() 
              << " has been added to the kitchen queue." << std::endl;
}

// Simulate cooking the first order in the queue and prompt the user to deliver it
void Kitchen::cookOrder() {
    if (!orderQueue.empty()) {
        // Get the current order at the front of the queue
        Order* currentOrder = orderQueue.front();
        
        // Display cooking message for the current order
        std::cout << "Cooking order " << currentOrder->getOrderId() 
                  << " for table " << currentOrder->getTableId() << "..." << std::endl;

        // Mark the order as completed
        currentOrder->completeOrder();
        
        // Remove the order from the queue after it's cooked
        orderQueue.pop();

        // Notify that the order is ready for delivery
        std::cout << "Order " << currentOrder->getOrderId() << " for table " 
                  << currentOrder->getTableId() << " is ready for delivery." << std::endl;

        // Clean up memory after cooking the order
        delete currentOrder;
    } else {
        std::cout << "No pending orders to cook." << std::endl;
    }
}

// Check if there are any pending orders in the kitchen
bool Kitchen::hasPendingOrders() const {
    return !orderQueue.empty();
}
