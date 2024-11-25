# C++ Flight Itinerary Planner

The **C++ Flight Itinerary Planner** is a project for efficiently managing and analyzing flight itineraries. The program allows users to input flight data and search for possible combinations between departure and arrival airports, sorted by cost. It uses recursive backtracking to generate valid flight combinations while avoiding cycles.

## Features

- **Flight Data Management**: Easily input and manage a database of flight details.
- **Efficient Pathfinding**: Generate all valid flight paths between two airports.
- **Sorting**: Display solutions sorted by the total fare (cheapest to most expensive).
- **Cycle Detection**: Prevent infinite loops or revisiting airports.
- **Customizable Constraints**: Define maximum allowable connections or solutions.

## Input Format

The program reads flight data from a text file, input_data.txt. Each line in the file represents a flight with the following format:

`<Flight ID> <Airline> <Departure Airport> <Arrival Airport> <Departure Time> <Arrival Time> <Fare>`

## Code Structure

The project consists of several core classes that work together to handle the flight itinerary logic.

- **`Flight`**: Holds data related to a single flight (ID, airline, airports, times, fare).
- **`Combination`**: Represents an itinerary, i.e., a valid combination of flights from departure to arrival.
- **`Itinerary`**: Orchestrates the process of finding flight combinations between two airports, using recursion and backtracking.

Each class has a clear responsibility, making the project modular and easy to maintain or extend.
