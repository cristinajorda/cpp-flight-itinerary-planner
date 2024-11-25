#include "Itinerary.hpp"
#include <iostream>

// Constructor
Itinerary::Itinerary(const std::string &dep, const std::string &arr, const std::vector<Combination>& listCombo) {
    depLoc = dep;
    arrLoc = arr;
    combinations = listCombo;
}

// Getter for combinations
std::vector<Combination> Itinerary::getCombinations() {
    return combinations;
}

// Helper method for findCombinations method
void Itinerary::findPaths(const std::string &dep, std::vector<Flight> currentPath, double totalFare, double totalTime, std::vector<Flight> &flights, std::vector<Combination> &validCombinations, std::set<std::string> visitedAirports) {
    std::string currentLoc = dep;
    
    // Base case: If current location matches the arrival location, save the path
    if (currentLoc == arrLoc) {
        Combination finishedCombo(currentPath);
        validCombinations.push_back(finishedCombo);

        // If SOLUTION_MAX_COMBINATIONS is reached stop searching
        if (validCombinations.size() < SOLUTION_MAX_COMBINATIONS) {
            return;
        }
    }

    // prints for debugging
    //std::cout << "current loc: " << currentLoc << std::endl;
    //std::cout << "Combinations: [";
    //for (const auto &comb : validCombinations) {
    //    std::cout << "comb " << comb.getID() << std::endl;
    //    for (auto &flight : comb.getFlights()) {
    //        std::cout << flight.getID() << " ";
    //    }
    //}
    //std::cout << "]" << std::endl;
    
    // Iterate over all available flights
    for (int i=0; i<flights.size(); i++) {
        //std::cout << flights[i].getID() << std::endl;
        // Skip flights that do not start at the current location
        if (flights[i].getDepLoc() != currentLoc) {
            //std::cout << "cosa1" << std::endl;
            continue;
        }

        // Skip flights that have depTime < arrTime of last flight in the current path
        if (!currentPath.empty() && flights[i].getDepTime() < currentPath.back().getArrTime()) {
            //std::cout << "cosa2" << std::endl;
            continue;
        }

        // Skip flights to airport already in the path to avoid cycles
        //if (visitedAirports.find(flights[i].getDepLoc()) != visitedAirports.end() || 
        //visitedAirports.find(flights[i].getArrLoc()) != visitedAirports.end()) {
        if (visitedAirports.find(flights[i].getArrLoc()) != visitedAirports.end()) {
            // set.find(element) -> returns iterator pointing to element
            // if not found, returns set.end()
            //std::cout << "cosa3" << std::endl;
            continue;
        }

        // Add the flight to the current path
        currentPath.push_back(flights[i]);
        //std::cout << "flight added to path" << std::endl;

        // Add departure and arrival airports as visited
        visitedAirports.insert(flights[i].getDepLoc());
        visitedAirports.insert(flights[i].getArrLoc());

        // Call again findPaths but with arrLoc of current flight as depLoc
        findPaths(
            flights[i].getArrLoc(),
            currentPath,
            totalFare + flights[i].getFare(),
            totalTime,
            flights,
            validCombinations,
            visitedAirports
        );

        // Backtrack
        // Remove the flight
        currentPath.pop_back();
        // Remove the visited airports
        visitedAirports.erase(flights[i].getDepLoc());
        visitedAirports.erase(flights[i].getArrLoc());
    }
}

// Method to find combinations based on departure and arrival locations
void Itinerary::findCombinations(const std::string& dep, const std::string& arr, std::vector<Flight> &flights) {
    depLoc = dep;
    arrLoc = arr;

    std::vector<Combination> validCombinations;
    std::set<std::string> visitedAirports; // To keep track of visited airports and avoid cycles

    // Call the helper function
    // Recursive backtracking
    findPaths(depLoc, {}, 0.0, 0.0, flights, validCombinations, visitedAirports);

    combinations = validCombinations;
}

// Method to display information about the itinerary
void Itinerary::displayInfo() {
    std::cout << "Itinerary from " << depLoc << " to " << arrLoc << std::endl;
    std::cout << "Number of possible combinations: " << combinations.size() << std::endl;
    
    // Sort combinations by totalFare in ascending order
    std::sort(combinations.begin(), combinations.end(), [](const Combination &a, const Combination &b) {
        return a.getTotalFare() < b.getTotalFare(); // Sort by totalFare
    });

    for (int i=0; i < combinations.size(); i++) {
        std::cout << "Solution " << i+1 << ":" << std::endl;
        combinations[i].displayInfo();
    }
}
