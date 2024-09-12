#include "Table.h"
#include <iostream>

Table::Table(int tableNumber) : tableNumber(tableNumber), occupied(false) {}

void Table::occupyTable(const Customer& customer) {
    currentCustomer = customer;
    occupied = true;
}

void Table::displayOrders() const {
    if (occupied) {
        std::cout << "Orders for " << currentCustomer.getName() << " at Table " << tableNumber << ":\n";
        for (const auto& order : orders) {
            std::cout << " - " << order.first << ": " << order.second << "\n";
        }
    } else {
        std::cout << "Table " << tableNumber << " is not occupied.\n";
    }
}

void Table::updateOrderStatus(const std::string& order, const std::string& status) {
    for (auto& o : orders) {
        if (o.first == order) {
            o.second = status;
        }
    }
}

Customer Table::getCurrentCustomer() const {
    return currentCustomer;
}
