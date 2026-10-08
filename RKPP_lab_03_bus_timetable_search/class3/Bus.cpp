#include "Bus.h"

Bus::Bus(const std::string& num, const std::string& dest, const std::string& type,
    const Time& dep, const Time& arr)
    : BusBase(num, dest, type), TimeInfo(dep, arr) {
}

Bus::~Bus() {}

void Bus::print(std::ostream& os) const {
    os << "Route: " << routeNumber << ", type: " << busType
        << ", destination: " << destination
        << ", departure: " << departureTime << ", arrival: " << arrivalTime;
}