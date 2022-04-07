#include "PrintScreen.h"
#include "UserInfo.h"
#include "EnemyInfo.h"
#include "BossInfo.h"
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

void PrintScreen::gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

PrintScreen::PrintScreen()
{
	srand((unsigned)time(NULL));
	Tip1 = "포켓몬의 등급이 낮다면 다시 뽑길 추천합니다!";
	Tip2 = "밸런스까지 생각하며 만들진 않았습니다!";
}


PrintScreen::~PrintScreen()
{
}


int PrintScreen::StartScreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int i = 0;
	gotoxy(36, 5);
	printf("┏");
	gotoxy(36, 6);
	printf("┃");
	gotoxy(36, 7);
	printf("┗");
	for (int i = 38; i < 58; i += 2)
	{
		gotoxy(i, 5);
		printf("━");
		gotoxy(i, 7);
		printf("━");
	}
	gotoxy(58, 5);
	printf("┓");
	gotoxy(58, 6);
	printf("┃");
	gotoxy(58, 7);
	printf("┛");

	gotoxy(39, 6);
	printf("<포켓몬스터 게임>");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(40, 9);
	printf("1.새로운 모험");
	gotoxy(40, 11);
	printf("2.불러오기");
	gotoxy(40, 13);
	printf("3.나가기");	

	gotoxy(16, 20);
	printf("Tip! 혹시 빠른클리어를 하고싶으시다면 MySave1파일을 MySave로 바꿔서 불러오세요~!");


	gotoxy(50, 13);
	int _Sel = 0;
	scanf_s("%d", &_Sel);
	getchar();

	return _Sel;
}

void PrintScreen::StartMessage()
{
	system("cls");
	gotoxy(30, 3);
	for (int i = 0; i < 7; i++)
	{
		printf("%s", _StartMessage1[i]);
		Sleep(50);
	}
	gotoxy(30, 5);
	for (int i = 0; i < 19; i++)
	{
		printf("%s", _StartMessage2[i]);
		Sleep(50);
	}

	gotoxy(30, 7);
	for (int i = 0; i < 19; i++)
	{
		printf("%s", _StartMessage3[i]);
		Sleep(50);
	}

	gotoxy(30, 9);
	for (int i = 0; i < 23; i++)
	{
		printf("%s", _StartMessage4[i]);
		Sleep(50);
	}

	gotoxy(30, 11);
	for (int i = 0; i < 31; i++)
	{
		printf("%s", _StartMessage5[i]);
		Sleep(50);
	}

	gotoxy(30, 13);
	for (int i = 0; i < 16; i++)
	{
		printf("%s", _StartMessage6[i]);
		Sleep(50);
	}

	gotoxy(30, 15);
	for (int i = 0; i < 13; i++)
	{
		printf("%s", _StartMessage9[i]);
		Sleep(50);
	}
	Sleep(500);
	gotoxy(30, 16);
	printf("엔터키를 눌러주세요");
	getchar();
	system("cls");
}

void PrintScreen::StartInfo(vector<UserInfo> *p_Info)
{
	system("cls");
	gotoxy(30, 9);
	printf("짜잔~~ 귀여운 %s를 습득하셨습니다~", (*p_Info)[0]._MonName);
	gotoxy(30, 11);
	printf("앞으로 멋있게 성장시켜주세요!");

	gotoxy(30, 12);
	printf("<포켓몬 정보>\n");
	gotoxy(30, 14);
	
	getchar();
}

void PrintScreen::MenuFrame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	gotoxy(70, 1);
	printf("┏");

	gotoxy(90, 1);
	printf("┓");

	gotoxy(70, 15);
	printf("┗");

	gotoxy(90, 15);
	printf("┛");
	for (int i = 72; i < 90; i += 2)
	{
		gotoxy(i, 1);
		printf("━");
		gotoxy(i, 15);
		printf("━");
	}
	for (int i = 2; i < 15; i++)
	{
		gotoxy(70, i);
		printf("┃");
		gotoxy(90, i);
		printf("┃");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
int PrintScreen::MenuScreen()
{
	MenuFrame();
	gotoxy(75, 1);
	printf("<메뉴 선택>");
	gotoxy(72, 3);
	printf("0.포켓몬 삭제/진화");
	gotoxy(75, 5);
	printf("1.저 장");
	gotoxy(75, 7);
	printf("2.전 투");
	gotoxy(75, 9);
	printf("3.포켓몬 센터");
	gotoxy(75, 11);
	printf("4.상 점");
	gotoxy(75, 13);
	printf("5.보 스 전");

	gotoxy(75, 16);
	printf("99.나가기");

	int a_Sel = -1;
	scanf_s("%d", &a_Sel);
	getchar();

	return a_Sel;
}

void PrintScreen::UserInfoFrame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 2; i < 30; i += 2)
	{
		gotoxy(i, 1);
		printf("━");
		gotoxy(i, 20);
		printf("━");
	}
	for (int i = 1; i < 20; i++)
	{
		gotoxy(0, i);
		printf("┃");
		gotoxy(30, i);
		printf("┃");
	}

	gotoxy(0, 1);
	printf("┏");

	gotoxy(30, 1);
	printf("┓");

	gotoxy(0, 20);
	printf("┗");

	gotoxy(30, 20);
	printf("┛");
}

