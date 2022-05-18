#pragma once
#include "Forma_Geometrica.h"

class Patrat : public Forma_Geometrica {
public:
	Patrat();
	Patrat(float, float, float, float);
	Patrat(const Patrat&);
	virtual ~Patrat();

	void set_latura(float);
	float get_latura();

	float calcul_arie();
	float volum();

	float diagonala();

	void afisare(std::ostream&);
	Patrat& operator= (const Forma_Geometrica&);
	virtual const Patrat& operator=(const Patrat&);

	friend std::istream& operator>>(std::istream&, Patrat&);
	friend std::ostream& operator<<(std::ostream&, Patrat&);
	friend bool operator == (Patrat&,Patrat&);
protected:
	float latura;
};
