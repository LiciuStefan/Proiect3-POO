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
