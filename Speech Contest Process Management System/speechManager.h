#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <map>
#include <deque>
#include <numeric>
#include "speaker.h"
#include <algorithm>
#include <ctime>

// 演讲管理类
class SpeechManager
{
public:

	// 构造函数
	SpeechManager();

	// 展示菜单
	void show_Menu();

	// 退出系统
	void exit_System();

	// 初始化属性
	void init_Speech();

	// 初始创建12名选手
	void create_Speaker();

	// 开始比赛-比赛流程控制
	void start_Speech();

	// 抽签
	void speech_Draw();

	// 比赛
	void speech_Contest();

	// 显示比赛结果
	void show_Score();

	// 保存记录
	void save_Record();

	// 读取记录
	void load_Record();

	// 显示往届得分
	void show_Record();

	// 清空记录
	void clear_Record();

	// 析构函数
	~SpeechManager();


	// 成员属性
	// 比赛选手容器12人
	vector<int>v1;

	// 第一轮晋级容器6人
	vector<int>v2;

	// 胜利前三名容器3人
	vector<int>vVictory;

	// 存放编号以及对应的具体选手的容器
	map<int, Speaker>m_Speaker;

	// 比赛轮数
	int m_Index;

	// 文件为空的标志
	bool fileIsEmpty;

	// 往届记录存放容器
	map<int, vector<string>> m_Record;
};