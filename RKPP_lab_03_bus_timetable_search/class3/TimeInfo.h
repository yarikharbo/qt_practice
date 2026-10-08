#ifndef TIMEINFO_H
#define TIMEINFO_H

#include "Time.h"

class TimeInfo {
protected:
    Time departureTime;
    Time arrivalTime;

public:
    TimeInfo(const Time& dep, const Time& arr);
    virtual ~TimeInfo();

    Time getDepartureTime() const;
    Time getArrivalTime() const;
};

#endif