void PrintScreen::ShowUserInfo(vector<UserInfo> *p_Info)
{
	UserInfoFrame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	gotoxy(8, 1);
	printf("<트레이너 정보>");
	gotoxy(3, 3);
	printf("이름: %s", (*p_Info)[0]._player_Name);
	gotoxy(3, 5);
	printf("<대표 포켓몬>");
	gotoxy(3, 6);
	printf("[%s등급] %s", (*p_Info)[0]._MonRating[(*p_Info)[0]._Rating], (*p_Info)[0]._MonName[(*p_Info)[0]._Name]);
	gotoxy(3, 7);
	printf("Lv:%d 공격력:%d 방어력:%d", (*p_Info)[0]._Level, (*p_Info)[0]._ATT, (*p_Info)[0]._DEF);
	gotoxy(3, 8);
	float _MyExp = ((float)(*p_Info)[0]._EXP / (float)(*p_Info)[0]._MaxEXP) * 100;
	printf("체력:%d/%d 경험치: %0.f%%", (*p_Info)[0]._HP, (*p_Info)[0]._MaxHP, _MyExp);
	gotoxy(3, 10);
	printf("포켓몬 수: %d마리", (*p_Info).size());
	gotoxy(3, 12);
	printf("골드: %dGold", (*p_Info)[0]._Gold);
	gotoxy(3, 14);
	printf("몬스터 볼: %d개", (*p_Info)[0]._Ball);
	gotoxy(3, 16);
	printf("회복약: %d개", (*p_Info)[0]._Potion);
	gotoxy(3, 18);
	printf("뱃지: %d개", (*p_Info)[0]._Medal);
}

void PrintScreen::ShowPoketMonList(vector<UserInfo> *p_Info)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(32, 17);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	for (int i = 18; i < 29; i++)
	{
		gotoxy(32, i);
		printf("┃");
		gotoxy(98, i);
		printf("┃");
	}
	gotoxy(33, 28);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(34, 17);
	printf("【보유중인 포켓몬 리스트】");
	int _line = 18;
	for (int i = 0; i < (*p_Info).size(); i++)
	{
		gotoxy(34, _line);
		(*p_Info)[i].PoketMonInfo();
		_line++;
	}
	DeleteList(p_Info);
}

void PrintScreen::DeleteList(vector<UserInfo> *p_Info)
{
	int a_Sel = 0;
	gotoxy(36, 4);
	printf("원하시는 메뉴를 선택해주세요:");
	gotoxy(36, 5);
	printf("1.삭제 2.진화 3.나가기");
	scanf_s("%d", &a_Sel);
	getchar();
	
	while (1)
	{
		if (a_Sel == 1)
		{
			gotoxy(36, 7);
			printf("삭제할 포켓몬의 번호 입력: ");
			int a_Num = 0;
			scanf_s("%d", &a_Num);
			getchar();
			if (p_Info->size() < (a_Num))
			{
				gotoxy(36, 9);
				printf("잘못된 번호를 입력하셨습니다!");
				break;
			}
			a_Num--;
			p_Info->erase(p_Info->begin() + a_Num);
			break;
		}
		else if (a_Sel == 2)
		{
			gotoxy(36, 7);
			printf("진화의 돌을 사용하시겠습니까?");
			gotoxy(36, 8);
			printf("%d개 보유중", (*p_Info)[0]._Stone);
			gotoxy(36, 9);
			printf("1.예 2.아니오 ");
			int a_Use;
			scanf_s("%d", &a_Use);
			getchar();
			
			if (a_Use == 1)
			{
				gotoxy(36, 11);
				printf("포켓몬의 번호를 입력해주세요");
				gotoxy(36, 12);
				printf("(포획한 포켓몬은 진화가 불가능합니다.)");
				gotoxy(36, 13);
				printf("(조건:Lv10이상): ");
				int a_Num;
				scanf_s("%d", &a_Num);
				getchar();
				a_Num--;
				if (0 < (*p_Info)[0]._Stone)
				{
					if (6 < (*p_Info)[a_Num]._Name)
					{
						gotoxy(36, 14);
						printf("이미 진화가 된 포켓몬 입니다!");
						getchar();
						break;				
					}

					else if (4 <= (*p_Info)[a_Num]._Name && 4 <= (*p_Info)[a_Num]._Name <= 6)
					{
						gotoxy(36, 14);
						printf("진화가 불가능한 포켓몬입니다 ㅠㅠ");
						getchar();
						break;
					}

					UserInfo _userInfo;
					if (10 <= (*p_Info)[a_Num]._Level)
					{
						(*p_Info)[0]._Stone--;
						gotoxy(36, 13);
						printf("축하합니다! 포켓몬 진화에 성공했습니다!!");
						gotoxy(36, 14);
						printf("%s -> %s", (*p_Info)[a_Num]._MonName[(*p_Info)[a_Num]._Name], (*p_Info)[a_Num]._MonName[(*p_Info)[a_Num]._Name + 7]);
						gotoxy(36, 15);
						printf("체력, 공격력, 방어력이 모두 2배가 되었습니다.");
						(*p_Info)[a_Num]._Name = (PoketMon)((*p_Info)[a_Num]._Name + 7);
						(*p_Info)[a_Num]._MaxHP *= 2;
						(*p_Info)[a_Num]._HP = (*p_Info)[a_Num]._MaxHP;
						(*p_Info)[a_Num]._ATT *= 2;
						(*p_Info)[a_Num]._DEF *= 2;
						getchar();
						break;
					}
					else
					{
						gotoxy(36, 14);
						printf("포켓몬의 레벨이 부족합니다ㅠㅠ");
						gotoxy(36, 15);
						printf("레벨 10이상이 된 후 와주세요!!");
					}
				}

				else
				{
					gotoxy(36, 13);
					printf("진화의 돌이 없습니다ㅠㅠ");
					gotoxy(36, 14);
					printf("상점에서 구매후 사용해주세요!");
					getchar();
					break;
				}
			}//if (a_Use == 1)

			else if (a_Use == 2)
				break;	

		}//if (a_Sel == 1)
		else if (a_Sel == 3)
			break;
	}
}

