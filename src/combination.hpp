#ifndef COMBINATION_H
#define COMBINATION_H

#include "Flight.hpp"
#include <vector>
#include <string>

class Combination {
private:
    std::string ID;                // Combination ID (string of concatenated flight IDs)
    std::vector<Flight> flights;   // List of Flight objects
    double totalFare;              // Total fare of the combination

public:
    // Constructor
    Combination(const std::vector<Flight>& flights);

    // Getters
    std::string getID() const;
    std::vector<Flight> getFlights() const;
    double getTotalFare() const;

    // Methods to compute total fare and total time
    double computeTotalFare();

    // Method to display the combination and its flight details
    void displayInfo();

};

#endif
