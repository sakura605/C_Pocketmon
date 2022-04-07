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
	char _EnemyName[7][128] = { " ", " ", " ", " ", "ĳ����", "����", "����" };
	char _MonRating[7][128] = { "F","C","B","A","S","SS","SSS" };
	char _MonType[10][128] = { "����","��","��","Ǯ","���Ӽ�" };
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

