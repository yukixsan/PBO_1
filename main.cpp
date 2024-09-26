#include <iostream>
#include "Table.h"
#include "Customer.h"
#include "Order.h"
#include "Kitchen.h"

int main() {
    // Create two tables with IDs 1 and 2
    Table table1(1);
    Table table2(2);

    // Generate one customer
    Customer customer1(100, -1); // Initialize with no table (tableId = -1)

    // Kitchen object to manage cooking orders
    Kitchen kitchen;

    // Prompt the user to select a table for the customer
    int tableChoice;
    std::cout << "Assign customer to a table (1 or 2): ";
    std::cin >> tableChoice;

    // Check user input and assign customer to the appropriate table
    if (tableChoice == 1 && !table1.getIsOccupied()) {
        customer1.setTableId(table1.getTableId());
        table1.setIsOccupied(true);
        std::cout << "Customer " << customer1.getCustomerId() << " is assigned to Table " << table1.getTableId() << std::endl;
    } 
    else if (tableChoice == 2 && !table2.getIsOccupied()) {
        customer1.setTableId(table2.getTableId());
        table2.setIsOccupied(true);
        std::cout << "Customer " << customer1.getCustomerId() << " is assigned to Table " << table2.getTableId() << std::endl;
    } 
    else {
        std::cout << "Invalid selection or table is occupied. Exiting." << std::endl;
        return 1; // Exit the program if the table selection is invalid or occupied
    }

    // Automatically set the customer's order to "Food"
    std::string orderItem = "Food";

    // Customer places the order automatically
    customer1.placeOrder(1, orderItem); // We assume orderId is 1 for simplicity

    // Send the order to the kitchen
    kitchen.takeOrder(customer1.getTableId(), orderItem);

    // Simulate cooking and prompt delivery
    while (kitchen.hasPendingOrders()) {
        kitchen.cookOrder();  // Kitchen processes one order at a time
    }

    return 0;
}
