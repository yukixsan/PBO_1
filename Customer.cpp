#include "Customer.h"
#include <iostream>

// Constructor
Customer::Customer(int id, int table) : customerId(id), tableId(table), hasOrdered(false), order(nullptr) {}

// Destructor
Customer::~Customer() {
    delete order;
}

// Getter for hasOrdered
bool Customer::getHasOrdered() const {
    return hasOrdered;
}

// Setter for hasOrdered
void Customer::setHasOrdered(bool ordered) {
    hasOrdered = ordered;
}

// Getter for customerId
int Customer::getCustomerId() const {
    return customerId;
}

// Getter for tableId
int Customer::getTableId() const {
    return tableId;
}

// Setter for tableId
void Customer::setTableId(int table) {
    tableId = table;
}

// Customer places an order
void Customer::placeOrder(int orderId, const std::string& item) {
    if (!hasOrdered) {
        order = new Order(orderId, tableId, item);
        hasOrdered = true;
        std::cout << "Customer " << customerId << " has placed an order at table " << tableId 
                  << " for " << item << "." << std::endl;
    } else {
        std::cout << "Customer " << customerId << " has already placed an order." << std::endl;
    }
}

// Display customer's order details
void Customer::displayOrder() const {
    if (order) {
        order->displayOrder();
    } else {
        std::cout << "Customer " << customerId << " has not placed any orders yet." << std::endl;
    }
}
