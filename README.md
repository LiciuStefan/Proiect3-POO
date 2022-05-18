# Proiect3-POO
Proiect realizat în cadrul cursului de Programare Orientată pe Obiecte, anul I, semestrul II, Facultatea de Matematică și Informatică, Universitatea din București

Proiectul este o extindere a proiectului 2.<br/>
Acesta exemplifica utilizarea de templates si design patterns.<br/>
Primul design pattern implementat este `Repository Pattern`, care imi permite sa creez un Repository de obiecte de tipul clasei `Patrat`. <br/>
```C++
template <class Ent>
class Repo {
public:
	inline void add(Ent* entity);
	inline void remove(Ent* entity);

protected:
	std::vector<Ent*>Ents;
};
```
In implementarea acestei clase am utilizat template pentru a imi permite sa utilizez instante ale unor clase diferite.</br>

Pentru a memora instante ale clasei `Patrat`, am utilizat clasa `PatratRepository` care mosteneste clasa `Repo`:<br/>
```C++
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
```
Al doilea design pattern utilizat este `Singleton`, prin intermediul caruia am construit meniul principal al programului.<br/>
Singleton imi permite sa instantiez un singur obiect de tipul clasei respective. 
```C++
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
```
Astfel, in interiorul main-ului este necesara doar apelarea metodelor din clasa `Singleton`:
```C++
int main()
{
	Singleton::start();
	Singleton::Terminate();
	return 0;
}
```
Exemplu:<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
0<br/>
Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea laturii(float)<br/>
1 1 2 5<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
0<br/>
Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea laturii(float)<br/>
2.2 3.3 0 12<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
0<br/>
Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float), inaltimea(float) si lungimea laturii(float)<br/>
1.22 4.5 9.8 3.33<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
5<br/>
1 1 2 5<br/>
2.2 3.3 0 12<br/>
1.22 4.5 9.8 3.33<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
1<br/>
Introduceti: asbscisa punctului stanga jos(float), ordonata punctului stanga jos(float)<br/>
2.2 3.3<br/>
A fost elimnat un element<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
5<br/>
1 1 2 5<br/>
1.22 4.5 9.8 3.33<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
2<br/>
Introduceti: latura patratului(float)<br/>
3.33<br/>
A fost elimnat un element<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
5<br/>
1 1 2 5<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
4<br/>
Introduceti: aria patratului(float)<br/>
25<br/>
A fost elimnat un element<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
5<br/>
Lista este goala<br/>
Doriti o alta actiune?<br/>
da<br/>
0.Exit<br/>
1.Vezi forme geometrice<br/>
2.Adauga forma geometrica<br/>
3.Sterge forma geometrica<br/>
4.Calcul arie forma geometrica<br/>
5.Calcul volum forma geometrica<br/>
6.Calculeaza lungime laturi triunghi<br/>
7.Centru de greutate triunghi<br/>
8.Actiuni repository<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
8<br/>
Introduceti cifra corespunzatoare actiunii dorite:<br/>
0. Adauga patrat<br/>
1. Delete patrat dupa punct stanga jos<br/>
2. Delete patrat dupa latura<br/>
3. Delete patrat dupa inaltime<br/>
4. Delete patrat dupa arie<br/>
5. Vezi patrate<br/>
3<br/>
Introduceti: inaltimea patratului(float)<br/>
0<br/>
Nu exista patrat cu aceasta inaltime<br/>
 Doriti o alta actiune?v
nu<br/>
Va mai asteptam!<br/>

