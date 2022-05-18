#include "PatratRepository.h"

std::vector<Patrat*> PatratRepository::SearchByLatura(float latura)
{
	std::vector<Patrat*>P;
	for (int i = 0; i < Ents.size(); ++i)
	{
		try {
			if (Ents[i]->get_latura() == latura)
				P.push_back(Ents[i]);
		}
		catch(std::runtime_error)
		{

		}
	}
	if (P.size() == 0)
	{
		throw std::runtime_error("Nu exista patrat cu aceasta latura\n");
	}
	else return P;
}

std::vector<Patrat*> PatratRepository::SearchByPunctStangaJos(float x, float y)
{
	//Punct* Point = new Punct(x, y);
	std::vector<Patrat*>P;
	for (int i = 0; i < Ents.size(); ++i)
	{
		try {
			if (Ents[i]->get_punct_stanga_jos()->get_x() == x && Ents[i]->get_punct_stanga_jos()->get_y() == y)
				P.push_back(Ents[i]);
		}
		catch (std::runtime_error)
		{

		}
	}
	if (P.size() == 0)
	{
		throw std::runtime_error("Nu exista patrat cu acest punct\n");
	}
	else return P;
}

std::vector<Patrat*> PatratRepository::SearchByInaltime(float inaltime)
{
	std::vector<Patrat*>P;
	for (int i = 0; i < Ents.size(); ++i)
	{
		try {
			if (Ents[i]->get_inaltime() == inaltime)
				P.push_back(Ents[i]);
		}
		catch (std::runtime_error)
		{

		}
	}
	if (P.size() == 0)
	{
		throw std::runtime_error("Nu exista patrat cu aceasta inaltime\n");
	}
	else return P;
}

std::vector<Patrat*> PatratRepository::SearchByArie(float arie)
{
	std::vector<Patrat*>P;
	for (int i = 0; i < Ents.size(); ++i)
	{
		try {
			if (Ents[i]->calcul_arie() == arie)
				P.push_back(Ents[i]);
		}
		catch (std::runtime_error)
		{

		}
	}
	if (P.size() == 0)
	{
		throw std::runtime_error("Nu exista patrat cu aceasta arie\n");
	}
	else return P;
}

void PatratRepository::see()
{
	if (Ents.size() == 0) {
		std::cout << "Lista este goala\n";
		return;
	}
	for (int i = 0; i < Ents.size(); ++i)
	{
		std::cout << *Ents[i] << '\n';
	}
}
