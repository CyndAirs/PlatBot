#ifndef ANIMATION_HANDLER
#define ANIMATION_HANDLER

enum AnimationState
{
	Stand, Jump, RangedAttack, MeleeAttack
};

class AnimationHandler
{
public:

	//Ustawia warto�� klatki na value na czas time
	void setTemp(AnimationState value, double duration);

	//Ustawia klatk� domy�ln� na warto�� value
	void setDefault(AnimationState value);

	//Update'uje animacj�, zwraca aktualn� klatk�
	AnimationState checkFrame(float dt);

	//Konstruktor domy�lny klasy
	AnimationHandler();

	//Destruktor
	~AnimationHandler(){};


private:

	//Warto�� domy�lna klatki animacji (wraca do niej gdy zako�czy si� tymczasowa animacja)
	AnimationState defValue;

	//Warto�� chwilowa klatki animacji
	AnimationState tempValue;

	//Licznik trwania klatki chwilowej
	float timer;

};


#endif // !ANIMATION_HANDLER
