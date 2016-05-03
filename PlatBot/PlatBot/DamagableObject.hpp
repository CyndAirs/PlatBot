#ifndef DAMAGABLE_OBJECT
#define DAMAGABLE_OBJECT


class DamagableObject
{
public:

	//Zmniejsza iloœæ punktów ¿ycia obiektu o x.
	bool damage(int x);

	//Zwraca iloœæ punktów ¿ycia obiektu.
	int checkHealth();

protected:

	//Aktualne punty ¿ycia obiektu.
	int health;
};













#endif