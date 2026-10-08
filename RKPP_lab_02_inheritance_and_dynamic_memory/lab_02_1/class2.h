#ifndef CLASS2_H
#define CLASS2_H

#include <cstdint>

class X {
protected:
    int32_t x1, x2;
public:
    X();
    X(int32_t other_x1, int32_t other_x2);
    virtual ~X();
    virtual void show() const;
    virtual void set();
};

class Y : public X {
private:
    int32_t y;
public:
    Y();
    Y(int32_t other_x1, int32_t other_x2, int32_t other_y);
    ~Y() override;
    void show() const override;
    void set() override;
    int32_t Run();
};

#endif