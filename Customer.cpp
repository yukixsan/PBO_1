#include "Customer.h"

Customer::Customer(int id, int tableId, int emotion) : customerId(id), tableId(tableId),order(nullptr) {}

int Customer::getCustomerId() const { return customerId; }

int Customer::getTableId() const { return tableId; }

void Customer::setTableId(int tableId) { this->tableId = tableId; }

void Customer::placeOrder(int orderId, const std::string& item) {
    order = new Order(orderId,tableId, item);
    std::cout << "Customer " << customerId << " has placed an order at table " 
              << tableId << " for " << item << "." << std::endl;
}

void Customer::displayOrder() const {
    if (order != nullptr) {
        order->displayOrder();
    } else {
        std::cout << "No order placed." << std::endl;
    }
}
void Customer::decreaseEmotion(int amount)
{
    emotion -= amount;
    if (emotion < 0) emotion = 0;  // Ensures it doesn't go below zero

    
}
