#include "singleton.h"
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

Singleton* Singleton::ptrInstance = nullptr;

void afisare_forme_geometrice(vector<pair<Forma_Geometrica*, string>>Forme)
{
	if (Forme.size() == 0)
		std::cout << "Nu exista elemente in vector\n";
	else
	{
		for (auto i = Forme.begin(); i != Forme.end(); ++i)
			std::cout << i->second << ' ' << *(i->first) << '\n';
	}
}

void sterge_forma_geometrica(vector<pair<Forma_Geometrica*, string>>& Forme)
{
	afisare_forme_geometrice(Forme);
	int poz;
	std::cout << "Introduceti pozitia corespunzatoare obiectului pe care doriti sa il stergeti:\n";
	std::cin >> poz;
	if (poz < Forme.size())
	{
		for (int i = poz; i < Forme.size() - 1; ++i)
			Forme[i] = Forme[i + 1];
		Forme.resize(Forme.size() - 1);
		cout << "Elementul a fost sters\n";
	}
	else
	{
		cout << "Pozitie invalida\n";
	}

}

void calcul_arie_forma_geometrica(vector<pair<Forma_Geometrica*, string>>Forme)
{
	afisare_forme_geometrice(Forme);
	int poz;
	cout << "Introduceti pozitia corespunzatoare obiectului a carui arie se calculeaza:\n";
	cin >> poz;
	if (poz >= Forme.size())
	{
		cout << "Pozitie invalida!\n";

	}
	else
	{
		if (typeid(*(Forme[poz].first)) == typeid(Patrat))
		{
			cout << (*dynamic_cast<Patrat*>(Forme[poz].first)).calcul_arie() << '\n';
		}
		else if (typeid(*(Forme[poz].first)) == typeid(Dreptunghi))
		{
			cout << (*dynamic_cast<Dreptunghi*>(Forme[poz].first)).calcul_arie() << '\n';

		}
		else if (typeid(*(Forme[poz].first)) == typeid(Romb))
		{
			cout << (*dynamic_cast<Romb*>(Forme[poz].first)).calcul_arie() << '\n';

		}
		else if (typeid(*(Forme[poz].first)) == typeid(Triunghi))
		{
			cout << (*dynamic_cast<Triunghi*>(Forme[poz].first)).calcul_arie() << '\n';

		}
		else if (typeid(*(Forme[poz].first)) == typeid(Cerc))
		{
			cout << (*dynamic_cast<Cerc*>(Forme[poz].first)).calcul_arie() << '\n';
		}
	}
}

void calcul_volum_forma_geometrica(vector<pair<Forma_Geometrica*, string>>Forme)
{
	afisare_forme_geometrice(Forme);
	int poz;
	cout << "Introduceti pozitia corespunzatoare obiectului a carui volum se calculeaza:\n";
	cin >> poz;

	if (poz < Forme.size())
	{
		if (Forme[poz].first->get_inaltime() == 0)
			cout << Forme[poz].first->calcul_arie() << '\n';
		else
			cout << Forme[poz].first->volum() << '\n';
	}
	else
	{
		cout << "Pozitie invalida!\n";
	}
}

