#include "BossInfo.h"



BossInfo::BossInfo()
{
}


BossInfo::~BossInfo()
{
}


void BossInfo::BossSetInfo(vector<BossInfo> *b_Info)
{
	BossInfo bInfo;
	bInfo._Name = "이슬이";
	bInfo._Grade = "BOSS";
	bInfo._pkmName = "별가사리";
	bInfo._Level = 10;
	bInfo._MaxHP = 200;
	bInfo._HP = bInfo._MaxHP;
	bInfo._ATT = 120;
	bInfo._DEF = 40;
	b_Info->push_back(bInfo);

	bInfo._pkmName = "아쿠스타";
	bInfo._Level = 15;
	bInfo._MaxHP = 250;
	bInfo._HP = bInfo._MaxHP;
	bInfo._ATT = 150;
	bInfo._DEF = 50;
	b_Info->push_back(bInfo);

	bInfo._pkmName = "갸라도스";
	bInfo._Level = 20;
	bInfo._MaxHP = 300;
	bInfo._HP = bInfo._MaxHP;
	bInfo._ATT = 180;
	bInfo._DEF = 60;

	b_Info->push_back(bInfo);
}

void BossInfo::ShowBossInfo(vector<BossInfo> *b_Info)
{
	printf("[%s]\n", (*b_Info)[0]._Name.c_str());
	for (int i = 0; i < b_Info->size(); i++)
	{
		printf("[%s][%s] Lv:%d  HP:%d/%d  ATT:%d  DEF:%d\n",
			(*b_Info)[i]._Grade.c_str(), (*b_Info)[i]._pkmName.c_str()
			, (*b_Info)[i]._Level, (*b_Info)[i]._HP, (*b_Info)[i]._MaxHP
			, (*b_Info)[i]._ATT, (*b_Info)[i]._DEF);
	}
}