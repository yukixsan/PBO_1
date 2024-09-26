#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Customer.h"
#include "Kitchen.h"
#include "Table.h"
#include <vector>
#include <queue>

class GameManager {
private:
    Kitchen* kitchen;  
    Table* table1;    // Pointer to Table 1
    Table* table2;    // Pointer to Table 2
    std::queue<Customer*> customerQueue; // Queue of customers

public:
    // Constructor to initialize the kitchen and tables
    GameManager(Kitchen* kitchen, Table* table1, Table* table2);

    // Add a new customer to the queue
    void addCustomerToQueue(Customer* customer);

    // Assign a customer to a table
    void assignCustomerToTable(Table* table);

    // Handle order placement and notify kitchen
    void orderPlaced(Customer* customer);

    // Process all orders in the kitchen
    void processOrders();

    // Handle the order delivery process
    void deliverOrder(int tableId);

    // Check if the customer queue is empty
    bool isCustomerQueueEmpty() const;
    
    // Free the table after delivering an order
    void freeTable(int tableId);
};

#endif