void PrintScreen::DoNotFight()
{
	CenterFrame();
	gotoxy(36, 11);
	printf("해당 포켓몬이 많이 다쳤습니다ㅠㅠ");
	gotoxy(36, 12);
	printf("센터에 가서 회복시켜주세요!!");
	getchar();
}

int PrintScreen::ShowFightMessage(vector<EnemyInfo> *e_Info)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	CenterFrame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(42, 11);
	printf("탐 색 중");

	gotoxy(34, 19);
	printf("Tip! %s", Tip1.c_str());

	int posX = 52;
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			gotoxy(posX, 11);
			printf(".");
			posX += 2;
			Sleep(200);
		}

		if (56 <= posX)
		{
			gotoxy(50, 11);
			printf("        ");
			posX = 52;
		}
		int num = rand() % 10;
		if (num <= 2)
		{
			break;
		}
	}

	gotoxy(38, 11);
	printf("                            ");
	gotoxy(38, 11);
	for (int i = 0; i < (sizeof(_FightMessage) / 128); i++)
	{
		printf("%s", _FightMessage[i]);
		Sleep(50);
	}

	Sleep(500);
	gotoxy(34, 21);
	(*e_Info)[0].ShowEnemyInfo();
	gotoxy(34, 22);
	printf("1.싸운다.(자동전투) 2.포획한다.(수동전투) 3.도망간다.");
	int a_Sel;
	scanf_s("%d", &a_Sel);
	getchar();

	return a_Sel;
}
int PrintScreen::Select(vector<UserInfo> *p_Info)
{
	gotoxy(10, 2);
	printf("전투할 포켓몬을 선택해주세요");
	int posx = 10;
	for (int i = 0; i < p_Info->size(); i++)
	{
		if (0 < (*p_Info)[i]._HP)
		{
			gotoxy(posx, 3);
			printf("%d.%s", i + 1, (*p_Info)[i]._MonName[(*p_Info)[i]._Name]);
			posx += 12;
		}
	}
	int a_Sel;
	scanf_s("%d", &a_Sel);
	a_Sel--;
	getchar();

	return a_Sel;
}

