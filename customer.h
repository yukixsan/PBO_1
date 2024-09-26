#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <string>

class Customer {
private:
    int customerId;      // Unique ID for each customer
    bool hasOrdered;     // True if the customer has placed an order
    int tableId;         // Table assigned to this customer
    Order* order;        // Pointer to an Order object

public:
    // Constructor
    Customer(int id, int table);

    // Destructor to clean up the order object
    ~Customer();

    // Getter and Setter for hasOrdered
    bool getHasOrdered() const;
    void setHasOrdered(bool ordered);

    // Getter for customerId
    int getCustomerId() const;

    // Getter and Setter for tableId
    int getTableId() const;
    void setTableId(int table);

    // Customer places an order
    void placeOrder(int orderId, const std::string& item);

    // Display customer's order details
    void displayOrder() const;
};

#endif
