#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
private:
    int orderId;         // Unique ID for each order
    int tableId;         // Table associated with the order
    bool isCompleted;    // Whether the order is completed
    std::string item;    // The single item ordered by the customer

public:
    // Constructor
    Order(int id, int table, const std::string& item);

    // Getter and Setter for isCompleted
    bool getIsCompleted() const;
    void completeOrder();

    // Display order details
    void displayOrder() const;

    // Getter for orderId and tableId
    int getOrderId() const;
    int getTableId() const;
};

#endif
