#ifndef CUSTOMERA_H
#define CUSTOMERA_H

#include "Customer.h"

class CustomerA : public Customer {
public:

    CustomerA(int id, int tableId, int emotion);
    void Emotion() const override;
};

#endif