void PrintScreen::MyFrame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 10; i <= 28; i += 2)
	{
		gotoxy(i, 8);
		printf("━");
		gotoxy(i, 16);
		printf("━");
	}
	for (int i = 8; i < 16; i++)
	{
		gotoxy(8, i);
		printf("┃");
		gotoxy(28, i);
		printf("┃");
	}

	gotoxy(8, 8);
	printf("┏");
	gotoxy(28, 8);
	printf("┓");
	gotoxy(8, 16);
	printf("┗");
	gotoxy(28, 16);
	printf("┛");
}
void PrintScreen::EnemyFrame()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	for (int i = 72; i < 90; i += 2)
	{
		gotoxy(i, 8);
		printf("━");
		gotoxy(i, 16);
		printf("━");
	}
	for (int i = 8; i < 16; i++)
	{
		gotoxy(70, i);
		printf("┃");
		gotoxy(90, i);
		printf("┃");
	}

	gotoxy(70, 8);
	printf("┏");
	gotoxy(90, 8);
	printf("┓");
	gotoxy(70, 16);
	printf("┗");
	gotoxy(90, 16);
	printf("┛");
}
void PrintScreen::FightFrame(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info,int _poketNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	gotoxy(48, 12);
	printf("VS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	MyFrame();
	gotoxy(11, 9);
	printf("[%s]", (*p_Info)[0]._player_Name);
	gotoxy(11, 10);
	printf("[%s등급]%s", (*p_Info)[_poketNum]._MonRating[(*p_Info)[_poketNum]._Rating], (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name]);
	gotoxy(11, 12);
	printf("Lv:%d 공:%d 방:%d", (*p_Info)[_poketNum]._Level, (*p_Info)[_poketNum]._ATT, (*p_Info)[_poketNum]._DEF);
	gotoxy(11, 14);
	printf("체력:%d/%d", (*p_Info)[_poketNum]._HP, (*p_Info)[_poketNum]._MaxHP);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	EnemyFrame();
	gotoxy(73, 10);
	printf("[%s등급]%s  ", (*e_Info)[0]._MonRating[(*e_Info)[0]._Rating], (*e_Info)[0]._EnemyName[(*e_Info)[0]._Enemy]);
	gotoxy(73, 12);
	printf("Lv:%d 공:%d 방:%d", (*e_Info)[0]._Level, (*e_Info)[0]._ATT, (*e_Info)[0]._DEF);
	gotoxy(73, 14);
	printf("체력:%d/%d", (*e_Info)[0]._HP, (*e_Info)[0]._MaxHP);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void PrintScreen::FightPoketMon(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info)
{
	int a_Sel = ShowFightMessage(e_Info);
	system("cls");

	if (a_Sel == 1)
	{
		AutoFight(p_Info, e_Info);
	}

	else if (a_Sel == 2)
	{
		HandFight(p_Info, e_Info);
	}
	e_Info->clear();
}

void PrintScreen::AutoFight(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info)
{
	int a_Sel = Select(p_Info);
	if ((*p_Info)[a_Sel]._HP <= 0)
	{
		DoNotFight();
		system("cls");
		a_Sel = Select(p_Info);
	}
	bool _Check;
	while (1)
	{
		_Check = LoseMsg(p_Info, a_Sel);
		FightFrame(p_Info, e_Info, a_Sel);
		if (_Check == true)
		{
			_Check = false;
			a_Sel = Select(p_Info);
			system("cls");
			FightFrame(p_Info, e_Info, a_Sel);
		}

		int _Skill = rand() % 3;
		if (a_Sel == 0)
		{
			MyAttack(p_Info, e_Info, a_Sel, _Skill);
		}
		else
		{
			gotoxy(4, 18);
			printf("가랏! [%s]!! 몸통박치기! [%d]                 ",
				(*p_Info)[a_Sel]._MonName[(*p_Info)[a_Sel]._Name], (*p_Info)[a_Sel]._ATT - (*e_Info)[0]._DEF);
			(*e_Info)[0]._HP -= (*p_Info)[a_Sel]._ATT - (*e_Info)[0]._DEF;
		}
		MyArrow();
		system("cls");
		FightFrame(p_Info, e_Info, a_Sel);
		Sleep(800);

		_Check = WinMsg(p_Info, e_Info, a_Sel);
		if (_Check == true)
		{
			_Check = false;
			break;
		}
		EnemyAttack(p_Info, e_Info, a_Sel);
		EnemyArrow();
		Sleep(800);
		system("cls");
	}
	LevelUpPoketMon(p_Info, a_Sel);
}
void PrintScreen::HandFight(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info)
{
	gotoxy(20, 2);
	printf("Tip! 수동전투는 포켓몬 포획을 위한 전투입니다.");
	gotoxy(20, 4);
	printf("적 포켓몬의 피를 50%% 이하로 떨어뜨리면 몬스터볼을 사용할 수 있습니다.");
	gotoxy(20, 6);
	printf("주먹기술을 이용해 적 포켓몬의 체력 조절하세요!");
	getchar();
	system("cls");
	int _pkmSel = Select(p_Info);
	if ((*p_Info)[_pkmSel]._HP <= 0)
	{
		DoNotFight();
		system("cls");
		_pkmSel = Select(p_Info);
	}

	bool _Check;
	while (1)
	{
		int _Heal = (rand() % 20) + 50;
		int _Catch = rand() % 2;
		FightFrame(p_Info, e_Info, _pkmSel);
		_Check = LoseMsg(p_Info, _pkmSel);
		if (_Check == true)
		{
			_Check = false;
			_pkmSel = Select(p_Info);
			if (_pkmSel == 3)
				break;
			system("cls");
			FightFrame(p_Info, e_Info, _pkmSel);
		}

		gotoxy(4, 18);
		printf("1.공격 2.회복약[%d개] 3.몬스터볼[%d개] 4.도망가기", (*p_Info)[0]._Potion, (*p_Info)[0]._Ball);
		int a_Sel = 0;
		scanf_s("%d", &a_Sel);
		getchar();
		if (a_Sel == 1)
		{
			if (_pkmSel == 0)
			{
				gotoxy(4, 18);
				printf("1.몸통박치기 2.백만볼트 3.아이언테일 4.주먹![10]");
				int _skill;
				scanf_s("%d", &_skill);
				getchar();
				_skill--;
				if (_skill < 3)
				{
					MyAttack(p_Info, e_Info, a_Sel, _skill);

				}
				else if (_skill == 3)
				{
					gotoxy(4, 18);
					printf("가랏! [%s]!! 주먹!! [10]                           ", (*p_Info)[0]._MonName[(*p_Info)[0]._Name]);
					(*e_Info)[0]._HP -= 10;
				}
			}
			else
			{
				gotoxy(4, 18);
				printf("가랏! [%s]!! 몸통박치기! [%d]                 ",
					(*p_Info)[_pkmSel]._MonName[(*p_Info)[_pkmSel]._Name], (*p_Info)[_pkmSel]._ATT - (*e_Info)[0]._DEF);

				(*e_Info)[0]._HP -= (*p_Info)[_pkmSel]._ATT - (*e_Info)[0]._DEF;
			}
			MyArrow();
		}

		else if (a_Sel == 2)
		{
			if (0 < (*p_Info)[0]._Potion)
			{
				gotoxy(4, 18);
				printf("회복약을 사용하여 체력을 %d회복했습니다!!", _Heal);
				getchar();
				(*p_Info)[_pkmSel]._HP += _Heal;
				(*p_Info)[0]._Potion--;
			}
			else
			{
				gotoxy(4, 18);
				printf("회복약이 부족합니다 ㅠㅠ");
			}
		}

		else if (a_Sel == 3)
		{
			if ((*e_Info)[0]._HP <= ((*e_Info)[0]._MaxHP / 2))
			{
				MyArrow();
				gotoxy(4, 18);
				printf("받아랏!! 몬스터볼!!!!                               ");

				gotoxy(44, 10);
				for (int i = 0; i < sizeof(_CatchingMessage) / 128; i++)
				{
					printf("%s", _CatchingMessage[i]);
					Sleep(300);
				}
				if (_Catch == 0)
				{
					gotoxy(33, 12);
					printf("축하합니다!! [%s]포획에 성공했습니다!", (*e_Info)[0]._EnemyName[(*e_Info)[0]._Enemy]);
					Catching(p_Info, e_Info);
					(*p_Info)[0]._Ball--;
					getchar();
					break;
				}
				else
				{
					gotoxy(36, 12);
					printf("포획에 실패했습니다 ㅠㅠ");
					(*p_Info)[0]._Ball--;
					getchar();
				}
			}
			else
			{
				gotoxy(4, 18);
				printf("적의 피를 반 이하로 깎아주세요!                        ");
				getchar();
			}
		}

		else
		{
			gotoxy(4, 18);
			printf("도망가기!!                        ");
			getchar();
			break;
		}

		_Check = WinMsg(p_Info, e_Info, _pkmSel);
		if (_Check == true)
		{
			_Check == false;
			break;
		}
		system("cls");
		FightFrame(p_Info, e_Info, _pkmSel);
		Sleep(800);
		EnemyAttack(p_Info, e_Info, _pkmSel);
		EnemyArrow();
		Sleep(800);
		system("cls");
	}//while(1)

	LevelUpPoketMon(p_Info, _pkmSel);
}

void PrintScreen::HealingPoketMon(vector<UserInfo> *p_Info)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	int cnt = 0;
	for (int i = 0; i < p_Info->size(); i++)
	{
		if ((*p_Info)[i]._HP < (*p_Info)[i]._MaxHP)
		{
			cnt++;
		}
	}
	CenterFrame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	gotoxy(44, 1);
	printf("<포켓몬 센터>");
	gotoxy(35, 3);
	printf("회복 하시겠습니까? [-%dGold]", cnt * 500);
	gotoxy(40, 6);
	printf("<회복이 필요한 포켓몬>");
	int line = 8;
	if (0 < cnt)
	{
		for (int i = 0; i < p_Info->size(); i++)
		{
			gotoxy(37, line);
			printf("%d.%s HP:%d/%d", i + 1, (*p_Info)[i]._MonName[(*p_Info)[i]._Name], (*p_Info)[i]._HP, (*p_Info)[i]._MaxHP);
			line += 2;
		}
	}
	else
	{
		gotoxy(36, 10);
		printf("회복할 포켓몬이 없습니다 ㅎㅎ");
	}
	gotoxy(35, 4);
	printf("1.회복한다 2.나간다 : ");
	int _Sel = 0;
	scanf_s("%d", &_Sel);
	getchar();
	if (_Sel == 1)
	{
		(*p_Info)[0]._Gold -= cnt * 500;
		for (int i = 0; i < p_Info->size(); i++)
		{
			(*p_Info)[i]._HP = (*p_Info)[i]._MaxHP;
		}


		gotoxy(44, 16);
		for (int i = 0; i < sizeof(_HealingMessage) / 128; i++)
		{
			printf("%s", _HealingMessage[i]);
			Sleep(300);
		}

		gotoxy(40, 17);
		printf("회복이 완료 되었습니다!");
		Sleep(1000);
	}
}

void PrintScreen::BuyStore(vector<UserInfo> *p_Info)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	CenterFrame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(44, 2);
	printf("<포켓몬 상점>");
	gotoxy(44, 6);
	printf("<물품 리스트>");

	gotoxy(37, 8);
	printf("1.몬스터 볼 1000Gold ");
	gotoxy(37, 10);
	printf("2.회복약 500Gold");
	gotoxy(37, 12);
	printf("3.포켓몬 구매 10000Gold");
	gotoxy(37, 14);
	printf("4.진화의 돌 10000Gold");
	gotoxy(37, 15);
	printf("5.나가기");

	int _MonBall = 1000;
	int _Potion = 500;
	int _PoketMon = 10000;
	gotoxy(37, 16);
	printf("구매할 물품 선택:");
	int a_Sel;
	scanf_s("%d", &a_Sel);
	getchar();
	if (a_Sel == 1)
	{
		gotoxy(37, 16);
		printf("구매할 수량 입력: ");
		int a_Num;
		scanf_s("%d", &a_Num);
		getchar();
		if ((_MonBall * a_Num) < (*p_Info)[0]._Gold)
		{
			(*p_Info)[0]._Ball = (*p_Info)[0]._Ball + a_Num;
			(*p_Info)[0]._Gold -= (_MonBall * a_Num);
			gotoxy(37, 16);
			printf("구매를 완료했습니다!!");
		}
		else
		{
			gotoxy(37, 16);
			printf("돈이 부족합니다 ㅠㅠ");
		}
	}
	
	else if (a_Sel == 2)
	{
		gotoxy(37, 16);
		printf("구매할 수량 입력:");
		int a_Num;
		scanf_s("&d", &a_Num);
		getchar();
		if ((_Potion * a_Num) < (*p_Info)[0]._Gold)
		{
			(*p_Info)[0]._Potion += a_Num;
			(*p_Info)[0]._Gold -= (_Potion * a_Num);
			gotoxy(37, 16);
			printf("구매를 완료했습니다!!");
		}
		else
		{
			gotoxy(37, 16);
			printf("돈이 부족합니다 ㅠㅠ");
		}
	}

	else if (a_Sel == 3)
	{
		gotoxy(37, 8);
		printf("1.피카츄               ");
		gotoxy(37, 10);
		printf("2.파이리               ");
		gotoxy(37, 12);
		printf("3.꼬부기               ");
		gotoxy(37, 14);
		printf("4.이상해씨             ");
		gotoxy(37, 15);
		printf("             ");
		gotoxy(37, 16);
		printf("구매할 포켓몬 입력: ");
		int a_Num;
		scanf_s("%d", &a_Num);
		getchar();
		if (_PoketMon < (*p_Info)[0]._Gold)
		{
			UserInfo _UserInfo;
			(*p_Info)[0]._Gold -= _PoketMon;
			_UserInfo.AddPoketMonInfo(p_Info, a_Num);
			gotoxy(37, 16);
			printf("새로운 포켓몬을 구매했습니다!!");
		}
		else
		{
			gotoxy(37, 16);
			printf("돈이 부족합니다 ㅠㅠ");
		}
	}

	else if (a_Sel == 4)
	{
		if (_PoketMon < (*p_Info)[0]._Gold)
		{
			(*p_Info)[0]._Stone++;
			(*p_Info)[0]._Gold -= _PoketMon;
			gotoxy(37, 16);
			printf("진화의 돌을 구매했습니다!!");
		}
	}

}

