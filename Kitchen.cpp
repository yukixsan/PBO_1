#include "Kitchen.h"

// Add an order to the kitchen queue
void Kitchen::takeOrder(int tableId, const std::string& item) {
    Order* newOrder = new Order(nextOrderId++, tableId, item);
    orderQueue.push(newOrder);
    std::cout << "Order " << newOrder->getOrderId() << " for table " << newOrder->getTableId() 
              << " has been added to the kitchen queue." << std::endl;
}

// Simulate cooking the first order in the queue and prompt user to deliver it
void Kitchen::cookOrder() {
    if (!orderQueue.empty()) {
        Order* currentOrder = orderQueue.front();
        std::cout << "Cooking order " << currentOrder->getOrderId() 
                  << " for table " << currentOrder->getTableId() << "..." << std::endl;

        // Simulate cooking (you could add a delay or more complex logic here)
        currentOrder->completeOrder();
        orderQueue.pop();

        // Prompt user to deliver the order to the correct table
        int deliveryTable;
        std::cout << "Order for table " << currentOrder->getTableId() 
                  << " is ready. Enter table number to deliver the order: ";
        std::cin >> deliveryTable;

        if (deliveryTable == currentOrder->getTableId()) {
            std::cout << "Order delivered to table " << deliveryTable << std::endl;
        } else {
            std::cout << "Wrong table! Order not delivered." << std::endl;
        }

        delete currentOrder;  // Clean up the order after it's delivered
    } else {
        std::cout << "No pending orders to cook." << std::endl;
    }
}

// Check if there are any pending orders in the kitchen
bool Kitchen::hasPendingOrders() const {
    return !orderQueue.empty();
}
