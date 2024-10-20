#include "CustomerB.h"
#include <iostream>

CustomerB::CustomerB(int id, int tableId) : Customer(id, tableId) {}

void CustomerB::emotion() const {
    std::cout << "Customer " << customerId << " is leaving." << std::endl;
}
