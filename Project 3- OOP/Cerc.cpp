#include <iostream>

#include "Cerc.h"
using namespace std;
///--------------------------------Cerc-------------------------------------------------------
float Cerc::pi = 3.14;

Cerc::Cerc() : Forma_Geometrica(), raza(0) {}

Cerc::Cerc(float abscisa, float ordonata, float inaltime, float raza) : Forma_Geometrica(abscisa, ordonata, inaltime)
{
	this->raza = raza;
}

Cerc::Cerc(const Cerc& Cerc1) : Forma_Geometrica(Cerc1)
{
	this->raza = Cerc1.raza;
}

float Cerc::calcul_arie()
{
	return this->pi * this->raza * this->raza;
}

float Cerc::volum()
{
	return this->calcul_arie() * this->inaltime;
}

void Cerc::set_raza(float raza)
{
	this->raza = raza;
}

float Cerc::get_raza()
{
	return this->raza;
}

float Cerc::get_pi()
{
	return pi;
}

void Cerc::afisare(ostream& stream)
{
	Forma_Geometrica::afisare(stream);
	cout << ' ' << this->raza;
}

Cerc& Cerc::operator =(const Forma_Geometrica& Forma)
{
	Forma_Geometrica::operator=(Forma);
	try {
		const Cerc& C = dynamic_cast<const Cerc&>(Forma);
		this->raza = C.raza;
	}
	catch (const bad_cast& e)
	{
		cout << e.what();
		this->raza = 0.0;
	}
	return *this;
}

const Cerc& Cerc::operator=(const Cerc& C)
{
	Forma_Geometrica::operator=(C);
	this->raza = C.raza;
	return *this;
}

istream& operator>>(istream& stream, Cerc& C)
{
	Forma_Geometrica* Forma = &C; //upcast
	cin >> *Forma;
	stream >> C.raza;
	if (!stream.good() || C.raza <= 0)
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		C.inaltime = 0.0;
		C.punct_stanga_jos = new Punct(0.0, 0.0);
		throw invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float, float, float, iar raza este strict pozitiva\n");
	}

	return stream;
}

ostream& operator<<(ostream& stream, Cerc& C)
{
	C.afisare(stream);
	return stream;
}
