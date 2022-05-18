#pragma once
#include <iostream>
#include "Patrat.h"
#include "repo.hpp"

class PatratRepository: public Repo<Patrat>
{
public:
	std::vector<Patrat*> SearchByPunctStangaJos(int, int);
	std::vector<Patrat*>SearchByLatura(int);
	std::vector<Patrat*>SearchByInaltime(int);
	std::vector<Patrat*>SearchByArie(int);
	void see();
	PatratRepository() {}
	~PatratRepository() {}
};
