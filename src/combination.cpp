#include "Combination.hpp"
#include <sstream>  // For creating the ID string

// Constructor: Initializes Combination with a list of flights
Combination::Combination(const std::vector<Flight>& listFlights) {
    flights = listFlights;
    totalFare = 0.0;

    // Initialize the ID by concatenating the IDs of all flights
    std::stringstream ss;
    for (int i=0; i<flights.size(); i++) {
        ss << flights[i].getID() << "_";
    }
    ID = ss.str();
    // Remove the last underscore if there's any
    if (!ID.empty()) {
        ID.pop_back();  // Remove trailing "_"
    }

    // Calculate total fare and total time
    totalFare = computeTotalFare();
}

// Getter for the Combination ID
std::string Combination::getID() const {
    return ID;
}

// Getter for the list of flights
std::vector<Flight> Combination::getFlights() const {
    return flights;
}

// Getter for the total fare
double Combination::getTotalFare() const {
    return totalFare;
}

// Method to compute the total fare of the combination
double Combination::computeTotalFare() {
    double fare = 0.0;
    for (int i=0; i<flights.size(); i++) {
        fare += flights[i].getFare();
    }
    return fare;
}

// Method to display the combination and its flight details
void Combination::displayInfo() {
    // Display the details of each flight in the combination
    for (int i=0; i<flights.size(); i++) {
        flights[i].displayInfo();
    }
    std::cout << "Total price: " << totalFare << std::endl;
}