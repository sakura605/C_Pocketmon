#include <stdio.h>
#include "PrintScreen.h"
#include "UserInfo.h"
#include "EnemyInfo.h"
#include "BossInfo.h"
#include <time.h>
//#include <Windows.h>


void main()
{
	vector<UserInfo> _PlayerInfo;
	vector<EnemyInfo> _EnemyInfo;
	vector<BossInfo> _BossInfo;

	UserInfo C_UserInfo;
	EnemyInfo C_EnemyIf;
	BossInfo C_BossIf;
	PrintScreen C_Printscr;

	srand((unsigned)time(NULL));
	system("mode con: cols=100 lines=30");

	int a_sel = C_Printscr.StartScreen();	//게임 시작전 원하는 메뉴를 선택한다.

	//1번 - 새로 시작
	if (a_sel == 1)
	{
		C_UserInfo.SetPlayerInfo(&_PlayerInfo);
	}
	//2번 - 저장 된 정보로 시작
	else if (a_sel == 2)
	{
		C_UserInfo.LoadPoketMonList(&_PlayerInfo);
	}
	//3번 - 종료
	else if (a_sel == 3)
	{
		exit(0);
	}

	//메뉴 타이틀
	while (1)
	{
		system("cls");
		C_Printscr.ShowUserInfo(&_PlayerInfo);	//플레이어 정보를 담은 내용
		int a_sel2 = C_Printscr.MenuScreen();				//선택지들

		//------예외처리--------
		if (a_sel2 < 0 || 10 < a_sel2)
		{
			if (a_sel2 == 99)
			{
				break;
			}
			system("cls");
			continue;
		}
		//------예외처리--------

		//0번 리스트
		if (a_sel2 == 0)
		{
			C_Printscr.ShowPoketMonList(&_PlayerInfo);	//플레이어가 보유중인 포켓몬 리스트
		}

		//1번 저장
		else if (a_sel2 == 1)
		{
			C_UserInfo.SavePoketMonList(&_PlayerInfo);	//플레이어가 가지고 있는 정보들을 저장
		}

		//2번 전투관련
		else if (a_sel2 == 2)
		{
			C_EnemyIf.SetEnemyInfo(&_EnemyInfo);

			C_Printscr.FightPoketMon(&_PlayerInfo, &_EnemyInfo);
		}

		//3번 포켓몬 센터
		else if (a_sel2 == 3)
		{
			C_Printscr.HealingPoketMon(&_PlayerInfo);	//포켓몬 회복메시지
			continue;
		}

		//4번 상점
		else if (a_sel2 == 4)
		{
			C_Printscr.BuyStore(&_PlayerInfo);
		}

		//5번 보스전
		else if (a_sel2 == 5)
		{
			C_Printscr.BossFight(&_PlayerInfo, &_BossInfo);
		}

		getchar();
		system("cls");
	}
	_PlayerInfo.clear();
	_EnemyInfo.clear();
}