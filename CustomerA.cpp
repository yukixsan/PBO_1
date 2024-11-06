#include "CustomerA.h"
#include <iostream>

CustomerA::CustomerA(int id, int tableId, int emotion) : Customer(id, tableId) {}

void CustomerA::Emotion() const {
    std::cout << "Customer " << customerId << " is angry!" << std::endl;
}
