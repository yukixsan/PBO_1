#include "Dishwasher.h"
#include <iostream>

// Constructor initializes the score
Dishwasher::Dishwasher() : score(0) {}

// Wash a dirty plate and add score
void Dishwasher::washPlate() {
    score += 10; // Add 10 points for washing a plate
    std::cout << "Plate washed! You earned 100 money." << std::endl;
}

// Getter for score
int Dishwasher::getScore() const {
    return score;
}
