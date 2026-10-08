#ifndef X_H_
#define X_H_

class X {
public:
	X();
	virtual ~X();

	void set(double m);
	void run();
	void print() const;

private:
	double m_m;
	double m_z1;
	double m_z2;
};

#endif