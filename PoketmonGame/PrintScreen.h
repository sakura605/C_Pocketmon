#pragma once
#include <vector>
#include "GlobalValue.h"
using namespace std;
#include <string>
class UserInfo;
class EnemyInfo;
class BossInfo;


class PrintScreen
{
public:

public:
	char _StartMessage1[7][128] = { "��", "��", "��", "��", "��", "~", "!"};
	char _StartMessage2[19][128] = { "��", "��", "��", " ", "��", "��", "��", " ", "��", "��", "��", " ", "ȯ", "��","��", "��", "��", "!", "!" };
	char _StartMessage3[19][128] = { "��", " ", "��", "��", "��", " ", "��", "��", "��", " ", "��", "��", "��", "��","��", "��", "��", "��", "." };
	char _StartMessage4[23][128] = { "1", ".", "��", "��", "��", "��", "��", "��", " ", "10", "��", "��", "��", "��"," ", "��", " ", "��", "ȭ", "��","Ų","��","." };
	char _StartMessage5[31][128] = { "2", ".", "��", "��", " ", "��", "��", "��", " ", "ü", "��", "��", " ", "��","��", "��", "��", " ", "��", "��","��","��"," ", "��","��","��"," ","��","��","��", "." };
	char _StartMessage6[16][128] = { "��", "��", " ", "��", "��", "��", "��", " ", "��", "��", "��", "��", "��", "!","!", "!"};
	char _StartMessage9[13][128] = { "��","��","��"," ", "��","��","��","��","��", "!", "!", "!", "!" };
	char _FightMessage[15][128] = { "��", "��", "��", " ", "��", "��", "��", "��", "��", "Ÿ", "��", "��", "!", "!", "!" };
	char _HealingMessage[11][128] = { "ȸ", " ", "��", " ", "��", " ", ".", " ", ".", " ", "." };
	char _CatchingMessage[11][128] = { "��", " ", "ȹ", " ", "��", " ", ".", " ", ".", " ", "." };

	string Tip1;
	string Tip2;

public:
	PrintScreen();
	~PrintScreen();
	
public:
	void gotoxy(int x, int y);

public:
	//���ο� ����� ����Ǵ� �Լ���
	int StartScreen();
	void StartMessage();
	void StartInfo(vector<UserInfo> *p_Info);
	//���ο� ����� ����Ǵ� �Լ���

	//����ȭ�� ��½� ����Ǵ� �Լ���
	void MenuFrame();
	int MenuScreen();
	void UserInfoFrame();
	void ShowUserInfo(vector<UserInfo> *p_Info);
	//����ȭ�� ��½� ����Ǵ� �Լ���


	//0�� ���� ���ϸ� ����Ʈ ����
	void ShowPoketMonList(vector<UserInfo> *p_Info);
	void DeleteList(vector<UserInfo> *p_Info);

	//1�� �������弱���� ����

	//2�� ���������� ����
	void DoNotFight();
	void MyArrow();
	void EnemyArrow();
	void MyFrame();
	void EnemyFrame();
	int ShowFightMessage(vector<EnemyInfo> *e_Info);
	void FightFrame(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info, int);
	int Select(vector<UserInfo> *p_Info);
	void FightPoketMon(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info);
	void AutoFight(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info);
	void HandFight(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info);
	void MyAttack(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info, int, int);
	void EnemyAttack(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info, int);
	bool WinMsg(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info, int);
	bool LoseMsg(vector<UserInfo> *p_Info, int);
	void Catching(vector<UserInfo> *p_Info, vector<EnemyInfo> *e_Info);
	
	//3�� ���ϸ� ȸ�������� ����
	void HealingPoketMon(vector<UserInfo> *p_Info);

	//4�� ����
	void BuyStore(vector<UserInfo> *p_Info);

	//5�� ����
	void BossFight(vector<UserInfo> *p_Info, vector<BossInfo> *b_Info);
	void BossFrame(vector<UserInfo> *p_Info, vector<BossInfo> *b_Info, int, int);

	//�� ��
	void LevelUpPoketMon(vector<UserInfo> *p_Info, int);
	void CenterFrame();
	void ClearFrame();
};