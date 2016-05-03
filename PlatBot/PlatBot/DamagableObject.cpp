#include "DamagableObject.hpp"

//Zmniejsza iloœæ punktów ¿ycia obiektu o x.
bool DamagableObject::damage(int x)
{
	if (health <= 0) return false;
	health-=x;
	return true;


}

//Zwraca iloœæ punktów ¿ycia obiektu.
int DamagableObject::checkHealth()
{
	return health;
}