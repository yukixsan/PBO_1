#include "Table.h"

// Constructor
Table::Table(int id) : tableId(id), isOccupied(false) {}

// Getter for isOccupied
bool Table::getIsOccupied() const {
    return isOccupied;
}

// Setter for isOccupied
void Table::setIsOccupied(bool occupied) {
    isOccupied = occupied;
}

// Getter for tableId
int Table::getTableId() const {
    return tableId;
}
