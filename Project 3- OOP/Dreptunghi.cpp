#include <iostream>
#include "Dreptunghi.h"

using namespace std;
//--------------Dreptunghi-----------------------------

Dreptunghi::Dreptunghi() : Patrat()
{
	this->latura2 = 0.0;
}

Dreptunghi::Dreptunghi(float abscisa, float ordonata, float inaltime, float latura1, float latura2) : Patrat(abscisa, ordonata, inaltime, latura)
{
	this->latura2 = latura2;
}

Dreptunghi::Dreptunghi(const Dreptunghi& Drept) : Patrat(Drept)
{
	this->latura2 = Drept.latura2;
}

Dreptunghi::~Dreptunghi()
{
	this->latura2 = 0.0;
}

float Dreptunghi::calcul_arie()
{
	return this->latura * this->latura2;
}

float Dreptunghi::volum()
{
	return this->calcul_arie() * this->inaltime;
}

void Dreptunghi::afisare(ostream& stream)
{
	Patrat::afisare(stream);
	cout << ' ' << this->latura2;
}

void Dreptunghi::set_latura2(float lungime_latura)
{
	this->latura2 = lungime_latura;
}

float Dreptunghi::get_latura2()
{
	return this->latura2;
}

Dreptunghi& Dreptunghi::operator =(const Forma_Geometrica& Forma)
{
	Forma_Geometrica::operator=(Forma);
	try {
		const Dreptunghi& D = dynamic_cast<const Dreptunghi&>(Forma);
		this->latura2 = D.latura2;
	}
	catch (const bad_cast& e)
	{
		cout << e.what() << '\n';
		this->latura2 = 0.0;
	}
	return *this;
}

Dreptunghi& Dreptunghi::operator =(const Patrat& Patrat1)
{
	Patrat::operator=(Patrat1);
	try {
		const Dreptunghi& D = dynamic_cast<const Dreptunghi&>(Patrat1);
		this->latura2 = D.latura2;
	}
	catch (const bad_cast& e)
	{
		cout << e.what() << '\n';
		this->latura2 = 0.0;
	}
	return *this;
}

const Dreptunghi& Dreptunghi::operator=(const Dreptunghi& D)
{
	Patrat::operator=(D);
	this->latura2 = D.latura2;
	return *this;
}

istream& operator>>(istream& stream, Dreptunghi& D)
{
	Patrat* P = &D;
	cin >> *P;
	stream >> D.latura2;
	if (!stream.good() || D.latura2 <= 0)
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		D.inaltime = 0.0;
		D.punct_stanga_jos = new Punct(0.0, 0.0);
		D.latura = 0.0;
		throw invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float, float, float si laturile sunt strict pozitive\n");

	}

	return stream;
}

ostream& operator<<(ostream& stream, Dreptunghi& D)
{
	D.afisare(stream);
	return stream;
}