#include "CustomerA.h"
#include <iostream>

CustomerA::CustomerA(int id, int tableId) : Customer(id, tableId) {}

void CustomerA::emotion() const {
    std::cout << "Customer " << customerId << " is angry!" << std::endl;
}
