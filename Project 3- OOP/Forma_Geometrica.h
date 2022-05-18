#pragma once
#include "Punct.h"

class Forma_Geometrica {
public:
	Forma_Geometrica();
	Forma_Geometrica(float, float, float);
	Forma_Geometrica(const Forma_Geometrica&);
	virtual ~Forma_Geometrica();

	virtual void set_punct_stanga_jos(float, float);
	virtual void set_inaltime(float);

	virtual Punct* get_punct_stanga_jos() const;
	virtual float get_inaltime();

	virtual float calcul_arie() = 0;
	virtual float volum() = 0;

	///Functie pentru afisare:
	virtual void afisare(std::ostream&);

	static int get_counter();

	virtual Forma_Geometrica& operator=(const Forma_Geometrica&);
	friend bool operator == (Forma_Geometrica&, Forma_Geometrica&);
	friend bool operator != (Forma_Geometrica&, Forma_Geometrica&);
	friend std::istream& operator>>(std::istream&, Forma_Geometrica&);
	friend std::ostream& operator<<(std::ostream&, Forma_Geometrica&);

protected:
	Punct* punct_stanga_jos;
	float inaltime;
	static int counter_Forme_Geometrice;
};
