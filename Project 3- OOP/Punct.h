#pragma once
#include <vector>
#include <memory>

class Punct {
public:
	Punct();
	Punct(float, float);
	Punct(const Punct&);
	virtual ~Punct();

	void set_x(float);
	void set_y(float);
	float get_x();
	float get_y();
	Punct operator =(const Punct&);
	friend bool operator == (Punct&, Punct&);
	friend bool operator != (Punct&, Punct&);
	friend std::istream& operator>>(std::istream&, Punct&);
	friend std::ostream& operator<<(std::ostream&, Punct&);
private:
	float x, y;
};



