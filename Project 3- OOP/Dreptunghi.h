#pragma once
#include "Patrat.h"

class Dreptunghi : public Patrat {
public:
	Dreptunghi();
	Dreptunghi(float, float, float, float, float);
	Dreptunghi(const Dreptunghi&);
	~Dreptunghi();
	float calcul_arie();
	float volum();
	void afisare(std::ostream&);

	void set_latura2(float);
	float get_latura2();

	Dreptunghi& operator=(const Forma_Geometrica&);
	Dreptunghi& operator= (const Patrat&);
	const Dreptunghi& operator=(const Dreptunghi&);

	friend std::istream& operator>>(std::istream&, Dreptunghi&);
	friend std::ostream& operator<<(std::ostream&, Dreptunghi&);

private:
	float latura2;
};