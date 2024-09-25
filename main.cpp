#include <iostream>
#include "Table.h"

int main()
{
    // Create a table with ID 1
    Table table1(1);

    // Check if the table is occupied
    std::cout << "Table " << table1.getTableId() << " is occupied? " << (table1.getIsOccupied() ? "Yes" : "No") << std::endl;

    // Set the table to occupied
    table1.setIsOccupied(true);

    // Check again
    std::cout << "Table " << table1.getTableId() << " is occupied? " << (table1.getIsOccupied() ? "Yes" : "No") << std::endl;

    return 0;
}