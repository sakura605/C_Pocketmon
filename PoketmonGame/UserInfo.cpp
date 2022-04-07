#include "UserInfo.h"
#include "EnemyInfo.h"
#include "PrintScreen.h"
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#pragma warning(disable:4996)


UserInfo::UserInfo()
{
}


UserInfo::~UserInfo()
{
}

void UserInfo::PoketMonInfo()
{
	printf("[%s���][%s] Lv:%d  HP:%d/%d  ATT:%d  DEF:%d EXP:%d\n",
		_MonRating[_Rating], _MonName[_Name], _Level, _HP, _MaxHP, _ATT, _DEF, _EXP);
}

void UserInfo::SetPlayerInfo(vector<UserInfo> *p_Info)
{
	UserInfo _pInfo;
	PrintScreen _scr;
	_scr.StartMessage();
	_scr.gotoxy(30, 11);
	printf("Ʈ���̳��� �̸��� �������ּ���! : ");
	scanf_s("%s", _pInfo._player_Name, sizeof(_pInfo._player_Name));
	getchar();
	_scr.gotoxy(30, 13);
	printf("Ű��� ���� ���ϸ��� �����ϼ���!");
	_scr.gotoxy(30, 14);
	printf("(��ī�� ��õ�帳�ϴ�.. ��������� ��ī���..�Ф�)");

	_scr.gotoxy(30, 15);
	printf("0.��ī�� 1.���̸� 2.���α� 3.�̻��ؾ� : ");

	_scr.gotoxy(20, 20);
	printf("Tip! ���� Ŭ��� ���ؼ� ��������� ��ȭ��Ų ���ϸ� 2~3������ �ʿ��մϴ�.");
	int Sel = -1;
	scanf_s("%d", &Sel);
	getchar();

	_pInfo._Gold = (rand() % 10 + 1) * 1000;
	_pInfo._Ball = (rand() % 3) + 1;
	_pInfo._Potion = (rand() % 3) + 1;
	_pInfo._Stone = 0;
	_pInfo._Name = (PoketMon)Sel;
	_pInfo._Type = (Type)Sel;
	_pInfo._Rating = (Rating)(rand() % 7);
	_pInfo._Level = 5;
	_pInfo._MaxHP = ((int)_pInfo._Rating * 10) + (_pInfo._Level * 5);
	_pInfo._HP = _pInfo._MaxHP;
	_pInfo._ATT = ((int)_pInfo._Rating * 5) + (_pInfo._Level * 5);
	_pInfo._DEF = (int)_pInfo._Rating + (_pInfo._Level * 2);
	_pInfo._MaxEXP = 100;
	_pInfo._EXP = 0;

	p_Info->push_back(_pInfo);
}

void UserInfo::AddPoketMonInfo(vector<UserInfo>* a_UserInfo, int a_Num)
{
	UserInfo _pInfo;
	a_Num--;
	_pInfo._Name = (PoketMon)a_Num;
	_pInfo._Type = (Type)a_Num;
	_pInfo._Rating = (Rating)(rand() % 7);
	_pInfo._Level = 5;
	_pInfo._MaxHP = ((int)_pInfo._Rating * 10) + (_pInfo._Level * 5);
	_pInfo._HP = _pInfo._MaxHP;
	_pInfo._ATT = ((int)_pInfo._Rating * 5) + (_pInfo._Level * 5);
	_pInfo._DEF = (int)_pInfo._Rating + (_pInfo._Level * 2);
	_pInfo._MaxEXP = 100;
	_pInfo._EXP = 0;

	a_UserInfo->push_back(_pInfo);
}

void UserInfo::SavePoketMonList(vector<UserInfo>* a_UserInfo)
{
	//-----��������
	FILE* a_wPF = fopen("MySave.txt", "wt");

	if (a_wPF != NULL)
	{
		fprintf(a_wPF, "%d\n", (*a_UserInfo).size());
		fprintf(a_wPF, "%s %d %d %d %d %d\n",
			(*a_UserInfo)[0]._player_Name, (*a_UserInfo)[0]._Gold, (*a_UserInfo)[0]._Ball
			, (*a_UserInfo)[0]._Potion, (*a_UserInfo)[0]._Stone, (*a_UserInfo)[0]._Medal);
		for (int i = 0; i < (*a_UserInfo).size(); i++)
		{
			fprintf(a_wPF, "%d %d %d %d %d %d %d %d %d %d\n"
				, (*a_UserInfo)[i]._Rating
				, (*a_UserInfo)[i]._Type
				, (*a_UserInfo)[i]._Name
				, (*a_UserInfo)[i]._Level
				, (*a_UserInfo)[i]._HP
				, (*a_UserInfo)[i]._MaxHP
				, (*a_UserInfo)[i]._ATT
				, (*a_UserInfo)[i]._DEF
				, (*a_UserInfo)[i]._EXP
				, (*a_UserInfo)[i]._MaxEXP);
		}

		fclose(a_wPF);
	}
	PrintScreen _scr;
	_scr.gotoxy(36, 10);
	printf("���� ������ �Ϸ��Ͽ����ϴ�!!\n");
	//-----��������
}

void UserInfo::LoadPoketMonList(vector<UserInfo>* a_UserInfo)
{
	//-----���Ϸε�
	FILE* a_rPF = fopen("MySave.txt", "rt");
	int _MonNum = 0;

	if (a_rPF != NULL)
	{
		UserInfo _PlayerInfo;
		fscanf(a_rPF, "%d\n", &_MonNum);
		fscanf(a_rPF, "%s %d %d %d %d %d\n",
			&_PlayerInfo._player_Name, &_PlayerInfo._Gold, &_PlayerInfo._Ball, &_PlayerInfo._Potion, &_PlayerInfo._Stone, &_PlayerInfo._Medal);
		for (int i = 0; i < _MonNum; i++)
		{
			fscanf(a_rPF, "%d %d %d %d %d %d %d %d %d %d\n"
				, &_PlayerInfo._Rating
				, &_PlayerInfo._Type
				, &_PlayerInfo._Name
				, &_PlayerInfo._Level
				, &_PlayerInfo._HP
				, &_PlayerInfo._MaxHP
				, &_PlayerInfo._ATT
				, &_PlayerInfo._DEF
				, &_PlayerInfo._EXP
				, &_PlayerInfo._MaxEXP);

			a_UserInfo->push_back(_PlayerInfo);
		}
		fclose(a_rPF);
	}

	else
		printf("\"MySave.txt\" ������ �������� �ʽ��ϴ�.\n");
	//-----���Ϸε�
}