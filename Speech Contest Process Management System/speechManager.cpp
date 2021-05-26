#include "speechManager.h"

SpeechManager::SpeechManager()
{
    // ��ʼ������
    this->init_Speech();

    // ����ѡ��
    this->create_Speaker();

    // ��ȡ�����¼
    this->load_Record();
}

void SpeechManager::show_Menu()
{
    cout << "*********************************************" << endl;
    cout << "************* ��ӭ�μ��ݽ����� **************" << endl;
    cout << "*************  1.��ʼ�ݽ�����  **************" << endl;
    cout << "*************  2.�鿴�����¼  **************" << endl;
    cout << "*************  3.��ձ�����¼  **************" << endl;
    cout << "*************  0.�˳���������  **************" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
}

void SpeechManager::exit_System()
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::init_Speech()
{
    // ��֤����Ϊ��
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    // ��ʼ����������
    this->m_Index = 1;

    // ��ʼ����¼����
    this->m_Record.clear();
}

void SpeechManager::create_Speaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "Player-";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }

        // 12��ѡ�ֱ��
        this->v1.push_back(i + 10001);

        // ��ѡ�ֱ�ź�ѡ�ִ�ŵ�map������
        this->m_Speaker.insert(pair<int, Speaker>(i + 10001, sp));
    }
}

void SpeechManager::start_Speech()
{
    // ��һ�ֱ���
    // 1����ǩ
    speech_Draw();

    // 2������
    speech_Contest();

    // 3����ʾ�������
    show_Score();

    // �ڶ��ֱ���
    this->m_Index++;
    // 1����ǩ
    speech_Draw();

    // 2������
    speech_Contest();

    // 3����ʾ���ս��
    show_Score();

    // 4���������
    save_Record();

    // ���ñ���
    // ��ʼ������
    this->init_Speech();

    // ����ѡ��
    this->create_Speaker();

    // ��ȡ�����¼
    this->load_Record();

    cout << "���������ϣ�" << endl;
    system("pause");
    system("cls");
}

void SpeechManager::speech_Draw()
{
    cout << "��<< " << this->m_Index << " >>�ֱ���ѡ�����ڳ�ǩ��" << endl;
    cout << endl;
    cout << "��ǩ���ݽ�˳�����£�" << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::speech_Contest()
{
    cout << "��" << this->m_Index << "�ֱ�����ʽ��ʼ��" << endl;

    multimap<double, int, greater<double>> groupScore;  // ��ʱ��������ŷ���key�ͱ��value

    int num = 0;  // ��¼��Ա����6��Ϊ1��

    vector<int>v_Src;  // ��������Ա����
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }
    
    // �������в���ѡ��
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;

        //��ί���
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;  // 60.0~100.0
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());  // ����
        d.pop_back();  // ȥ����ͷ�
        d.pop_front();  // ȥ����߷�

        double sum = accumulate(d.begin(), d.end(), 0.0f);  // ��ȡ�ܷ�
        double avg = sum / (double)d.size();  // ��ȡƽ����

        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        // 6����һ�飬����ʱ�������
        groupScore.insert(pair<double, int>(avg, *it));
        if (num % 6 == 0)
        {
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "��ţ�" << it->second
                    << " | ������" << this->m_Speaker[it->second].m_Name
                    << " | �ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index - 1]
                    << endl;
            }

            int count = 0;
            // ȡǰ����
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }
            }

            groupScore.clear();

            cout << endl;
        }
    }
    cout << "��" << this->m_Index << "�ֱ�����ϣ�" << endl;
    system("pause");

}

void SpeechManager::show_Score()
{
    cout << "��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�" << endl;
    vector<int>v;
    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "��ţ�" << *it
            << " | ������" << this->m_Speaker[*it].m_Name
            << " | �ɼ���" << this->m_Speaker[*it].m_Score[this->m_Index - 1]
            << endl;
    }
    cout << endl;

    system("pause");
    system("cls");
    this->show_Menu();
}

void SpeechManager::save_Record()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);  // ������ķ�ʽ���ļ�����׷��д�ļ�

    // ��ÿ���˵�����д�뵽�ļ���
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;

    // �ر��ļ�
    ofs.close();

    cout << "��¼�Ѿ����棡" << endl;

    // �����ļ���¼�ı�־
    this->fileIsEmpty = false;
}

void SpeechManager::load_Record()
{
    ifstream ifs("speech.csv", ios::in);  // �����������ȡ�ļ�

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->fileIsEmpty = true;
        cout << "�ļ�Ϊ�գ�" << endl;
        ifs.close();
        return;
    }

    // �ļ���Ϊ��
    this->fileIsEmpty = false;

    ifs.putback(ch);  // ��ȡ�ĵ����ַ��Ż�ȥ

    string data;
    int index = 0;
    while (ifs >> data)
    {
        vector<string>v;

        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",", start);  // ��0��ʼ����
            if (pos == -1)
            {
                break;  // �Ҳ���break����
            }

            string tmp = data.substr(start, pos - start);  // �Զ��ŷָ��ַ�������һ������Ϊ��ʼλ�ã��ڶ�������Ϊ�ַ�������
            v.push_back(tmp);
            start = pos + 1;
        }

        this->m_Record.insert(pair<int, vector<string>>(index, v));
        index++;

    }
    ifs.close();
}

void SpeechManager::show_Record()
{
    if (this->fileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i++)
        {
            cout << "��" << i + 1 << "��"
                << "�ھ���ţ�" << this->m_Record[i][0] << "\t�÷֣�" << this->m_Record[i][1] << "\t"
                << "�Ǿ���ţ�" << this->m_Record[i][2] << "\t�÷֣�" << this->m_Record[i][3] << "\t"
                << "������ţ�" << this->m_Record[i][4] << "\t�÷֣�" << this->m_Record[i][5] << endl;
        }
    }
    

    system("pause");
    system("cls");
}

void SpeechManager::clear_Record()
{
    cout << "ȷ������ļ���¼��" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // ��ģʽΪios::trunc���������ɾ���ļ������´���
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        // ��ʼ������
        this->init_Speech();

        // ����ѡ��
        this->create_Speaker();

        cout << "����ļ��ɹ���" << endl;

    }
    system("pause");
    system("cls");
}

SpeechManager::~SpeechManager()
{

}