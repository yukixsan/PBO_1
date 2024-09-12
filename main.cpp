#include "Customer.h"
#include "Table.h"
#include "Kitchen.h"

int main() {
    // Create a kitchen
    Kitchen kitchen;

    // Create a customer and add orders
    Customer customer("John Doe");
    customer.addOrder("Burger");
    customer.addOrder("Fries");

    // Create a table and occupy it with the customer
    Table table(1);
    table.occupyTable(customer);

    // Simulate receiving orders in the kitchen
    for (const auto& order : customer.getOrders()) {
        kitchen.receiveOrder(order);
    }

    // Simulate giving orders to the waiter
    kitchen.giveOrderToWaiter(); // Should give "Burger"
    kitchen.giveOrderToWaiter(); // Should give "Fries"
    kitchen.giveOrderToWaiter(); // Should indicate no orders are left

    // Display the orders at the table
    table.displayOrders();

    // Release the table
    table.releaseTable();
    
    return 0;
}
