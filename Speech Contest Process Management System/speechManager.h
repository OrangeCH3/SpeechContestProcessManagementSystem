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

// �ݽ�������
class SpeechManager
{
public:

	// ���캯��
	SpeechManager();

	// չʾ�˵�
	void show_Menu();

	// �˳�ϵͳ
	void exit_System();

	// ��ʼ������
	void init_Speech();

	// ��ʼ����12��ѡ��
	void create_Speaker();

	// ��ʼ����-�������̿���
	void start_Speech();

	// ��ǩ
	void speech_Draw();

	// ����
	void speech_Contest();

	// ��ʾ�������
	void show_Score();

	// �����¼
	void save_Record();

	// ��ȡ��¼
	void load_Record();

	// ��ʾ����÷�
	void show_Record();

	// ��ռ�¼
	void clear_Record();

	// ��������
	~SpeechManager();


	// ��Ա����
	// ����ѡ������12��
	vector<int>v1;

	// ��һ�ֽ�������6��
	vector<int>v2;

	// ʤ��ǰ��������3��
	vector<int>vVictory;

	// ��ű���Լ���Ӧ�ľ���ѡ�ֵ�����
	map<int, Speaker>m_Speaker;

	// ��������
	int m_Index;

	// �ļ�Ϊ�յı�־
	bool fileIsEmpty;

	// �����¼�������
	map<int, vector<string>> m_Record;
};