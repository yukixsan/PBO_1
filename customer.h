#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <iostream>

class Customer {
protected:
    int customerId;
    int tableId;
    Order* order;
    int emotion;

public:
    Customer(int id, int tableId, int emotion = 50) ;

    int getCustomerId() const;
    int getTableId() const;
    void setTableId(int tableId);

    // Customer places an order (no notification, Game Manager handles it)
    void placeOrder(int orderId, const std::string& item);

    virtual void displayOrder() const;
    virtual void Emotion() const = 0;
    int getEmotion() const {return emotion;}
    void decreaseEmotion(int amount);
};

#endif
