#ifndef ITINERARY_H
#define ITINERARY_H

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "Combination.hpp"

class Itinerary {
private:
    std::string depLoc;
    std::string arrLoc;
    static const int SOLUTION_MAX_COMBINATIONS = 3;
    std::vector<Combination> combinations;

public:
    // Constructor
    Itinerary(const std::string& dep, const std::string& arr, const std::vector<Combination>& listCombo);

    // Getters
    std::vector<Combination> getCombinations();

    // Helper method for findCombinations method
    void findPaths(const std::string &depLoc, std::vector<Flight> currentPath, double totalFare, double totalTime, std::vector<Flight> &flights, std::vector<Combination> &validCombinations, std::set<std::string> visitedAirports);

    // Method to find combinations based on depLoc and arrLoc
    void findCombinations(const std::string &dep, const std::string &arr, std::vector<Flight> &flights);

    // Method to display itinerary information
    void displayInfo();
};

#endif
