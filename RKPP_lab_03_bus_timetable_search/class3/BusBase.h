#ifndef BUSBASE_H
#define BUSBASE_H

#include <string>
#include <vector>
#include <iostream>

class BusBase {
protected:
    std::string routeNumber;
    std::string destination;
    std::string busType;

public:
    BusBase(const std::string& num, const std::string& dest, const std::string& type);
    virtual ~BusBase();

    virtual void print(std::ostream& os) const = 0;

    friend void Run(const std::vector<BusBase*>& buses, const std::string& filename);

    std::string getRouteNumber() const;
    std::string getDestination() const;
    std::string getBusType() const;
};

#endif