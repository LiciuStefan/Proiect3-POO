#include <iostream>
#include "Romb.h"

using namespace std;
//---------------------------------------Romb---------------------------------------------------------

Romb::Romb() : Patrat()
{
	this->punct_colt_opus = new Punct(0.0, 0.0);
}

Romb::Romb(float abscisa, float ordonata, float inaltime, float latura1, float abscisa2, float ordonata2) : Patrat(abscisa, ordonata, inaltime, latura1)
{
	this->punct_colt_opus = new Punct(abscisa2, ordonata2);
}

Romb::Romb(const Romb& R) : Patrat(R)
{
	this->punct_colt_opus = new Punct(*R.punct_colt_opus); ///Mut in pointer valoarea celuilalt pointer
}

Romb::~Romb()
{
	delete this->punct_colt_opus;
}

float Romb::calcul_arie()
{
	float x_dreapta_jos, y_dreapta_jos, x_stanga_sus, y_stanga_sus;
	x_dreapta_jos = this->punct_stanga_jos->get_x() + this->latura;
	y_dreapta_jos = this->punct_stanga_jos->get_y();

	x_stanga_sus = this->punct_colt_opus->get_x() - this->latura;
	y_stanga_sus = this->punct_colt_opus->get_y();
	//cout << "x dreapta jos este: " << x_dreapta_jos << "\ny dreapta jos este: " << y_dreapta_jos << "\nx stanga sus este: " << x_stanga_sus << "\ny stanga sus este: " << y_stanga_sus << '\n';
	float diagonala1 = sqrt((this->punct_colt_opus->get_x() - this->punct_stanga_jos->get_x()) * (this->punct_colt_opus->get_x() - this->punct_stanga_jos->get_x()) + (this->punct_colt_opus->get_y() - this->punct_stanga_jos->get_y()) * (this->punct_colt_opus->get_y() - this->punct_stanga_jos->get_y()));
	float diagonala2 = sqrt((x_dreapta_jos - x_stanga_sus) * (x_dreapta_jos - x_stanga_sus) + (y_dreapta_jos - y_stanga_sus) * (y_dreapta_jos - y_stanga_sus));
	//cout << "Diagonala 1 este: " << diagonala1 << "\nDiagonala2 este: " << diagonala2<<'\n';
	return (diagonala1 * diagonala2) / 2;
}

float Romb::volum()
{
	return this->calcul_arie() * this->inaltime;
}

void Romb::afisare(ostream& stream)
{
	Patrat::afisare(stream);
	cout << ' ' << *(this->punct_colt_opus);
}

void Romb::set_colt_opus(Punct P)
{
	*(this->punct_colt_opus) = P;
}

Punct Romb::get_colt_opus()
{
	return *(this->punct_colt_opus);
}

Romb& Romb::operator =(const Forma_Geometrica& Forma)
{
	Forma_Geometrica::operator=(Forma);
	try {
		const Romb& R = dynamic_cast<const Romb&>(Forma);
		this->punct_colt_opus = new Punct(*R.punct_colt_opus);
	}
	catch (const bad_cast& e)
	{
		cout << e.what();
		this->punct_colt_opus = new Punct(0.0, 0.0);
	}
	return *this;
}

Romb& Romb::operator =(const Patrat& P)
{
	Patrat::operator=(P);
	try {
		const Romb& R = dynamic_cast<const Romb&>(P);
		*(this->punct_colt_opus) = *(R.punct_colt_opus);
	}
	catch (const bad_cast& e)
	{
		cout << e.what() << '\n';
		this->punct_colt_opus = new Punct(0.0, 0.0);
	}
	return *this;
}

const Romb& Romb::operator=(const Romb& R)
{
	Patrat::operator=(R);
	*(this->punct_colt_opus) = *(R.punct_colt_opus);
	return *this;
}

istream& operator>>(istream& stream, Romb& R)
{
	float x, y;
	Patrat* P = &R;
	cin >> *P;
	stream >> x >> y;
	if (!stream.good())
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		R.inaltime = 0.0;
		R.punct_stanga_jos = new Punct(0.0, 0.0);
		R.latura = 0.0;
		throw invalid_argument("Romb:Argument invalid! Datele trebuie sa fie de tipul: float, float, float, float.\n");

	}
	else
	{
		R.punct_colt_opus = new Punct(x, y);
	}
	return stream;
}

ostream& operator<<(ostream& stream, Romb& R)
{
	R.afisare(stream);
	return stream;
}
