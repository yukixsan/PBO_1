#ifndef DISHWASHER_H
#define DISHWASHER_H

class Dishwasher {
private:
    int score; // Total score accumulated from washing dishes

public:
    // Constructor
    Dishwasher();

    // Method to wash a dirty plate and add score
    void washPlate();

    // Getter for score
    int getScore() const;
};

#endif
