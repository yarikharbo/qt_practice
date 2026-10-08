#include "TimeInfo.h"

TimeInfo::TimeInfo(const Time& dep, const Time& arr) : departureTime(dep), arrivalTime(arr) {}

TimeInfo::~TimeInfo() {}

Time TimeInfo::getDepartureTime() const { return departureTime; }
Time TimeInfo::getArrivalTime() const { return arrivalTime; }