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

	int a_sel = C_Printscr.StartScreen();	//���� ������ ���ϴ� �޴��� �����Ѵ�.

	//1�� - ���� ����
	if (a_sel == 1)
	{
		C_UserInfo.SetPlayerInfo(&_PlayerInfo);
	}
	//2�� - ���� �� ������ ����
	else if (a_sel == 2)
	{
		C_UserInfo.LoadPoketMonList(&_PlayerInfo);
	}
	//3�� - ����
	else if (a_sel == 3)
	{
		exit(0);
	}

	//�޴� Ÿ��Ʋ
	while (1)
	{
		system("cls");
		C_Printscr.ShowUserInfo(&_PlayerInfo);	//�÷��̾� ������ ���� ����
		int a_sel2 = C_Printscr.MenuScreen();				//��������

		//------����ó��--------
		if (a_sel2 < 0 || 10 < a_sel2)
		{
			if (a_sel2 == 99)
			{
				break;
			}
			system("cls");
			continue;
		}
		//------����ó��--------

		//0�� ����Ʈ
		if (a_sel2 == 0)
		{
			C_Printscr.ShowPoketMonList(&_PlayerInfo);	//�÷��̾ �������� ���ϸ� ����Ʈ
		}

		//1�� ����
		else if (a_sel2 == 1)
		{
			C_UserInfo.SavePoketMonList(&_PlayerInfo);	//�÷��̾ ������ �ִ� �������� ����
		}

		//2�� ��������
		else if (a_sel2 == 2)
		{
			C_EnemyIf.SetEnemyInfo(&_EnemyInfo);

			C_Printscr.FightPoketMon(&_PlayerInfo, &_EnemyInfo);
		}

		//3�� ���ϸ� ����
		else if (a_sel2 == 3)
		{
			C_Printscr.HealingPoketMon(&_PlayerInfo);	//���ϸ� ȸ���޽���
			continue;
		}

		//4�� ����
		else if (a_sel2 == 4)
		{
			C_Printscr.BuyStore(&_PlayerInfo);
		}

		//5�� ������
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