void lungime_laturi_triunghi(vector<pair<Forma_Geometrica*, string>>Forme)
{
	cout << "Alegeti una din optiuni:\n1. Element deja existent in vector\n2. Element nou\n";
	int choice;
	cin >> choice;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Argument invalid\n";
	}

	else
	{
		switch (choice)
		{
		case 1:
		{  afisare_forme_geometrice(Forme);
		cout << "Introduceti pozitia corespunzatore elementului:\n";
		int poz;
		cin >> poz;
		if (poz < Forme.size())
		{
			if (typeid(*(Forme[poz].first)) == typeid(Triunghi))
			{
				cout << "Lungimea laturii AB este:\n";
				cout << (*dynamic_cast<Triunghi*>(Forme[poz].first)).lungime_AB() << '\n';
				cout << "Lungimea laturii AC este:\n";
				cout << (*dynamic_cast<Triunghi*>(Forme[poz].first)).lungime_AC() << '\n';
				cout << "Lungimea laturii BC este:\n";
				cout << (*dynamic_cast<Triunghi*>(Forme[poz].first)).lungime_BC() << '\n';
			}

			else
			{
				cout << "Elementul selectat nu este triunghi!\n";
			}
		}
		else
		{
			cout << "Pozitie invalida!\n";
		}

		}
		break;
		case 2:
		{
			cout << "Introduceti: abscisa primului punct(float), ordonata primului punct(float), inaltimea(float), abscisa punctului 2(float), ordonata punctului 2(float), abscisa punctului 3(float), ordonata punctului 3(float)\n";
			Triunghi Tr;
			bool Ok = true;
			try
			{
				cin >> Tr;
			}
			catch (invalid_argument arg)
			{
				cout << arg.what() << '\n';
				Ok = false;
			}
			if (Ok)
			{
				cout << "Lungimea laturii AB este:\n";
				cout << Tr.lungime_AB() << '\n';
				cout << "Lungimea laturii AC este:\n";
				cout << Tr.lungime_AC() << '\n';
				cout << "Lungimea laturii BC este:\n";
				cout << Tr.lungime_BC() << '\n';
			}
		}
		break;
		default: cout << "Argument invalid\n";
		}
	}
}

void centru_de_greutate(vector<pair<Forma_Geometrica*, string>>Forme)
{
	cout << "Alegeti una din optiuni:\n1. Element deja existent in vector\n2. Element nou\n";
	int choice;
	cin >> choice;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Argument invalid\n";
	}

	else
	{
		switch (choice)
		{
		case 1:
		{
			afisare_forme_geometrice(Forme);
			cout << "Introduceti pozitia corespunzatore elementului:\n";
			int poz;
			cin >> poz;
			if (poz < Forme.size())
			{
				if (typeid(*(Forme[poz].first)) == typeid(Triunghi))
				{
					cout << "Centrul de greutate al triunghiului are coordonatele:\n";
					Punct Centru_Greutate = (*dynamic_cast<Triunghi*>(Forme[poz].first)).get_centru_greutate();
					cout << Centru_Greutate << '\n';
				}

				else
				{
					cout << "Elementul selectat nu este triunghi!\n";
				}
			}
			else
			{
				cout << "Pozitie invalida!\n";
			}

		}
		break;
		case 2:
		{
			cout << "Introduceti: abscisa primului punct(float), ordonata primului punct(float), inaltimea(float), abscisa punctului 2(float), ordonata punctului 2(float), abscisa punctului 3(float), ordonata punctului 3(float)\n";
			Triunghi Tr;
			bool Ok = true;
			try
			{
				cin >> Tr;
			}
			catch (invalid_argument arg)
			{
				cout << arg.what() << '\n';
				Ok = false;
			}
			if (Ok)
			{
				cout << "Centrul de greutate al triunghiului are coordonatele:\n";
				Punct Centru_Greutate = Tr.get_centru_greutate();
				cout << Centru_Greutate << '\n';
			}
		}
		break;
		default: cout << "Argument invalid\n";
		}
	}
}


