#include "CustomerB.h"
#include <iostream>

CustomerB::CustomerB(int id, int tableId, int emotion) : Customer(id, tableId) {}

void CustomerB::Emotion() const  {
    std::cout << "Customer " << customerId << " is leaving." << std::endl;
}
