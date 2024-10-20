#include <iostream>
#include "GameManager.h"
#include "Table.h"
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
#include "CustomerA.h"
#include "CustomerB.h"
#include "Kitchen.h"

int main() {
    // Initialize tables and kitchen
    Table table1(1);
    Table table2(2);
    Kitchen kitchen;
    Dishwasher dishwasher;

    // Create GameManager and pass kitchen and tables
    GameManager gameManager(&kitchen, &table1, &table2, &dishwasher);
   

    int choice;
    do {
         gameManager.addCustomerToQueue();
        std::cout << "===== Diner Dash Menu =====\n";
        std::cout << "1. Assign customer to table\n";
        std::cout << "2. Take order from table\n";
        std::cout << "3. Take dirty plate from table\n";
        std::cout << "4. Exit\n";
        gameManager.displayQueueSize();  // Display the number of customers in the queue
        std::cout << "===========================\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int tableChoice;
                std::cout << "Assign customer to which table (1 or 2)? ";
                std::cin >> tableChoice;

                if (tableChoice == 1) {
                    gameManager.assignCustomerToTable(&table1);
                } else if (tableChoice == 2) {
                    gameManager.assignCustomerToTable(&table2);
                } else {
                    std::cout << "Invalid table choice.\n";
                }
                break;
            }
            case 2: {
                int tableChoice;
                std::cout << "Take order from which table (1 or 2)? ";
                std::cin >> tableChoice;

                if (tableChoice == 1 && table1.getIsOccupied()) {
                    gameManager.processOrders();  // Process the order in the kitchen
                    gameManager.deliverOrder(table1.getTableId());  // Deliver the order
                } else if (tableChoice == 2 && table2.getIsOccupied()) {
                    gameManager.processOrders();  // Process the order in the kitchen
                    gameManager.deliverOrder(table2.getTableId());  // Deliver the order
                } else {
                    std::cout << "No customer at table " << tableChoice << ".\n";
                }
                break;
            }
            case 3:
            {
                gameManager.takeDirtyPlate(); // Call the method to take dirty plate
                break;
            }
            case 4: {
                std::cout << "Exiting the game.\n";
                break;
            }
            default: {
                std::cout << "Invalid option. Please choose again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
