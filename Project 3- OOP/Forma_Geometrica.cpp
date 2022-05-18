#include <iostream>
#include "Forma_Geometrica.h"
#include "Punct.h"

using namespace std;
//-------------------------------Forma Geometrica-------------------------------------------------

int Forma_Geometrica::counter_Forme_Geometrice = 0;

Forma_Geometrica::Forma_Geometrica(float abscisa, float ordonata, float h)
{
	this->punct_stanga_jos = new Punct(abscisa, ordonata);
	this->inaltime = h;
	counter_Forme_Geometrice++;
}

Forma_Geometrica::Forma_Geometrica()
{
	this->punct_stanga_jos = new Punct(0.0, 0.0);
	this->inaltime = 0;
	counter_Forme_Geometrice++;
}

Forma_Geometrica::Forma_Geometrica(const Forma_Geometrica& Forma)
{
	this->punct_stanga_jos = new Punct(Forma.punct_stanga_jos->get_x(), Forma.punct_stanga_jos->get_y());
	this->inaltime = Forma.inaltime;
}

Forma_Geometrica::~Forma_Geometrica()
{
	//cout << '\n' << *(this->punct_stanga_jos) << '\n';
	delete this->punct_stanga_jos;
}

void Forma_Geometrica::set_punct_stanga_jos(float abscisa, float ordonata)
{
	this->punct_stanga_jos->set_x(abscisa);
	this->punct_stanga_jos->set_y(ordonata);
}
void Forma_Geometrica::set_inaltime(float h)
{
	this->inaltime = h;
}

Punct* Forma_Geometrica::get_punct_stanga_jos() const
{
	return this->punct_stanga_jos;
}

float Forma_Geometrica::get_inaltime()
{
	return this->inaltime;
}

void Forma_Geometrica::afisare(ostream& stream)
{
	stream << *(this->punct_stanga_jos) << ' ' << this->inaltime;
}

int Forma_Geometrica::get_counter()
{
	return counter_Forme_Geometrice;
}

Forma_Geometrica& Forma_Geometrica::operator=(const Forma_Geometrica& Forma)
{
	if (this != &Forma)
	{
		*(this->punct_stanga_jos) = *(Forma.punct_stanga_jos);
		this->inaltime = Forma.inaltime;
	}
	return *this;
}


bool operator == (Forma_Geometrica& Forma1, Forma_Geometrica& Forma2)
{
	return (Forma1.punct_stanga_jos == Forma2.punct_stanga_jos && Forma1.inaltime == Forma2.inaltime);
}

bool operator != (Forma_Geometrica& Forma1, Forma_Geometrica& Forma2)
{
	return (Forma1.punct_stanga_jos != Forma2.punct_stanga_jos || Forma1.inaltime != Forma2.inaltime);
}

istream& operator>>(istream& stream, Forma_Geometrica& Forma)
{
	stream >> *(Forma.punct_stanga_jos) >> Forma.inaltime;
	if (!stream.good() || Forma.inaltime < 0)
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		Forma.punct_stanga_jos = new Punct(0, 0);
		throw invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float, float.\n");
	}
	return stream;
}

//Operator << ce apeleaza functia virtuala de afisare.
ostream& operator<<(ostream& stream, Forma_Geometrica& Forma)
{
	Forma.afisare(stream);
	return stream;
}