#include "AnimationHandler.hpp"

//Ustawia warto�� klatki na value na czas time
void AnimationHandler::setTemp(AnimationState value, double duration)
{
	tempValue = value;

	timer = duration;
}

//Ustawia klatk� domy�ln�
void AnimationHandler::setDefault(AnimationState value)
{
	defValue = value;
}

//Update'uje animacj�, zwraca aktualn� klatk�
AnimationState AnimationHandler::checkFrame(float dt)
{
	timer -= dt;

	if (timer > 0)
	{
		return tempValue;
	}
	return defValue;
}

//Konstruktor domy�lny klasy
AnimationHandler::AnimationHandler()
{
	timer = 0;

	defValue = tempValue = Stand;
}