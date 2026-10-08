#include "Time.h"
#include <stdexcept>

Time::Time(int h, int m) : hours(h), minutes(m) {
    if (h < 0 || h > 23 || m < 0 || m > 59) throw std::out_of_range("Invalid time");
}

int Time::toMinutes() const { return hours * 60 + minutes; }

bool Time::operator<=(const Time& other) const { return toMinutes() <= other.toMinutes(); }

std::ostream& operator<<(std::ostream& os, const Time& t) {
    return os << std::setw(2) << std::setfill('0') << t.hours << ':'
        << std::setw(2) << std::setfill('0') << t.minutes;
}

std::istream& operator>>(std::istream& is, Time& t) {
    char c; is >> t.hours >> c >> t.minutes;
    if (c != ':') is.setstate(std::ios::failbit);
    return is;
}