#pragma once
#include "Forma_Geometrica.h"

//In cazul triunghiului, punct_stanga_jos este considerat primul colt;
class Triunghi : public Forma_Geometrica
{
public:
	Triunghi();
	Triunghi(float, float, float, float, float, float, float);
	Triunghi(const Triunghi&);
	~Triunghi();

	float calcul_arie();
	float volum();

	void set_punct2(float, float);
	void set_punct3(float, float);

	Punct* get_punct2() const;
	Punct* get_punct3() const;

	void afisare(std::ostream&);

	float lungime_AB();
	float lungime_AC();
	float lungime_BC();

	float mediana_din_A();
	float mediana_din_B();
	float mediana_din_C();

	Punct get_centru_greutate();

	Triunghi& operator=(const Forma_Geometrica&);
	const Triunghi& operator=(const Triunghi&);

	friend std::istream& operator>>(std::istream&, Triunghi&);
	friend std::ostream& operator<<(std::ostream&, Triunghi&);

protected:
	Punct* punct_2;
	Punct* punct_3;
};