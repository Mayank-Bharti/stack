#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// User Class
class User {
public:
    string userId, name;
    double funds;

    User(){}

    User(string userId, string name, double funds) {
        this->userId = userId;
        this->name = name;
        this->funds = funds;
    }

    void deductFunds(double amount) {
        if (funds >= amount) {
            funds -= amount;
        } else {
            cout << "ERROR: Insufficient funds for user " << userId << endl;
        }
    }

    void display() {
        cout << "<" << userId << ", " << name << ", " << funds << ">" << endl;
    }
};

// Flight Fare Class
class Fare {
public:
    string fareType;
    double price;
    set<string> availableSeats;

    Fare(){}

    Fare(string fareType, double price, vector<string> seats) {
        this->fareType = fareType;
        this->price = price;
        availableSeats = set<string>(seats.begin(), seats.end());
    }

    bool isSeatAvailable(const string &seat) {
        return availableSeats.find(seat) != availableSeats.end();
    }

    bool bookSeats(vector<string> &seats) {
        for (auto &seat : seats) {
            if (!isSeatAvailable(seat)) return false;
        }
        for (auto &seat : seats) {
            availableSeats.erase(seat);
        }
        return true;
    }
};

// Flight Class
class Flight {
public:
    string flightNumber, airline, from, to;
    int departDate;
    double departTime;
    unordered_map<string, Fare> fares; // fareType -> Fare Object

    Flight() {}

    Flight(string flightNumber, string airline, string from, string to, int departDate, double departTime) {
        this->flightNumber = flightNumber;
        this->airline = airline;
        this->from = from;
        this->to = to;
        this->departDate = departDate;
        this->departTime = departTime;
    }

    void addFare(string fareType, double price, vector<string> seats) {
        fares[fareType] = Fare(fareType, price, seats);
    }

    void display() {
        cout << "<" << flightNumber << ", " << airline << ", " << from << ", " << to << ", " << departDate
             << ", " << departTime << ">" << endl;
    }
};

// Flight Inventory Management System
class FlightInventory {
private:
    unordered_map<string, User> users;
    unordered_map<string, Flight> flights;

public:
    void addUser(string userId, string name, double funds) {
        users[userId] = User(userId, name, funds);
        users[userId].display();
    }

    void addFlight(string flightNumber, string airline, string from, string to, int departDate, double departTime) {
        flights[flightNumber] = Flight(flightNumber, airline, from, to, departDate, departTime);
    }

    void addFareToFlight(string flightNumber, string fareType, double price, vector<string> seats) {
        if (flights.find(flightNumber) != flights.end()) {
            flights[flightNumber].addFare(fareType, price, seats);
        }
    }

    void searchFlight(string from, string to, int departDate, int paxCount) {
        for (auto &pair : flights) {
            Flight &flight = pair.second;
            if (flight.from == from && flight.to == to && flight.departDate == departDate) {
                for (auto &farePair : flight.fares) {
                    if (farePair.second.availableSeats.size() >= paxCount) {
                        flight.display();
                        cout << "Fare: " << farePair.first << ", Price: " << farePair.second.price << ", Seats: ";
                        for (const string &seat : farePair.second.availableSeats)
                            cout << seat << " ";
                        cout << endl;
                    }
                }
            }
        }
    }

    void bookFlight(string userId, string flightNumber, string fareType, vector<string> seats) {
        if (users.find(userId) == users.end()) {
            cout << "ERROR: User not found" << endl;
            return;
        }
        if (flights.find(flightNumber) == flights.end()) {
            cout << "ERROR: Flight not found" << endl;
            return;
        }

        User &user = users[userId];
        Flight &flight = flights[flightNumber];

        if (flight.fares.find(fareType) == flight.fares.end()) {
            cout << "ERROR: Fare type not found" << endl;
            return;
        }

        Fare &fare = flight.fares[fareType];
        double totalPrice = fare.price * seats.size();

        if (user.funds < totalPrice) {
            cout << "ERROR: Insufficient funds" << endl;
            return;
        }

        if (!fare.bookSeats(seats)) {
            cout << "ERROR: One or more seats are already booked" << endl;
            return;
        }

        user.deductFunds(totalPrice);
        cout << "BOOKING SUCCESS: " << userId << " booked flight " << flightNumber << " for fare " << fareType
             << " with seats ";
        for (auto &seat : seats) cout << seat << " ";
        cout << endl;
    }
};

// Main function
int main() {
    FlightInventory system;

    // Adding Users
    system.addUser("u1", "Vinit", 5000);
    system.addUser("u2", "Neha", 1500);

    // Adding Flights
    system.addFlight("111", "IndiGo", "DEL", "BLR", 2, 10.30);
    system.addFlight("222", "Air India", "DEL", "BLR", 2, 12.00);

    // Adding Fares
    system.addFareToFlight("111", "F1", 2000, {"10A", "11C", "20B"});
    system.addFareToFlight("222", "F2", 2500, {"5A", "6B", "7C"});

    // Searching Flights
    cout << "\nSearching Flights (DEL -> BLR on Day 2 for 1 pax):\n";
    system.searchFlight("DEL", "BLR", 2, 1);

    // Booking Flights
    cout << "\nBooking Flights:\n";
    system.bookFlight("u1", "111", "F1", {"10A", "11C"});
    system.bookFlight("u2", "222", "F2", {"5A"});

    return 0;
}
