#include "Customer.h"

Customer::Customer(const std::string& name) : name(name), emotion(5) {}

std::string Customer::getName() const {
    return name;
}

void Customer::addOrder(const std::string& order) {
    orders.push_back(order);
}

std::vector<std::string> Customer::getOrders() const {
    return orders;
}

void Customer::updateEmotion(int decrement) {
    emotion = std::max(1, emotion - decrement);
}

int Customer::getEmotion() const {
    return emotion;
}
