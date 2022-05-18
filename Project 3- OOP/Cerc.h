#pragma once
#include "Forma_Geometrica.h"

//In cazul cercului, punct_stanga_jos este considerat centrul cercului
class Cerc : public Forma_Geometrica
{
public:
	Cerc();
	Cerc(float, float, float, float);
	Cerc(const Cerc&);
	~Cerc() {}
	float calcul_arie();
	float volum();

	void set_raza(float);
	float get_raza();
	static float get_pi();

	void afisare(std::ostream&);

	Cerc& operator=(const Forma_Geometrica&);
	const Cerc& operator=(const Cerc&);

	friend std::istream& operator>>(std::istream&, Cerc&);
	friend std::ostream& operator<<(std::ostream&, Cerc&);

protected:
	float raza;
	static float pi;
};