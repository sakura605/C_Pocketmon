#include "EnemyInfo.h"
#include <stdio.h>


EnemyInfo::EnemyInfo()
{
}


EnemyInfo::~EnemyInfo()
{
}


void EnemyInfo::ShowEnemyInfo()
{
	printf("[%s] Lv:%d  HP:%d/%d  ATT:%d  DEF:%d", _EnemyName[_Enemy], _Level, _HP, _MaxHP, _ATT, _DEF);
}

void EnemyInfo::SetEnemyInfo(vector<EnemyInfo> *e_Info)
{
	EnemyInfo _eInfo;

	_eInfo._Enemy = (PoketMon)((rand() % 3) + 4);
	_eInfo._Type = (Type)Mu;
	_eInfo._Rating = (Rating)(rand() % 7);
	_eInfo._Level = 3 + (int)_eInfo._Rating;
	_eInfo._MaxHP = 60 + ((int)_eInfo._Rating * 10);
	_eInfo._HP = _eInfo._MaxHP;
	_eInfo._ATT = 15 + ((int)_eInfo._Rating * 5);
	_eInfo._DEF = 5 + ((int)_eInfo._Rating * 2);
	_eInfo._EXP = 0;

	e_Info->push_back(_eInfo);
}
