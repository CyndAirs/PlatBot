#ifndef ANIMATION_HANDLER
#define ANIMATION_HANDLER

enum AnimationState
{
	Stand, Jump, RangedAttack, MeleeAttack
};

class AnimationHandler
{
public:

	//Ustawia wartoœæ klatki na value na czas time
	void setTemp(AnimationState value, double duration);

	//Ustawia klatkê domyœln¹ na wartoœæ value
	void setDefault(AnimationState value);

	//Update'uje animacjê, zwraca aktualn¹ klatkê
	AnimationState checkFrame(float dt);

	//Konstruktor domyœlny klasy
	AnimationHandler();

	//Destruktor
	~AnimationHandler(){};


private:

	//Wartoœæ domyœlna klatki animacji (wraca do niej gdy zakoñczy siê tymczasowa animacja)
	AnimationState defValue;

	//Wartoœæ chwilowa klatki animacji
	AnimationState tempValue;

	//Licznik trwania klatki chwilowej
	float timer;

};


#endif // !ANIMATION_HANDLER
