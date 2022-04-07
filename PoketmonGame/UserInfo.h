#pragma once
#include <vector>
#include "GlobalValue.h"
using namespace std;


class EnemyInfo;
class UserInfo
{
public:
	UserInfo();
	~UserInfo();
public:
	char _player_Name[128];
	PoketMon _Name;
	Rating _Rating;
	Type _Type;

public:
	//트레이너 정보
	int _Gold;
	int _Ball;
	int _Potion;
	int _Stone;
	//포켓몬 정보
	int _Level;
	int _MaxHP;
	int _HP;
	int _ATT;
	int _DEF;
	int _MaxEXP;
	int _EXP;
	int _Medal = 0;

public:
	char _MonName[11][128] = { "피카츄", "파이리", "꼬부기", "이상해씨","캐터피", "꼬렛", "구구","라이츄", "리자몽", "거북왕", "이상해꽃" };
	char _MonRating[7][128] = { "F","C","B","A","S","SS","SSS" };
	char _MonType[10][128] = { "전기","불","물","풀","무속성" };

public:

	void SavePoketMonList(vector<UserInfo>* a_UserInfo);
	void LoadPoketMonList(vector<UserInfo>* a_UserInfo);


	void PoketMonInfo();
	void SetPlayerInfo(vector<UserInfo>* a_UserInfo);
	void AddPoketMonInfo(vector<UserInfo>* a_UserInfo, int a_Num);
};
