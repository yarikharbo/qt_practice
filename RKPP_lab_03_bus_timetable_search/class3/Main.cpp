#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "Bus.h"

using namespace std;

string inputString(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    if (s.empty()) {
        throw invalid_argument("String cannot be empty");
    }
    return s;
}

Time inputTime(const string& prompt) {
    Time t;
    cout << prompt;
    cin >> t;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw invalid_argument("Time input error (expected HH:MM)");
    }
    cin.ignore(10000, '\n');
    return t;
}

void Run(const vector<BusBase*>& buses, const string& filename) {
    string targetDest;
    Time limitTime;

    cout << "\n--- Search for buses ---\n";
    try {
        targetDest = inputString("Enter destination: ");
        limitTime = inputTime("Enter maximum arrival time (HH:MM): ");
    } catch (const exception& e) {
        cerr << "Input error: " << e.what() << endl;
        return;
    }

    vector<const BusBase*> suitable;
    for (const auto& b : buses) {
        const Bus* bus = dynamic_cast<const Bus*>(b);
        if (!bus) continue;
        if (bus->getDestination() == targetDest && bus->getArrivalTime() <= limitTime) {
            suitable.push_back(bus);
        }
    }

    sort(suitable.begin(), suitable.end(),
         [](const BusBase* a, const BusBase* b) {
             const Bus* ba = dynamic_cast<const Bus*>(a);
             const Bus* bb = dynamic_cast<const Bus*>(b);
             return ba->getArrivalTime().toMinutes() < bb->getArrivalTime().toMinutes();
         });

    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    if (suitable.empty()) {
        outFile << "No buses satisfy the conditions." << endl;
    } else {
        for (const auto& b : suitable) {
            b->print(outFile);
            outFile << endl;
        }
    }

    outFile.close();
    if (outFile.fail()) {
        throw runtime_error("Error writing to file");
    }

    cout << "Result written to " << filename << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<BusBase*> timetable;

    cout << "Enter bus data :" << endl;

    while (true) {
        try {
            cout << "\n--- New bus ---\n";
            string num;
            cout << "Route number (empty to exit): ";
            getline(cin, num);
            if (num.empty()) break;

            string dest = inputString("Destination: ");
            string type = inputString("Bus type: ");
            Time dep = inputTime("Departure time (HH:MM): ");
            Time arr = inputTime("Arrival time (HH:MM): ");

            if (arr.toMinutes() <= dep.toMinutes()) {
                throw logic_error("Arrival time must be after departure");
            }

            Bus* bus = new Bus(num, dest, type, dep, arr);
            timetable.push_back(bus);
        } catch (const exception& e) {
            cerr << "Input error: " << e.what() << ". Try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    try {
        Run(timetable, "buses_output.txt");
    } catch (const exception& e) {
        cerr << "Run error: " << e.what() << endl;
    }

    for (auto b : timetable) {
        delete b;
    }

    return 0;
}