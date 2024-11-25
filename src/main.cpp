#include "Flight.hpp"
#include "Combination.hpp"
#include "Itinerary.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

int main() {
    // Create flight database
    std::vector<Flight> flights;

    // Open the input file
    std::ifstream inputFile("C:/Users/cjordaicustal/Documents/C++/Project/input_data.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open input data text file" << std::endl;
        return 1;
    }

    // Read input file
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);

        std::string id, airline, depLoc, arrLoc, depTimeStr, arrTimeStr, fareStr;
        double depTime, arrTime, fare;

        // Parse the line
        if (iss >> id >> airline >> depLoc >> arrLoc >> depTimeStr >> arrTimeStr >> fareStr) {
            // Convert depTimeStr and arrTimeStr to double
            depTime = std::stod(depTimeStr);
            arrTime = std::stod(arrTimeStr);
            fare = std::stod(fareStr);

            // Create a Flight object and add it to the flights vector
            Flight new_flight = Flight(id, airline, depLoc, arrLoc, depTime, arrTime, fare);
            flights.push_back(new_flight);
        } else {
            std::cerr << "Error: Invalid line format: " << line << std::endl;
        }
    }

    // Close input file
    inputFile.close();
    
    // Create an empty itinerary
    Itinerary it("", "", {});

    // Get user input
    std::string depLoc, arrLoc;
    std::cout << "Enter departure location: ";
    std::cin >> depLoc;
    std::cout << "Enter arrival location: ";
    std::cin >> arrLoc;

    // Convert input to uppercase
    std::transform(depLoc.begin(), depLoc.end(), depLoc.begin(), ::toupper);
    std::transform(arrLoc.begin(), arrLoc.end(), arrLoc.begin(), ::toupper);

    it.findCombinations(depLoc, arrLoc, flights);

    // Display the result
    if (!it.getCombinations().empty()) {
        it.displayInfo();
    } else {
        std::cout << "No valid combination found for " << depLoc << " to " << arrLoc << std::endl;
    }

    return 0;
}
