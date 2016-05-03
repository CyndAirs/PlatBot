#include "AnimationHandler.hpp"

//Ustawia wartoœæ klatki na value na czas time
void AnimationHandler::setTemp(AnimationState value, double duration)
{
	tempValue = value;

	timer = duration;
}

//Ustawia klatkê domyœln¹
void AnimationHandler::setDefault(AnimationState value)
{
	defValue = value;
}

//Update'uje animacjê, zwraca aktualn¹ klatkê
AnimationState AnimationHandler::checkFrame(float dt)
{
	timer -= dt;

	if (timer > 0)
	{
		return tempValue;
	}
	return defValue;
}

//Konstruktor domyœlny klasy
AnimationHandler::AnimationHandler()
{
	timer = 0;

	defValue = tempValue = Stand;
}