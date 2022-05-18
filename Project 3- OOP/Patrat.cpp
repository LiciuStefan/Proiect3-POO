#include <iostream>
#include "Patrat.h"


using namespace std;

//-----------------------------Patrat------------------------------------------------
bool operator ==(Patrat& P1, Patrat& P2)
{
	return (P1.punct_stanga_jos == P2.punct_stanga_jos && P1.latura == P2.latura && P1.inaltime == P2.inaltime);
}
Patrat::Patrat() :Forma_Geometrica()
{
	this->latura = 0;
}
Patrat::Patrat(float abscisa, float ordonata, float inaltime, float latura) : Forma_Geometrica(abscisa, ordonata, inaltime)
{
	this->latura = latura;
}

Patrat::Patrat(const Patrat& Patrat1) : Forma_Geometrica(Patrat1)
{
	this->latura = Patrat1.latura;
}

Patrat::~Patrat()
{
	this->latura = 0.0;
}

void Patrat::set_latura(float lungime_latura)
{
	this->latura = lungime_latura;
}

float Patrat::get_latura()
{
	return this->latura;
}

float Patrat::calcul_arie()
{
	return this->latura * this->latura;
}

float Patrat::volum()
{
	return this->calcul_arie() * this->inaltime;
}

float Patrat::diagonala()
{
	return this->latura * sqrt(2);
}

void  Patrat::afisare(ostream& stream)
{
	Forma_Geometrica::afisare(stream);
	cout << ' ' << this->latura;
}

Patrat& Patrat::operator =(const Forma_Geometrica& Forma)
{
	Forma_Geometrica::operator=(Forma);
	try {
		const Patrat& P = dynamic_cast<const Patrat&>(Forma);
		this->latura = P.latura;
	}
	catch (const bad_cast& e)
	{
		cout << e.what() << '\n';
		this->latura = 0.0;
	}
	return *this;
}

const Patrat& Patrat::operator=(const Patrat& P)
{
	Forma_Geometrica::operator=(P);
	this->latura = P.latura;
	return *this;
}

istream& operator>>(istream& stream, Patrat& P)
{
	Forma_Geometrica* F = &P;
	cin >> *F;
	stream >> P.latura;
	if (!stream.good() || P.latura <= 0)
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		P.inaltime = 0.0;
		P.punct_stanga_jos = new Punct(0.0, 0.0);
		throw invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float, float, float, iar latura trebuie sa fie pozitiva\n");
	}

	return stream;
}

ostream& operator<<(ostream& stream, Patrat& P)
{
	P.afisare(stream);
	return stream;
}