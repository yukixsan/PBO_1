#include <iostream>
#include "GameManager.h"
#include "Kitchen.h"
#include "Table.h"
#include "Customer.h"

int main() {
    // Create tables
    Table table1(1);
    Table table2(2);

    // Create kitchen
    Kitchen kitchen;

    // Create Game Manager and pass kitchen and tables to it
    GameManager gameManager(&kitchen, &table1, &table2);

    // Create and add customers to the queue
    Customer customer1(101, -1);
    Customer customer2(102, -1);
    Customer customer3(103, -1);

    gameManager.addCustomerToQueue(&customer1);
    gameManager.addCustomerToQueue(&customer2);
    gameManager.addCustomerToQueue(&customer3);

    // Main game loop to assign customers to tables until the queue is empty
    while (!gameManager.isCustomerQueueEmpty()) {
        int tableChoice;
        std::cout << "Assign customer to a table (1 or 2): ";
        std::cin >> tableChoice;

        if (tableChoice == 1) {
            gameManager.assignCustomerToTable(&table1);
        } else if (tableChoice == 2) {
            gameManager.assignCustomerToTable(&table2);
        } else {
            std::cout << "Invalid table choice." << std::endl;
            continue;
        }

        // Process orders in the kitchen
        gameManager.processOrders();

        // Simulate delivering the order for the assigned table
        gameManager.deliverOrder(tableChoice);
    }

    std::cout << "All customers have been served." << std::endl;
    return 0;
}
