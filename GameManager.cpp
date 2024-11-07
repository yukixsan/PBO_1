#include "GameManager.h"
#include "CustomerA.h"
#include "CustomerB.h"
#include <iostream>
#include <cstdlib>

// Constructor initializes the kitchen and tables
GameManager::GameManager(Kitchen* kitchen, Table* table1, Table* table2, Dishwasher* dishwasher) 
    : kitchen(kitchen), table1(table1), table2(table2), dishwasher(dishwasher), lastOrderId(0) {}

// Add a customer to the queue
void GameManager::addCustomerToQueue() {
    
    int randomCustomerType = rand() % 2;  // 0 or 1
    int customerId = nextCustomerId++;  // Incremental customer ID
    Customer* newCustomer;
      if (randomCustomerType == 0) {
        newCustomer = new CustomerA(customerId,-1,50);
        std::cout << "Generated CustomerA with ID " << customerId << std::endl;
    } else {
        newCustomer = new CustomerB(customerId,-1,50);
        std::cout << "Generated CustomerB with ID " << customerId << std::endl;
    }

    if (customerQueue.size() < 3) { // Limit to 3 customers
        customerQueue.push(newCustomer);
         std::cout << "Customer added to the queue. Current queue size: " << customerQueue.size() << std::endl;
    } else {
        std::cout << "Customer queue is full (max 3 customers).\n";
    }
}

// Check if customer queue is empty
bool GameManager::isCustomerQueueEmpty() const {
    return customerQueue.empty();
}

// Assign a customer from the queue to a table
void GameManager::assignCustomerToTable(Table* table) {
    if (!table->getIsOccupied() && !customerQueue.empty()) {
        Customer* customer = customerQueue.front(); // Get the first customer in the queue
        customerQueue.pop();                         // Remove the customer from the queue
        customer->setTableId(table->getTableId());
        table->setIsOccupied(true);

        tableCustomers[table->getTableId()] = customer;

        std::cout << "Customer " << customer->getCustomerId() 
                  << " has been assigned to table " << table->getTableId() << std::endl;
        // Automatically place an order for the customer
        orderPlaced(customer);                       
    } else {
        if (table->getIsOccupied()) {
            std::cout << "Table " << table->getTableId() << " is already occupied." << std::endl;
        } else {
            std::cout << "No customers in the queue." << std::endl;
        }
    }
}int GameManager::getNextOrderId() {
    return ++lastOrderId; // Increment and return the next order ID
}
// Notify the kitchen when a customer places an order
void GameManager::orderPlaced(Customer* customer) {
    std::string orderItem = "Food";  // Automatically assign the order to "Food"
    // Create the order with the orderId matching tableId
     int orderId = getNextOrderId(); // Get the next order ID
    customer->placeOrder(orderId, orderItem);  
    kitchen->takeOrder(new Order(orderId, customer->getTableId(), orderItem));  

    std::cout << "Order for " << orderItem << " placed for table " 
              << customer->getTableId() << "." << std::endl;
}

// Process orders in the kitchen (cooking all pending orders)
void GameManager::processOrders() {
    while (kitchen->hasPendingOrders()) {
        kitchen->cookOrder();  // Cook one order at a time
    }
}

// Handle delivering orders to the correct table
void GameManager::deliverOrder(int tableId) {
    int deliveryTable;
    std::cout << "Enter table number to deliver the order: ";
    std::cin >> deliveryTable;
    
    Customer* customer = tableCustomers[tableId];
    customer->getTableId();
    if (deliveryTable == tableId) {
        std::cout << "Order successfully delivered to table " << tableId << "." << std::endl;
    } 
    else 
    {
        customer->decreaseEmotion(50);
        //std::cout << "Wrong table! The order was not delivered." << std::endl;
        if (customer->getEmotion() <= 0) 
        { // Check if emotion has reached zero
            customer->Emotion();
            freeTable(tableId);
        } // Free the table
    }
}
void GameManager::takeDirtyPlate() 
{
    if (table1->getIsOccupied() && table1->getIsOccupied()) {
        std::cout << "Taking dirty plate from table " << table1->getTableId() << " to the dishwasher..." << std::endl;
        dishwasher->washPlate();
        freeTable(table1->getTableId()); // Free the table after washing
    } else if (table2->getIsOccupied()) {
        std::cout << "Taking dirty plate from table " << table2->getTableId() << " to the dishwasher..." << std::endl;
        dishwasher->washPlate();
        freeTable(table2->getTableId()); // Free the table after washing
    } else {
        std::cout << "No completed orders to wash." << std::endl;
    }
}
void GameManager::freeTable(int tableId) {
    if (tableId == 1) {
        table1->setIsOccupied(false); // Free table 1
        std::cout << "Table 1 has been freed." << std::endl;
    } else if (tableId == 2) {
        table2->setIsOccupied(false); // Free table 2
        std::cout << "Table 2 has been freed." << std::endl;
    } else {
        std::cout << "Invalid table ID." << std::endl;
    }
        tableCustomers.erase(tableId);

}
void GameManager::displayQueueSize() const {
    std::cout << "Customers in queue: " << customerQueue.size() << std::endl;
}
