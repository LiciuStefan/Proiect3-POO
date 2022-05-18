#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>
#include "Punct.h"
#include "Forma_Geometrica.h"
#include "Patrat.h"
#include "Dreptunghi.h"
#include "Romb.h"
#include "Triunghi.h"
#include "Cerc.h"
#include "PatratRepository.h"
#include "repo.hpp"

using namespace std;

class Singleton
{
public:
	static void start();
	static void Terminate();
private:
	static Singleton* ptrInstance;
	static Singleton& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new Singleton();
		}
		return *ptrInstance;
	}
	Singleton();
	~Singleton() {};
};