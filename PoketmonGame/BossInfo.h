#pragma once
#include <vector>
#include <string>
using namespace std;

class BossInfo
{
public:
	BossInfo();
	~BossInfo();

public:
	string _Name;
	string _Grade;
	string _pkmName;
	int _Level;
	int _MaxHP;
	int _HP;
	int _ATT;
	int _DEF;

public:
	void ShowBossInfo(vector<BossInfo> *b_Info);
	void BossSetInfo(vector<BossInfo> *b_Info);
};

