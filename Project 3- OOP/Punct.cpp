#include <iostream>
#include "Punct.h"

using namespace std;

Punct::Punct()
{
	this->x = 0.0;
	this->y = 0.0;
}

Punct::Punct(float abscisa, float ordonata)
{
	this->x = abscisa;
	this->y = ordonata;
}

Punct::Punct(const Punct& Point)
{
	this->x = Point.x;
	this->y = Point.y;
}

Punct::~Punct()
{
	this->x = 0.0, this->y = 0.0; //Plasez punctul in origine;
}

void Punct::set_x(float abscisa)
{
	this->x = abscisa;
}

void Punct::set_y(float ordonata)
{
	this->y = ordonata;
}

float Punct::get_x()
{
	return this->x;
}

float Punct::get_y()
{
	return this->y;
}
Punct Punct::operator=(const Punct& Punct)
{
	if (this != &Punct)
	{
		this->x = Punct.x;
		this->y = Punct.y;
	}
	return *this;
}

bool operator ==(Punct& Punct1, Punct& Punct2)
{
	return (Punct1.x == Punct2.x && Punct1.y == Punct2.y);
}

bool operator !=(Punct& Punct1, Punct& Punct2)
{
	return (Punct1.x != Punct2.x || Punct1.y != Punct2.y);
}

istream& operator>>(istream& stream, Punct& Point)
{
	stream >> Point.x >> Point.y;
	if (!stream.good())
	{
		stream.clear();
		stream.ignore(INT_MAX, '\n');
		Point.x = 0.0;
		throw invalid_argument("Argument invalid! Datele trebuie sa fie de tipul: float, float.\n");
	}
	return stream;
}

ostream& operator<<(ostream& stream, Punct& Point)
{
	stream << Point.x << ' ' << Point.y;
	return stream;
}







