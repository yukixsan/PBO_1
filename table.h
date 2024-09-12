#ifndef TABLE_H
#define TABLE_H

#include "Customer.h"
#include <vector>
#include <string>

class Table {
public:
    Table(int tableNumber);

    // Occupy the table with a customer
    void occupyTable(const Customer& customer);

    // Display orders with their status
    void displayOrders() const;

    // Update the order status
    void updateOrderStatus(const std::string& order, const std::string& status);

    // Get the current customer at the table
    Customer getCurrentCustomer() const;

private:
    int tableNumber;
    Customer currentCustomer;
    std::vector<std::pair<std::string, std::string>> orders; // Order and its status
    bool occupied;
};

#endif // TABLE_H
