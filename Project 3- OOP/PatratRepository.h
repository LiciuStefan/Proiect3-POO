#pragma once
#include <iostream>
#include "Patrat.h"
#include "repo.hpp"

class PatratRepository: public Repo<Patrat>
{
public:
	std::vector<Patrat*> SearchByPunctStangaJos(float, float);
	std::vector<Patrat*>SearchByLatura(float);
	std::vector<Patrat*>SearchByInaltime(float);
	std::vector<Patrat*>SearchByArie(float);
	void see();
	PatratRepository() {}
	~PatratRepository() {}
};
