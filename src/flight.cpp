#include "Flight.hpp"

// Constructor
Flight::Flight(const std::string &id, const std::string &air, const std::string &dep, const std::string &arr, double depT, double arrT, double fr) {
    ID = id;
    airline = air;
    depLoc = dep;
    arrLoc = arr;
    depTime = depT;
    arrTime = arrT;
    fare = fr;
}

// Getters
std::string Flight::getID() {
    return ID;
}
std::string Flight::getAirline() {
    return airline;
}
std::string Flight::getDepLoc() {
    return depLoc;
}
std::string Flight::getArrLoc() {
    return arrLoc;
}
double Flight::getDepTime() {
    return depTime;
}
double Flight::getArrTime() {
    return arrTime;
}
double Flight::getFare() {
    return fare;
}

// Setters
void Flight::setID(const std::string &id) {
    ID = id;
}
void Flight::setAirline(const std::string &air) {
    airline = air;
}
void Flight::setDepLoc(const std::string &dep) {
    depLoc = dep;
}
void Flight::setArrLoc(const std::string &arr) {
    arrLoc = arr;
}
void Flight::setDepTime(double depT) {
    depTime = depT;
}
void Flight::setArrTime(double arrT) {
    arrTime = arrT;
}
void Flight::setFare(double fr) {
    fare = fr;
}

// Method to display flight information
void Flight::displayInfo() {
    // Extract hours and minutes from depTime and arrTime
    int depHours = static_cast<int>(depTime);  // Get the hour part
    int depMinutes = static_cast<int>((depTime - depHours) * 100);  // Get the minute part
    int arrHours = static_cast<int>(arrTime);  // Get the hour part
    int arrMinutes = static_cast<int>((arrTime - arrHours) * 100);  // Get the minute part

    std::cout << ID << " " << airline << " " << depLoc << " " << arrLoc << " " 
    << std::setw(2) << std::setfill('0') << depHours << ":" << std::setw(2) << std::setfill('0') << depMinutes << " "
    << std::setw(2) << std::setfill('0') << arrHours << ":" << std::setw(2) << std::setfill('0') << arrMinutes << " "
    << std::fixed << std::setprecision(2) << fare << std::endl;
}