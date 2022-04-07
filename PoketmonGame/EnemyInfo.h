#pragma once
#include <vector>
#include "GlobalValue.h"
using namespace std;

class EnemyInfo
{

public:
	EnemyInfo();
	~EnemyInfo();

public:
	char _EnemyName[7][128] = { " ", " ", " ", " ", "캐터피", "꼬렛", "구구" };
	char _MonRating[7][128] = { "F","C","B","A","S","SS","SSS" };
	char _MonType[10][128] = { "전기","불","물","풀","무속성" };
	PoketMon _Enemy;
	Type _Type;
	Rating _Rating;
	int _Level;
	int _MaxHP;
	int _HP;
	int _ATT;
	int _DEF;
	int _EXP;

public:
	void ShowEnemyInfo();
	void SetEnemyInfo(vector<EnemyInfo> *e_Info);
};