void PrintScreen::LevelUpPoketMon(vector<UserInfo> *p_Info, int _poketNum)
{
	system("cls");
	int p_hp = rand() % 5 + 5;
	int p_att = rand() % 3 + 3;
	int p_def = rand() % 3 + 1;

	if ((*p_Info)[_poketNum]._EXP >= (*p_Info)[_poketNum]._MaxEXP)
	{
		(*p_Info)[_poketNum]._Level++;
		(*p_Info)[_poketNum]._EXP -= (*p_Info)[_poketNum]._MaxEXP;
		(*p_Info)[_poketNum]._MaxEXP += 20;
		(*p_Info)[_poketNum]._MaxHP += p_hp;
		(*p_Info)[_poketNum]._HP = (*p_Info)[_poketNum]._MaxHP;
		(*p_Info)[_poketNum]._ATT += p_att;
		(*p_Info)[_poketNum]._DEF += p_def;


		printf("축하합니다~~ [%s]가 레벨업을 하여 Lv%d가 됐습니다!!\n", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], (*p_Info)[_poketNum]._Level);
		printf("MaxHP:+%d\n", p_hp);
		printf("ATT:+%d\n", p_att);
		printf("DEF:+%d\n", p_def);
		getchar();
	}
}

void PrintScreen::MyAttack(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info, int _poketNum, int skill)
{
	float P_Attack = (*p_Info)[_poketNum]._ATT - (*e_Info)[0]._DEF;

	if (skill == 0)
	{
		gotoxy(4, 18);
		printf("가랏! [%s]!! 몸통박치기! [%.0f]                 ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
	}

	else if (skill == 1)
	{
		gotoxy(4, 18);
		P_Attack = P_Attack * 1.5f;
		printf("[%s]!! 백만볼트~!~! [%.0f]                       ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
	}

	else if (skill == 2)
	{
		gotoxy(4, 18);
		P_Attack = P_Attack * 1.3f;
		printf("가랏! [%s]!! 아이언테일! [%.0f]                     ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
	}
	(*e_Info)[0]._HP -= P_Attack;
}

void PrintScreen::EnemyAttack(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info, int _poketNum)
{
	float E_Attack = (*e_Info)[0]._ATT - (*p_Info)[_poketNum]._DEF;
	if (E_Attack <= 0)
		E_Attack = 0;

	gotoxy(70, 18);
	printf("[%s]의 공격!![%.0f]\n", (*e_Info)[0]._EnemyName[(*e_Info)[0]._Enemy], E_Attack);
	(*p_Info)[_poketNum]._HP -= E_Attack;
}

void PrintScreen::MyArrow()
{
	int x = 30, x2 = 68;

	for (x; x < x2; x++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		gotoxy(x, 10);
		printf("━━>");
		gotoxy((x - 1), 10);
		printf(" ");
		Sleep(20);
		if (67 <= x)
		{
			gotoxy(x, 10);
			printf("   ");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
}
void PrintScreen::EnemyArrow()
{
	int x = 30, x2 = 67;
	for (x2; x < x2; x2--)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		gotoxy(x2, 14);
		printf("<━━");
		gotoxy((x2 + 5), 14);
		printf(" ");
		Sleep(20);
		if (33 >= x2)
		{
			gotoxy(x2, 14);
			printf("     ");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
}

bool PrintScreen::WinMsg(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info,int _poketNum)
{
	if ((*e_Info)[0]._HP <= 0)
	{
		gotoxy(33, 12);
		(*e_Info)[0]._HP = 0;
		printf("전투에서 승리하셨습니다!!");
		gotoxy(33, 13);
		printf("경험치 + %d, 골드 + %d", (*e_Info)[0]._Level * 10, (*e_Info)[0]._Level * 200);
		(*p_Info)[_poketNum]._EXP += ((*e_Info)[0]._Level * 7);
		(*p_Info)[0]._Gold += ((*e_Info)[0]._Level * 200);
		getchar();
		return true;
	}
	return false;
}
bool PrintScreen::LoseMsg(vector<UserInfo> *p_Info, int _poketNum)
{
	if ((*p_Info)[_poketNum]._HP <= 0)
	{
		gotoxy(33, 11);
		(*p_Info)[_poketNum]._HP = 0;
		printf("전투에서 패배했습니다ㅜㅜ");
		gotoxy(33, 13);
		getchar();
		system("cls");
		return true;
	}
	return false;
}

void PrintScreen::CenterFrame()
{
	gotoxy(33, 5);
	printf("■■■■■■■■■■■■■■■■■■");

	gotoxy(33, 18);
	printf("■■■■■■■■■■■■■■■■■■");

	for (int i = 6; i < 18; i++)
	{
		gotoxy(33, i);
		printf("■");
		gotoxy(67, i);
		printf("■");
	}
}

void PrintScreen::Catching(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info)
{
	UserInfo pInfo;
	pInfo._Name = (*e_Info)[0]._Enemy;
	pInfo._Type = (*e_Info)[0]._Type;
	pInfo._Rating = (*e_Info)[0]._Rating;
	pInfo._Level = (*e_Info)[0]._Level;
	pInfo._MaxHP = (*e_Info)[0]._MaxHP;
	pInfo._HP = (*e_Info)[0]._MaxHP;
	pInfo._ATT = (*e_Info)[0]._ATT;
	pInfo._DEF = (*e_Info)[0]._DEF;
	pInfo._EXP = 0;
	pInfo._MaxEXP = 100;

	p_Info->push_back(pInfo);
}

void PrintScreen::BossFight(vector<UserInfo> *p_Info, vector<BossInfo> *b_Info)
{
	if (10 < (*p_Info)[0]._Level && 6 < (*p_Info)[0]._Name);
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		CenterFrame();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		gotoxy(38, 4);
		printf("보스와의 전투가 가능합니다!!");
		gotoxy(44, 6);
		printf("<보스 정보>");
		BossInfo _bIf;
		_bIf.BossSetInfo(b_Info);
		gotoxy(38, 8);
		printf("이름:%s", (*b_Info)[0]._Name.c_str());
		gotoxy(38, 9);
		printf("첫번째 포켓몬 : %s", (*b_Info)[0]._pkmName.c_str());
		gotoxy(54, 10);
		printf("공:%d 방:%d", (*b_Info)[0]._ATT, (*b_Info)[0]._DEF);
		gotoxy(38, 11);
		printf("두번째 포켓몬 : %s", (*b_Info)[1]._pkmName.c_str());
		gotoxy(54, 12);
		printf("공:%d 방:%d", (*b_Info)[1]._ATT, (*b_Info)[1]._DEF);
		gotoxy(38, 13);
		printf("세번째 포켓몬 : %s", (*b_Info)[2]._pkmName.c_str());
		gotoxy(54, 14);
		printf("공:%d 방:%d", (*b_Info)[2]._ATT, (*b_Info)[2]._DEF);

		gotoxy(36, 16);
		printf("전투를 원하시면 100 입력 : ");
		int a_Chall = 0;
		scanf_s("%d", &a_Chall);
		getchar();
		if (a_Chall != 100)
			return;

		if (0 < (*p_Info)[0]._Medal)
		{
			gotoxy(36, 16);
			printf("이미 클리어 했습니다!!     ");
			getchar();
			return;
		}

		if ((*p_Info)[0]._Level < 10)
		{
			gotoxy(36, 17);
			printf("레벨을 10이상 달성하신 후 도전해주세요!");
			getchar();
			return;
		}

		system("cls");
		int _BossNum = 0;
		int _poketNum = 0;
		bool _Check;
		int _size = p_Info->size();
		system("cls");
		while (1)
		{
			if (a_Chall == 100)
			{
				_Check = LoseMsg(p_Info, _poketNum);
				if (_Check == true)
				{
					_poketNum++;
					if (p_Info->size() <= _poketNum)
					{
						break;
					}
				}
				BossFrame(p_Info, b_Info, _poketNum, _BossNum);

				int _Skill = rand() % 3;
				float P_Attack = (*p_Info)[_poketNum]._ATT - (*b_Info)[_BossNum]._DEF;
				if (0 < (*p_Info)[_poketNum]._HP)
				{
					if (_poketNum == 0)
					{
						if (_Skill == 0)
						{
							gotoxy(4, 18);
							printf("가랏! [%s]!! 몸통박치기! [%.0f]                 ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
						}

						else if (_Skill == 1)
						{
							gotoxy(4, 18);
							P_Attack = P_Attack * 1.5f;
							printf("[%s]!! 백만볼트~!~! [%.0f]                       ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
						}

						else if (_Skill == 2)
						{
							gotoxy(4, 18);
							P_Attack = P_Attack * 1.3f;
							printf("가랏! [%s]!! 아이언테일! [%.0f]                     ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
						}
						(*b_Info)[_BossNum]._HP -= P_Attack;
					}
					else
					{
						gotoxy(4, 18);
						printf("가랏! [%s]!! 공격해!! [%.0f]                 ", (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name], P_Attack);
						(*b_Info)[_BossNum]._HP -= P_Attack;
					}
					MyArrow();
					system("cls");
					BossFrame(p_Info, b_Info, _poketNum, _BossNum);
					Sleep(800);
				}
				else
				{
					gotoxy(33, 10);
					printf("전투가 불가능한 포켓몬입니다...");
					_poketNum++;
					if (p_Info->size() <= _poketNum)
					{
						break;
					}
					getchar();
					system("cls");
					continue;
				}

				float E_Attack = (*b_Info)[_BossNum]._ATT - (*p_Info)[_poketNum]._DEF;
				if (E_Attack <= 0)
					E_Attack = 0;

				if ((*b_Info)[_BossNum]._HP <= 0)
				{
					if (_BossNum <= 2)
					{
						(*b_Info)[_BossNum]._HP = 0;
						gotoxy(70, 18);
						printf("돌아와 %s!!", (*b_Info)[_BossNum]._pkmName.c_str());
						_BossNum++;
						if (3 <= _BossNum)
						{
							gotoxy(70, 18);
							printf("큭... 내가졌다.. ㅠㅠ");
							gotoxy(70, 19);
							printf("여기 블루시티 뱃지를 줄게~");
							(*p_Info)[0]._Medal++;
							getchar();
							ClearFrame();
							break;
						}
						else
						{
							gotoxy(70, 19);
							printf("나와랏 %s!!", (*b_Info)[_BossNum]._pkmName.c_str());
							Sleep(800);
							continue;
						}
					}
				}

				gotoxy(70, 18);
				printf("[%s]의 공격!![%d]\n", (*b_Info)[_BossNum]._pkmName.c_str(), (*b_Info)[_BossNum]._ATT);
				(*p_Info)[_poketNum]._HP -= E_Attack;
				EnemyArrow();
				system("cls");
				BossFrame(p_Info, b_Info, _poketNum, _BossNum);
				Sleep(800);
			}
		}
	}
}

void PrintScreen::BossFrame(vector<UserInfo> *p_Info, vector<BossInfo> *b_Info, int _poketNum, int _BpoketNum)
{
	MyFrame();
	gotoxy(11, 9);
	printf("[%s]", (*p_Info)[0]._player_Name);
	gotoxy(11, 10);
	printf("[%s등급]%s", (*p_Info)[_poketNum]._MonRating[(*p_Info)[_poketNum]._Rating], (*p_Info)[_poketNum]._MonName[(*p_Info)[_poketNum]._Name]);
	gotoxy(11, 12);
	printf("Lv:%d 공:%d 방:%d", (*p_Info)[_poketNum]._Level, (*p_Info)[_poketNum]._ATT, (*p_Info)[_poketNum]._DEF);
	gotoxy(11, 14);
	printf("체력:%d/%d", (*p_Info)[_poketNum]._HP, (*p_Info)[_poketNum]._MaxHP);

	EnemyFrame();
	gotoxy(73, 9);
	printf("[%s]", (*b_Info)[0]._Name.c_str());
	gotoxy(73, 10);
	printf("[%s등급]%s  ", (*b_Info)[_BpoketNum]._Grade.c_str(), (*b_Info)[_BpoketNum]._pkmName.c_str());
	gotoxy(73, 12);
	printf("Lv:%d 공:%d 방:%d", (*b_Info)[_BpoketNum]._Level, (*b_Info)[_BpoketNum]._ATT, (*b_Info)[_BpoketNum]._DEF);
	gotoxy(73, 14);
	printf("체력:%d/%d", (*b_Info)[_BpoketNum]._HP, (*b_Info)[_BpoketNum]._MaxHP);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void PrintScreen::ClearFrame()
{
	system("cls");
	int cnt = 0;
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		gotoxy(38, 10);
		printf("★☆★☆축하합니다★☆★☆");
		gotoxy(39, 13);
		printf("★☆★Game Clear!!☆★☆");
		CenterFrame();
		Sleep(500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		gotoxy(38, 10);
		printf("★☆★☆축하합니다★☆★☆");
		gotoxy(39, 13);
		printf("★☆★Game Clear!!☆★☆");
		CenterFrame();
		Sleep(500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		gotoxy(38, 10);
		printf("★☆★☆축하합니다★☆★☆");
		gotoxy(39, 13);
		printf("★☆★Game Clear!!☆★☆");
		CenterFrame();
		Sleep(500);
		cnt++;

		if (2 < cnt)
		{
			gotoxy(39, 16);
			printf("엔터키를 입력해 빠져나가기");
			break;
		}
	}
	
}