void Singleton::start()
{
	int choice;
	vector<pair<Forma_Geometrica*, string>>Forme;
	Forma_Geometrica* B = new Triunghi(0, 1, 10, 2, 2, 3, 1);
	Forme.push_back(make_pair(B, "Triunghi"));
	B = new Cerc(10, 0, 20, 100);
	Forme.push_back(make_pair(B, "Cerc"));
	string continuare;
	PatratRepository Patrate;
	cout << "---------------------------------------------------Meniu-----------------------------------------------\n";


menu:
	cout << "0.Exit\n1.Vezi forme geometrice\n2.Adauga forma geometrica\n3.Sterge forma geometrica\n4.Calcul arie forma geometrica\n5.Calcul volum forma geometrica\n6.Calculeaza lungime laturi triunghi\n7.Centru de greutate triunghi\n8.Actiuni repository\n";

	cout << "Introduceti cifra corespunzatoare actiunii dorite:\n";
	cin >> choice;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Input invalid!\nIntroduceti cifra corespunzatoare actiunii dorite:\n";
		cin >> choice;
	}
	switch (choice)
	{
	case 0:
	{
		cout << "Va mai asteptam!\n";
		exit(0);
	}
	break;
	case 1:
	{
		afisare_forme_geometrice(Forme);
	}
	break;
	case 2:
	{
		int natura;
		cout << "Alegeti natura formei geometrice:\n";
		cout << "1. Patrat\n2. Dreptunghi\n3. Romb\n4. Triunghi\n5. Cerc\n";
		cin >> natura;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input!\n";
			goto menu;
		}

		switch (natura)
		{
			//Patrat
		case 1:
		{   Patrat P;
		cout << "Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea laturii(float)\n";
	label_Patrat:
		try {
			cin >> P;
		}
		catch (invalid_argument arg)
		{
			cout << arg.what() << '\n';
			goto label_Patrat;
		}
		Forma_Geometrica* B = new Patrat(P); //upcast
		Forme.push_back(make_pair(B, "Patrat"));
		}
		break;
		//Dreptunghi
		case 2: {

			Dreptunghi D;
			cout << "Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea primei laturi(float), lungimea celei de-a doua laturi(float)\n";
		label_Dreptunghi:
			try {
				cin >> D;
			}
			catch (invalid_argument arg)
			{
				cout << arg.what() << '\n';
				goto label_Dreptunghi;
			}
			Forma_Geometrica* B = new Dreptunghi(D);
			Forme.push_back(make_pair(B, "Dreptunghi"));
		}
			  break;
			  //Romb
		case 3:
		{
			Romb R;
			cout << "Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea primei laturi(float), abscisa punct opus(float), ordonata punct opus(float)\n";
		label_Romb:
			try
			{
				cin >> R;
			}
			catch (invalid_argument arg)
			{
				cout << arg.what() << '\n';
				goto label_Romb;
			}
			Forma_Geometrica* B = new Romb(R);
			Forme.push_back(make_pair(B, "Romb"));
		}
		break;
		//Triunghi
		case 4:
		{	Triunghi Tr;
		cout << "Introduceti: abscisa primului punct(float), ordonata primului punct(float), inaltimea(float), abscisa punctului 2(float), ordonata punctului 2(float), abscisa punctului 3(float), ordonata punctului 3(float)\n";
	label_Triunghi:
		try
		{
			cin >> Tr;
		}
		catch (invalid_argument arg)
		{
			cout << arg.what() << '\n';
			goto label_Triunghi;
		}
		Forma_Geometrica* B = new Triunghi(Tr);
		Forme.push_back(make_pair(B, "Triunghi"));
		}
		break;
		//Cerc
		case 5:
		{
			Cerc C;
			cout << "Introduceti: abscisa centrului cercului(float), ordonata centrului cercului (float), inaltimea(float), raza cercului\n";
		label_Cerc:
			try
			{
				cin >> C;
			}
			catch (invalid_argument arg)
			{
				cout << arg.what() << '\n';
				goto label_Cerc;
			}
			Forma_Geometrica* B = new Cerc(C);
			Forme.push_back(make_pair(B, "Cerc"));
		}
		break;
		default: cout << "Invalid argument!\n";
		}
	}
	break;
	case 3:
	{
		sterge_forma_geometrica(Forme);
	}
	break;
	case 4:
	{
		calcul_arie_forma_geometrica(Forme);
		break;
	}

	case 5:
	{
		calcul_volum_forma_geometrica(Forme);
	}
	break;
	case 6:
	{
		lungime_laturi_triunghi(Forme);
	}
	break;
	case 7:
	{
		centru_de_greutate(Forme);
	}
	case 8:
	{
		cout << "Introduceti cifra corespunzatoare actiunii dorite:\n";
		cout << "0. Adauga patrat\n1. Delete patrat dupa punct stanga jos\n2. Delete patrat dupa latura\n3. Delete patrat dupa inaltime\n4. Delete patrat dupa arie\n5. Vezi patrate\n";
		int op;
	label_Repo:
		cin >> op;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input!\n";
			goto label_Repo;
		}
	
		switch (op)
		{
		case 0:
		{
			Patrat* Pt;
			int x, y, inaltime, latura;
			cout << "Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea laturii(float)\n";
		label_patrat:
			cin >> x >> y >> inaltime >> latura;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input!\n";
				goto label_patrat;
			}
			Pt = new Patrat(x, y, inaltime, latura);
			Patrate.add(Pt);
			
		}
		break;
		case 1:
		{
			vector<Patrat*> Ptr;
			int x, y;
			cout << "Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float)\n";
		label_patrat_remove:
			cin >> x >> y;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input!\n";
				goto label_patrat_remove;
			}
			try {
				Ptr = Patrate.SearchByPunctStangaJos(x, y);
			}
			catch (std::runtime_error const err)
			{
				cout << err.what() << ' ';
				goto label_cont;
			}
			for (auto patrat = Ptr.begin(); patrat != Ptr.end(); ++patrat)
				Patrate.remove(*patrat);
		}
		break;
		case 2:
		{
			vector<Patrat*> Ptr;
			int latura;
			cout << "Introduceti: latura patratului(float)\n";
		label_patrat_latura:
			cin >> latura;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input!\n";
				goto label_patrat_latura;
			}
			try {
				Ptr = Patrate.SearchByLatura(latura);
			}
			catch (std::runtime_error const err)
			{
				cout << err.what() << ' ';
				goto label_cont;
			}
			for (auto patrat = Ptr.begin(); patrat != Ptr.end(); ++patrat)
				Patrate.remove(*patrat);

		}
		break;
		case 3:
		{
			vector<Patrat*> Ptr;
			int inaltime;
			cout << "Introduceti: inaltimea patratului(float)\n";
		label_patrat_inaltime:
			cin >> inaltime;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input!\n";
				goto label_patrat_inaltime;
			}
			try {
				Ptr = Patrate.SearchByInaltime(inaltime);
			}
			catch (std::runtime_error const err)
			{
				cout << err.what() << ' ';
				goto label_cont;
			}
			for (auto patrat = Ptr.begin(); patrat != Ptr.end(); ++patrat)
				Patrate.remove(*patrat);
		}
		break;
		case 4:
		{
			vector<Patrat*> Ptr;
			int arie;
			cout << "Introduceti: aria patratului(float)\n";
		label_patrat_arie:
			cin >> arie;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Invalid input!\n";
				goto label_patrat_arie;
			}
			try {
				Ptr = Patrate.SearchByArie(arie);
			}
			catch (std::runtime_error const err)
			{
				cout << err.what() << ' ';
				goto label_cont;
			}
			for (auto patrat = Ptr.begin(); patrat != Ptr.end(); ++patrat)
				Patrate.remove(*patrat);
		}
		break;
		case 5:
		{
			Patrate.see();
		}
		break;
		default: cout << "Invalid selection!\n";
		}
	}
	break;
	default: cout << "Invalid selection!\n";
	}
	label_cont:
	cout << "Doriti o alta actiune?\n";
	cin >> continuare;
	transform(continuare.begin(), continuare.end(), continuare.begin(), [](unsigned char c) { return tolower(c); });
	if (continuare == "da")
		goto menu;
	else
	{
		cout << "Va mai asteptam!\n";
		exit(0);
	}


		system("pause");
	}


void Singleton::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

