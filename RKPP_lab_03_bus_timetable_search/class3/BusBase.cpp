#include "BusBase.h"
#include <stdexcept>

BusBase::BusBase(const std::string& num, const std::string& dest, const std::string& type)
    : routeNumber(num), destination(dest), busType(type) {
    if (num.empty() || dest.empty() || type.empty()) {
        throw std::invalid_argument("Fields cannot be empty");
    }
}

BusBase::~BusBase() {}

std::string BusBase::getRouteNumber() const { return routeNumber; }
std::string BusBase::getDestination() const { return destination; }
std::string BusBase::getBusType() const { return busType; }