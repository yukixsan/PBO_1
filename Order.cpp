#include "Order.h"
#include <iostream>

// Constructor
Order::Order(int id, int table, const std::string& orderItem) 
    : orderId(id), tableId(table), isCompleted(false), item(orderItem) {}

// Getter for isCompleted
bool Order::getIsCompleted() const {
    return isCompleted;
}

// Mark order as completed
void Order::completeOrder() {
    isCompleted = true;
    std::cout << "Order " << orderId << " has been completed." << std::endl;
}

// Display order details
void Order::displayOrder() const {
    std::cout << "Order ID: " << orderId << "\nTable ID: " << tableId 
              << "\nItem: " << item << "\nOrder Completed: " 
              << (isCompleted ? "Yes" : "No") << std::endl;
}

// Getter for orderId
int Order::getOrderId() const {
    return orderId;
}

// Getter for tableId
int Order::getTableId() const {
    return tableId;
}
