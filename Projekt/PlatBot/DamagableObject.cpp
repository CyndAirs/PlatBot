#include "DamagableObject.hpp"

//Zmniejsza ilo�� punkt�w �ycia obiektu o x.
bool DamagableObject::damage(int x)
{
	if (health <= 0) return false;
	health-=x;
	return true;


}

//Zwraca ilo�� punkt�w �ycia obiektu.
int DamagableObject::checkHealth()
{
	return health;
}