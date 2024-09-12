// Main.cpp
#include "Kitchen.h"

int main() {
    Kitchen kitchen;
    kitchen.receiveOrder("Pasta");

    kitchen.giveOrderToWaiter(); // Gives the first order ("Pasta")
    kitchen.giveOrderToWaiter(); // No orders left

    return 0;
}