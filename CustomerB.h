#ifndef CUSTOMERB_H
#define CUSTOMERB_H

#include "Customer.h"

class CustomerB : public Customer {
public:
    CustomerB(int id, int tableId);
    void emotion() const override;
};

#endif
