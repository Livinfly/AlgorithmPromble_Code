#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/*
����
����1����ť��˳�򲻾���״̬��������ӣ�12��21�õ���״̬����ͬ�ġ�

����2��ͬһ����ť�����ε���û����������ӣ�121��2�õ���״̬����ͬ�ġ�

����3����ť123���������������ڵ�������������ӣ�12�õ���״̬��3����ͬ�ġ� 

�������е�״̬��ʵ����ֻ��8���� 
*/ 
int state[8][6] = {
    {1, 1, 1, 1, 1, 1},  // ��
    {0, 0, 0, 0, 0, 0},  // 1
    {0, 1, 0, 1, 0, 1},  // 2
    {1, 0, 1, 0, 1, 0},  // 3
    {0, 1, 1, 0, 1, 1},  // 4
    {1, 0, 0, 1, 0, 0},  // 14
    {1, 1, 0, 0, 0, 1},  // 24
    {0, 0, 1, 1, 1, 0},  // 34
};

int n, c;
vector<int> on, off;

bool check(int s[6])
{
    for (auto id: on)
        if (!s[id % 6])
            return false;
    for (auto id: off)
        if (s[id % 6])
            return false;
    return true;
}

void work(vector<int> ids)
{
    sort(ids.begin(), ids.end(),[](int a, int b){
        for (int i = 0; i < 6; i ++ )
            if (state[a][i] != state[b][i])
                return state[a][i] < state[b][i];
        return false;
    });

    bool has_print = false;
    for (auto id: ids)
    {
        auto s = state[id];
        if (check(s))
        {
            has_print = true;
            for (int i = 0; i < n; i ++ )
                cout << s[i % 6];
            cout << endl;
        }
    }
    if (!has_print) puts("IMPOSSIBLE");
}

int main()
{
    cin >> n >> c;
    int id;
    while (cin >> id, id != -1) on.push_back(id - 1);
    while (cin >> id, id != -1) off.push_back(id - 1);

    if (!c) work({0});
    else if (c == 1) work({1, 2, 3, 4});
    else if (c == 2) work({0, 1, 2, 3, 5, 6, 7});
    else work({0, 1, 2, 3, 4, 5, 6, 7});

    return 0;
}
