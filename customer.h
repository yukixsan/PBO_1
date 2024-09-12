#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(const std::string& name);

    // Get the customer's name
    std::string getName() const;

    // Add an order
    void addOrder(const std::string& order);

    // Get all orders
    std::vector<std::string> getOrders() const;

    // Update emotion level
    void updateEmotion(int decrement);

    // Get current emotion level
    int getEmotion() const;

private:
    std::string name;
    std::vector<std::string> orders;
    int emotion;
};

#endif // CUSTOMER_H
