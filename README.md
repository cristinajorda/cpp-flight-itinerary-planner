# C++ Flight Itinerary Planner

The **C++ Flight Itinerary Planner** is a project for efficiently managing and analyzing flight itineraries. The program allows users to input flight data and search for possible combinations between departure and arrival airports, sorted by cost. It uses recursive backtracking to generate valid flight combinations while avoiding cycles.

## Features

- **Flight Data Management**: Easily input and manage a database of flight details.
- **Efficient Pathfinding**: Generate all valid flight paths between two airports.
- **Sorting**: Display solutions sorted by the total fare (cheapest to most expensive).
- **Cycle Detection**: Prevent infinite loops or revisiting airports.
- **Customizable Constraints**: Define maximum allowable connections or solutions.

## Input Format

The program reads flight data from a text file. Each line in the file represents a flight with the following format:

```text
<Flight ID> <Airline> <Departure Airport> <Arrival Airport> <Departure Time> <Arrival Time> <Fare>
