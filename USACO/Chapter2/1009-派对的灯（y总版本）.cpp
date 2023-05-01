#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/*
发现
公理1：按钮的顺序不决定状态。打个例子，12和21得到的状态是相同的。

公理2：同一个按钮按两次等于没按。打个例子，121与2得到的状态是相同的。

公理3：按钮123满足任意两个等于第三个。打个例子，12得到的状态与3是相同的。 

所以所有的状态其实最多就只有8个。 
*/ 
int state[8][6] = {
    {1, 1, 1, 1, 1, 1},  // 无
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
