#include <iostream>
#include "Triunghi.h"
using namespace std;
//------------------------------------------Triunghi-------------------------------------------------
Triunghi::Triunghi() : Forma_Geometrica() {
	this->punct_2 = new Punct(0.0, 0.0);
	this->punct_3 = new Punct(0.0, 0.0);
}

Triunghi::Triunghi(float abscisa1, float ordonata1, float inaltime, float abscisa2, float ordonata2, float abscisa3, float ordonata3) : Forma_Geometrica(abscisa1, ordonata1, inaltime) {
	this->punct_2 = new Punct(abscisa2, ordonata2);
	this->punct_3 = new Punct(abscisa3, ordonata3);
}

Triunghi::Triunghi(const Triunghi& Tr) : Forma_Geometrica(Tr) {
	this->punct_2 = new Punct(*Tr.punct_2);
	this->punct_3 = new Punct(*Tr.punct_3);
}

Triunghi::~Triunghi()
{
	delete this->punct_2;
	delete this->punct_3;
}

float Triunghi::calcul_arie()
{ //Punct_stanga_jos, punct_2, punct_3;

	float semiperimetru = (this->lungime_AB() + this->lungime_AC() + this->lungime_BC()) / 2;
	//cout << this->lungime_AB() << ' ' << this->lungime_AC() << ' ' << this->lungime_BC() << '\n';
	//cout << semiperimetru << '\n';
	//cout<<(semiperimetru * (semiperimetru - this->lungime_AB()) * (semiperimetru - this->lungime_AC()) * (semiperimetru - this->lungime_BC()));
	//cout << '\n';

	return sqrt(semiperimetru * (semiperimetru - this->lungime_AB()) * (semiperimetru - this->lungime_AC()) * (semiperimetru - this->lungime_BC()));
}

float Triunghi::volum()
{
	return this->calcul_arie() * this->inaltime;
}

void Triunghi::set_punct2(float abscisa, float ordonata)
{
	this->punct_2->set_x(abscisa);
	this->punct_2->set_y(ordonata);
}

void Triunghi::set_punct3(float abscisa, float ordonata)
{
	this->punct_3->set_x(abscisa);
	this->punct_3->set_y(ordonata);
}

Punct* Triunghi::get_punct2() const
{
	return this->punct_2;
}

Punct* Triunghi::get_punct3() const
{
	return this->punct_3;
}

void Triunghi::afisare(ostream& stream)
{
	Forma_Geometrica::afisare(stream);
	std::cout << ' ' << *(this->punct_2) << ' ' << *(this->punct_3);
}

float Triunghi::lungime_AB()
{
	float AB = sqrt((this->punct_2->get_x() - this->punct_stanga_jos->get_x()) * (this->punct_2->get_x() - this->punct_stanga_jos->get_x()) + (this->punct_2->get_y() - this->punct_stanga_jos->get_y()) * (this->punct_2->get_y() - this->punct_stanga_jos->get_y()));
	return AB;
}

float Triunghi::lungime_AC()
{
	float AC = sqrt((this->punct_3->get_x() - this->punct_stanga_jos->get_x()) * (this->punct_3->get_x() - this->punct_stanga_jos->get_x()) + (this->punct_3->get_y() - this->punct_stanga_jos->get_y()) * (this->punct_3->get_y() - this->punct_stanga_jos->get_y()));
	return AC;
}

float Triunghi::lungime_BC()
{
	float BC = sqrt((this->punct_2->get_x() - this->punct_3->get_x()) * (this->punct_2->get_x() - this->punct_3->get_x()) + (this->punct_2->get_y() - this->punct_3->get_y()) * (this->punct_2->get_y() - this->punct_3->get_y()));
	return BC;
}

float Triunghi::mediana_din_A()
{
	return (2 * (this->lungime_AC() * this->lungime_AC() + (this->lungime_AB() * this->lungime_AB())) - (this->lungime_BC() * this->lungime_BC())) / 4;
}

float Triunghi::mediana_din_B()
{
	return (2 * (this->lungime_BC() * this->lungime_BC() + (this->lungime_AB() * this->lungime_AB())) - (this->lungime_AC() * this->lungime_AC())) / 4;
}

float Triunghi::mediana_din_C()
{
	return (2 * (this->lungime_AC() * this->lungime_AC() + (this->lungime_BC() * this->lungime_BC())) - (this->lungime_AB() * this->lungime_AB())) / 4;
}

Punct Triunghi::get_centru_greutate()
{
	float xG = (this->punct_stanga_jos->get_x() + this->punct_2->get_x() + this->punct_3->get_x()) / 3;
	float yG = (this->punct_stanga_jos->get_y() + this->punct_2->get_y() + this->punct_3->get_y()) / 3;

	Punct Centru_De_Greutate(xG, yG);
	return Centru_De_Greutate;
}

Triunghi& Triunghi::operator =(const Forma_Geometrica& Forma)
{
	Forma_Geometrica::operator=(Forma);
	try {
		const Triunghi& Tr = dynamic_cast<const Triunghi&>(Forma);
		*(this->punct_2) = *(Tr.punct_2);
		*(this->punct_3) = *(Tr.punct_3);
	}
	catch (const bad_cast& e)
	{
		std::cout << e.what();
		this->punct_2->set_x(0.0);
		this->punct_2->set_y(0.0);

		this->punct_3->set_x(0.0);
		this->punct_3->set_y(0.0);
	}
	return *this;
}

const Triunghi& Triunghi::operator=(const Triunghi& Tr)
{
	Forma_Geometrica::operator=(Tr);
	*(this->punct_2) = *(Tr.punct_2);
	*(this->punct_3) = *(Tr.punct_3);

	return *this;
}

std::istream& operator>>(std::istream& stream, Triunghi& Tr)
{
	float x, y;
	Forma_Geometrica* Forma = &Tr; //upcast
	cin >> *Forma;
	stream >> x >> y;
	if (!stream.good())
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		Tr.inaltime = 0.0;
		Tr.punct_stanga_jos = new Punct(0.0, 0.0);
		throw std::invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float, float, float.\n");
	}
	else {
		Tr.punct_2 = new Punct(x, y);
	}

	stream >> x >> y;
	if (!stream.good())
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		Tr.inaltime = 0.0;
		Tr.punct_stanga_jos = new Punct(0.0, 0.0);
		Tr.punct_2 = new Punct(0.0, 0.0);
		throw std::invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float, float, float.\n");
	}
	else {
		Tr.punct_3 = new Punct(x, y);
	}

	return stream;
}

std::ostream& operator<<(std::ostream& stream, Triunghi& Tr)
{
	Tr.afisare(stream);
	return stream;
}