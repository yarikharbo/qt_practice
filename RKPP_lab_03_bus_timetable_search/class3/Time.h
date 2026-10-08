#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

struct Time {
    int hours, minutes;
    Time(int h = 0, int m = 0);
    int toMinutes() const;
    bool operator<=(const Time& other) const;
    friend std::ostream& operator<<(std::ostream&, const Time&);
    friend std::istream& operator>>(std::istream&, Time&);
};

#endif