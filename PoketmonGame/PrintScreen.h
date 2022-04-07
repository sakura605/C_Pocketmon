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
	char _StartMessage1[7][128] = { "안", "녕", "하", "세", "요", "~", "!"};
	char _StartMessage2[19][128] = { "포", "켓", "몬", " ", "세", "상", "에", " ", "오", "신", "걸", " ", "환", "영","합", "니", "다", "!", "!" };
	char _StartMessage3[19][128] = { "본", " ", "게", "임", "의", " ", "목", "적", "을", " ", "알", "려", "드", "리","겠", "습", "니", "다", "." };
	char _StartMessage4[23][128] = { "1", ".", "메", "인", "포", "켓", "몬", "을", " ", "10", "레", "벨", "달", "성"," ", "후", " ", "진", "화", "시","킨","다","." };
	char _StartMessage5[31][128] = { "2", ".", "후", "에", " ", "열", "리", "는", " ", "체", "육", "관", " ", "관","장", "에", "게", " ", "승", "리","하","여"," ", "뱃","지","를"," ","얻","는","다", "." };
	char _StartMessage6[16][128] = { "그", "럼", " ", "재", "미", "있", "게", " ", "즐", "겨", "주", "세", "요", "!","!", "!"};
	char _StartMessage9[13][128] = { "모","험","을"," ", "시","작","합","니","다", "!", "!", "!", "!" };
	char _FightMessage[15][128] = { "야", "생", "의", " ", "포", "켓", "몬", "이", "나", "타", "났", "다", "!", "!", "!" };
	char _HealingMessage[11][128] = { "회", " ", "복", " ", "중", " ", ".", " ", ".", " ", "." };
	char _CatchingMessage[11][128] = { "포", " ", "획", " ", "중", " ", ".", " ", ".", " ", "." };

	string Tip1;
	string Tip2;

public:
	PrintScreen();
	~PrintScreen();
	
public:
	void gotoxy(int x, int y);

public:
	//새로운 모험시 적용되는 함수들
	int StartScreen();
	void StartMessage();
	void StartInfo(vector<UserInfo> *p_Info);
	//새로운 모험시 적용되는 함수들

	//메인화면 출력시 적용되는 함수들
	void MenuFrame();
	int MenuScreen();
	void UserInfoFrame();
	void ShowUserInfo(vector<UserInfo> *p_Info);
	//메인화면 출력시 적용되는 함수들


	//0번 보유 포켓몬 리스트 관련
	void ShowPoketMonList(vector<UserInfo> *p_Info);
	void DeleteList(vector<UserInfo> *p_Info);

	//1번 파일저장선택지 관련

	//2번 전투선택지 관련
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
	
	//3번 포켓몬 회복선택지 관련
	void HealingPoketMon(vector<UserInfo> *p_Info);

	//4번 상점
	void BuyStore(vector<UserInfo> *p_Info);

	//5번 보스
	void BossFight(vector<UserInfo> *p_Info, vector<BossInfo> *b_Info);
	void BossFrame(vector<UserInfo> *p_Info, vector<BossInfo> *b_Info, int, int);

	//그 외
	void LevelUpPoketMon(vector<UserInfo> *p_Info, int);
	void CenterFrame();
	void ClearFrame();
};