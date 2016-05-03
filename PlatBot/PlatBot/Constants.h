#pragma once

#include <deque>
#include <vector>

//Szerokoœæ pola planszy
static const int TILE_W = 16;

//Wysokoœæ pola planszy
static const int TILE_H = 16;

//Szerokoœæ planszy
static const int MAP_W = 15;

//Wysokoœæ planszy
static const int MAP_H = 10;

//Grawitacja
static const int GRAVITY = 500;

//Domyœlne przyœpieszenie postaci
static const int BASE_ACC = 200;

//Szerokoœæ widoku
static const int VIEW_W = 200;

//Wysokoœæ widoku
static const int VIEW_H = 150;



//Pocz¹tkowe po³o¿enie lewej krawêdzi spritera postaci.
static const int P_START_X = 40;

//Pocz¹tkowe po³o¿enie górnej krawêdzi spritera postaci.
static const int P_START_Y = 56;

//Wysokoœæ spritera postaci.
static const int P_SPRITE_W = 32;

//Szerokoœæ spritera postaci.
static const int P_SPRITE_H = 32;

//Pocz¹tkowe HP postaci.
static const int P_HEALTH = 10;

//Prêdkoœæ poruszania siê postaci
static const int P_SPEED = 2;

//Ró¿nica miêdzy hitboxem postaci a lewym brzegiem spritera.
static const int P_HB_DIFF_W = 11;

//Ró¿nica miêdzy hitboxem postaci a lewym brzegiem spritera.
static const int P_HB_DIFF_H = 7;

//Wysokoœæ hitboxa postaci.
static const int P_HB_SIZE_W = 10;

//Szerokoœæ hitboxa postaci.
static const int P_HB_SIZE_H = 19;

//Pozycja ataków wzglêdem po³o¿enia postaci w poziomie.
static const int P_A_POS_X[] = { 20, 20 };

//Pozycja ataków wzglêdem po³o¿enia postaci w pionie.
static const int P_A_POS_Y[] = { 10, 10 };

//Cooldown ataku postaci.
static const float P_ATT_CD = 0.5f;

//Prêdkoœæ pocisków postaci
static const int P_PROJECTILE_SPEED = 100;

//Typy ataków u¿ywane przez postaæ
static const int P_A_TYPE[] = { 0, 1 };

//Wysokoœæ spritera przeciwnika
static const int E_SPRITE_W = 32;

//Szerokoœæ spritera przeciwnika
static const int E_SPRITE_H = 32;

//Pocz¹tkowe HP przeciwników
static const int E_HEALTH[] = { 1, 2 };

//Prêdkoœæ poruszania siê przeciwników
static const int E_SPEED[] = { 5, 5 };

//Ró¿nice miêdzy hitboxami przeciwników a lewymi brzegami ich spriterów.
static const int E_HB_DIFF_W[] = { 9, 11 };

//Ró¿nice miêdzy hitboxami przeciwników a górnymi brzegami ich spriterów.
static const int E_HB_DIFF_H[] = { 4, 7 };

//Wysokoœci hitboxów przeciwników.
static const int E_HB_SIZE_W[] = { 18, 10 };

//Szerokoœci hitboxów przeciwników.
static const int E_HB_SIZE_H[] = { 23, 21 };

//Odpornoœci przeciwników na ataki klasy Hit
static const int E_HIT_DMG_TKN[] = { 2, 2 };

//Odpornoœci przeciwników na ataki klasy Projectile
static const int E_PROJECTILE_DMG_TKN[] = { 2, 1 };

//Pozycje ataków wzglêdem po³o¿enia przeciwników w poziomie.
static const int E_A_POS_X[] = { 20, 23 };

//Pozycje ataków wzglêdem po³o¿enia przeciwników w pionie.
static const int E_A_POS_Y[] = { 15, 10 };

//Cooldowny ataków przeciwników
static const float E_ATT_CD[] = { 2.0f, 1.0f };

//Prêdkoœæ pocisków przeciwników
static const int E_PROJECTILE_SPEED[] = { 50, 0 };

//true je¿eli przeciwnik u¿ywa ataku typu Hit
static const bool E_MELEE[] = { false, true };

//true je¿eli przeciwnik u¿ywa ataku typu Projectile
static const bool E_RANGED[] = { true, false };

//Typy ataków u¿ywanych przez przeciwników.
static const int E_A_TYPE[] = { 2, 3 };

//Wysokoœæ spritera ataku
static const int A_SPRITE_W = 16;

//Szerokoœæ spritera ataku
static const int A_SPRITE_H = 16;

//Wysokoœci hitboxów ataków.
static const int A_HB_SIZE_W[] = { 6, 7, 6, 7 };

//Szerokoœci hitboxów ataków.
static const int A_HB_SIZE_H[] = { 6, 10, 6, 10 };

//Ró¿nice miêdzy hitboxami ataków a lewymi brzegami ich spriterów.
static const int A_HB_DIFF_W[] = { 5, 5, 5, 5 };

//Ró¿nice miêdzy hitboxami ataków a górnymi brzegami ich spriterów.
static const int A_HB_DIFF_H[] = { 5, 0, 5, 0 };

//Czasy trwania ataków.
static const float A_TIMER[] = { 0.1f, 0.1f, 0.1f, 0.15f };

//Ró¿nice miêdzy hitboxami elementów t³a a lewymi brzegami ich spriterów.
static const int BG_HB_DIFF_W[] = { 0, 2, 0, 0};

//Ró¿nice miêdzy hitboxami elementów t³a a górnymi brzegami ich spriterów.
static const int BG_HB_DIFF_H[] = { 0, 3, 3, 3};

//Wysokoœci hitboxów elementów t³a.
static const int BG_HB_SIZE_W[] = { 0, 13, 15, 13 };

//Szerokoœci hitboxów elementów t³a.
static const int BG_HB_SIZE_H[] = { 0, 4, 4, 4 };

//Pozycja przycisku w poziomie.
static const int B_POS_X[] = {50, 50, 50};

//Pozycja przycisku w pionie.
static const int B_POS_Y[] = {50, 65, 50};

//Szerokoœæ przycisku.
static const int B_SIZE_X = 48;

//Wysokoœæ przycisku.
static const int B_SIZE_Y = 11;

//Szerokoœæ paska ¿ycia.
static const int HPBAR_W = 44;

//Wysokoœæ paska ¿ycia.
static const int HPBAR_H = 5;

//Po³o¿enie paska ¿ycia w posiomie.
static const int HPBAR_X = 10;

//po³o¿enie paska ¿ycia w pionie.
static const int HPBAR_Y = 10;

//Po³o¿enie paska punktacji w poziomie.
static const int ScBAR_X = 120;

//po³o¿enie paska punktacji w pionie.
static const int ScBAR_Y = 10;