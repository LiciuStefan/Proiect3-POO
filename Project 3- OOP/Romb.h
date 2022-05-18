#pragma once
#include "Patrat.h"
//Rombul are doua laturi paralele cu Ox:

class Romb : public Patrat {
public:
	Romb();
	Romb(float, float, float, float, float, float);
	Romb(const Romb&);
	~Romb();
	float calcul_arie();
	float volum();

	void afisare(std::ostream&);

	void set_colt_opus(Punct);
	Punct get_colt_opus();

	Romb& operator=(const Forma_Geometrica&);
	Romb& operator=(const Patrat&);
	const Romb& operator=(const Romb&);

	friend std::istream& operator>>(std::istream&, Romb&);
	friend std::ostream& operator<<(std::ostream&, Romb&);

private:
	Punct* punct_colt_opus;
};
