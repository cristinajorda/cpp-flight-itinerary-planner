#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>
#include <iomanip>

class Flight {
private:
    std::string ID;
    std::string airline;
    std::string depLoc;
    std::string arrLoc;
    double depTime;
    double arrTime;
    double fare;

public:
    // Constructor
    Flight(const std::string &id, const std::string &air, const std::string &dep, const std::string &arr, double depT, double arrT, double fr);

    // Getters
    std::string getID();
    std::string getAirline();
    std::string getDepLoc();
    std::string getArrLoc();
    double getDepTime();
    double getArrTime();
    double getFare();

    // Setters
    void setID(const std::string &id);
    void setAirline(const std::string &air);
    void setDepLoc(const std::string &dep);
    void setArrLoc(const std::string &arr);
    void setDepTime(double depT);
    void setArrTime(double arrT);
    void setFare(double fr);

    // Method to display flight information
    void displayInfo();
};

#endif