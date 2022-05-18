#pragma once

#include <iostream>
#include <vector>

template <class Ent>
class Repo {
public:
	inline void add(Ent* entity);
	inline void remove(Ent* entity);

protected:
	std::vector<Ent*>Ents;
};

template <class Ent>
inline void Repo<Ent>::add(Ent* entity)
{
	this->Ents.push_back(entity);
}

template <class Ent>
inline void Repo<Ent> ::remove(Ent* entity)
{   
	int nr_elem = 0;
	for (int i = 0; i < Ents.size(); ++i)
	{
		//std::cout << "aici\n";
		//std::cout << *Ents[i] << '\n'<<*entity;
		if ((*Ents[i]) == *entity)
		{
			Ents[i] = Ents[Ents.size() - 1];
			//std::cout << "aici\n";
			Ents.pop_back();
			nr_elem++;
			//Ents.resize(Ents.size() - 1);
		}
	}
	if (nr_elem > 1)
		std::cout << "Au fost eliminate " << nr_elem << " elemente\n";
	else if (nr_elem == 1)
		std::cout << "A fost elimnat un element\n";
}