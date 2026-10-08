#ifndef BUS_H
#define BUS_H

#include "BusBase.h"
#include "TimeInfo.h"

class Bus : public BusBase, public TimeInfo {
public:
    Bus(const std::string& num, const std::string& dest, const std::string& type,
        const Time& dep, const Time& arr);
    virtual ~Bus(); 

    void print(std::ostream& os) const override;
};

#endif