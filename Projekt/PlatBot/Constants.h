#pragma once

#include <deque>
#include <vector>

//Szeroko�� pola planszy
static const int TILE_W = 16;

//Wysoko�� pola planszy
static const int TILE_H = 16;

//Szeroko�� planszy
static const int MAP_W = 15;

//Wysoko�� planszy
static const int MAP_H = 10;

//Grawitacja
static const int GRAVITY = 500;

//Domy�lne przy�pieszenie postaci
static const int BASE_ACC = 200;

//Szeroko�� widoku
static const int VIEW_W = 200;

//Wysoko�� widoku
static const int VIEW_H = 150;



//Pocz�tkowe po�o�enie lewej kraw�dzi spritera postaci.
static const int P_START_X = 40;

//Pocz�tkowe po�o�enie g�rnej kraw�dzi spritera postaci.
static const int P_START_Y = 56;

//Wysoko�� spritera postaci.
static const int P_SPRITE_W = 32;

//Szeroko�� spritera postaci.
static const int P_SPRITE_H = 32;

//Pocz�tkowe HP postaci.
static const int P_HEALTH = 10;

//Pr�dko�� poruszania si� postaci
static const int P_SPEED = 2;

//R�nica mi�dzy hitboxem postaci a lewym brzegiem spritera.
static const int P_HB_DIFF_W = 11;

//R�nica mi�dzy hitboxem postaci a lewym brzegiem spritera.
static const int P_HB_DIFF_H = 7;

//Wysoko�� hitboxa postaci.
static const int P_HB_SIZE_W = 10;

//Szeroko�� hitboxa postaci.
static const int P_HB_SIZE_H = 19;

//Pozycja atak�w wzgl�dem po�o�enia postaci w poziomie.
static const int P_A_POS_X[] = { 20, 20 };

//Pozycja atak�w wzgl�dem po�o�enia postaci w pionie.
static const int P_A_POS_Y[] = { 10, 10 };

//Cooldown ataku postaci.
static const float P_ATT_CD = 0.5f;

//Pr�dko�� pocisk�w postaci
static const int P_PROJECTILE_SPEED = 100;

//Typy atak�w u�ywane przez posta�
static const int P_A_TYPE[] = { 0, 1 };

//Wysoko�� spritera przeciwnika
static const int E_SPRITE_W = 32;

//Szeroko�� spritera przeciwnika
static const int E_SPRITE_H = 32;

//Pocz�tkowe HP przeciwnik�w
static const int E_HEALTH[] = { 1, 2 };

//Pr�dko�� poruszania si� przeciwnik�w
static const int E_SPEED[] = { 5, 5 };

//R�nice mi�dzy hitboxami przeciwnik�w a lewymi brzegami ich spriter�w.
static const int E_HB_DIFF_W[] = { 9, 11 };

//R�nice mi�dzy hitboxami przeciwnik�w a g�rnymi brzegami ich spriter�w.
static const int E_HB_DIFF_H[] = { 4, 7 };

//Wysoko�ci hitbox�w przeciwnik�w.
static const int E_HB_SIZE_W[] = { 18, 10 };

//Szeroko�ci hitbox�w przeciwnik�w.
static const int E_HB_SIZE_H[] = { 23, 21 };

//Odporno�ci przeciwnik�w na ataki klasy Hit
static const int E_HIT_DMG_TKN[] = { 2, 2 };

//Odporno�ci przeciwnik�w na ataki klasy Projectile
static const int E_PROJECTILE_DMG_TKN[] = { 2, 1 };

//Pozycje atak�w wzgl�dem po�o�enia przeciwnik�w w poziomie.
static const int E_A_POS_X[] = { 20, 23 };

//Pozycje atak�w wzgl�dem po�o�enia przeciwnik�w w pionie.
static const int E_A_POS_Y[] = { 15, 10 };

//Cooldowny atak�w przeciwnik�w
static const float E_ATT_CD[] = { 2.0f, 1.0f };

//Pr�dko�� pocisk�w przeciwnik�w
static const int E_PROJECTILE_SPEED[] = { 50, 0 };

//true je�eli przeciwnik u�ywa ataku typu Hit
static const bool E_MELEE[] = { false, true };

//true je�eli przeciwnik u�ywa ataku typu Projectile
static const bool E_RANGED[] = { true, false };

//Typy atak�w u�ywanych przez przeciwnik�w.
static const int E_A_TYPE[] = { 2, 3 };

//Wysoko�� spritera ataku
static const int A_SPRITE_W = 16;

//Szeroko�� spritera ataku
static const int A_SPRITE_H = 16;

//Wysoko�ci hitbox�w atak�w.
static const int A_HB_SIZE_W[] = { 6, 7, 6, 7 };

//Szeroko�ci hitbox�w atak�w.
static const int A_HB_SIZE_H[] = { 6, 10, 6, 10 };

//R�nice mi�dzy hitboxami atak�w a lewymi brzegami ich spriter�w.
static const int A_HB_DIFF_W[] = { 5, 5, 5, 5 };

//R�nice mi�dzy hitboxami atak�w a g�rnymi brzegami ich spriter�w.
static const int A_HB_DIFF_H[] = { 5, 0, 5, 0 };

//Czasy trwania atak�w.
static const float A_TIMER[] = { 0.1f, 0.1f, 0.1f, 0.15f };

//R�nice mi�dzy hitboxami element�w t�a a lewymi brzegami ich spriter�w.
static const int BG_HB_DIFF_W[] = { 0, 2, 0, 0};

//R�nice mi�dzy hitboxami element�w t�a a g�rnymi brzegami ich spriter�w.
static const int BG_HB_DIFF_H[] = { 0, 3, 3, 3};

//Wysoko�ci hitbox�w element�w t�a.
static const int BG_HB_SIZE_W[] = { 0, 13, 15, 13 };

//Szeroko�ci hitbox�w element�w t�a.
static const int BG_HB_SIZE_H[] = { 0, 4, 4, 4 };

//Pozycja przycisku w poziomie.
static const int B_POS_X[] = {50, 50, 50};

//Pozycja przycisku w pionie.
static const int B_POS_Y[] = {50, 65, 50};

//Szeroko�� przycisku.
static const int B_SIZE_X = 48;

//Wysoko�� przycisku.
static const int B_SIZE_Y = 11;

//Szeroko�� paska �ycia.
static const int HPBAR_W = 44;

//Wysoko�� paska �ycia.
static const int HPBAR_H = 5;

//Po�o�enie paska �ycia w posiomie.
static const int HPBAR_X = 10;

//po�o�enie paska �ycia w pionie.
static const int HPBAR_Y = 10;

//Po�o�enie paska punktacji w poziomie.
static const int ScBAR_X = 120;

//po�o�enie paska punktacji w pionie.
static const int ScBAR_Y = 10;