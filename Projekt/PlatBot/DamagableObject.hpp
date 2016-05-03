#ifndef DAMAGABLE_OBJECT
#define DAMAGABLE_OBJECT


class DamagableObject
{
public:

	//Zmniejsza ilo�� punkt�w �ycia obiektu o x.
	bool damage(int x);

	//Zwraca ilo�� punkt�w �ycia obiektu.
	int checkHealth();

protected:

	//Aktualne punty �ycia obiektu.
	int health;
};













#endif