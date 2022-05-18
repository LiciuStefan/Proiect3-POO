//Singleton in meniu
//repo cu vector de entitati plus alta clasa care are vector de obiecte
#include <iostream>
#include "singleton.h"
#include "repo.hpp"
#include "Patrat.h"
#include "PatratRepository.h"

using namespace std;

int main()
{
	Singleton::start();
	Singleton::Terminate();
	return 0;
}