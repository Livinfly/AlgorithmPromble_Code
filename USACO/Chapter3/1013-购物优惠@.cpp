#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n, idx;
int m[10], id[1010], f[6][6][6][6][6];
bool st[1010];
struct rec
{
    int c;
    int id[10];
    int w[10];
} goods[N];

inline void init()
{
    memset(f, 0x3f, sizeof f);
    f[0][0][0][0][0] = 0;
}
inline void read_data()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int n1;
        cin >> n1;
        for(int j = 0; j < n1; j ++)
        {
            int idd;
            cin >> idd;
            if(!st[idd])
            {
                id[idd] = idx ++; // use idx ++, cuz idx [0, ...]
                st[idd] = true;
            }
            cin >> goods[i].w[id[idd]];
        }
        cin >> goods[i].c;
    }
    int t;
    cin >> t;
    for(int i = n; i < n + t; i ++)
    {
        int a, b;
        cin >> a >> b >> goods[i].c;
        if(!st[a])
        {
            id[a] = idx ++;
            st[a] = true;
        }
        goods[i].id[0] = a;
        goods[i].w[id[a]] = 1;
        m[id[a]] = b;
    }
    n += t;
}
inline void solve()
{
    // for(int i = 0; i < n; i ++)
    // {
    //     cout << i << ' ';
    //     for(int j = 0; j < 5; j ++)
    //         cout << goods[i].w[j] << ' ';
    //     cout << endl;
    // }
    for(int i = 0; i < n; i ++)
        for(int j0 = goods[i].w[0]; j0 <= m[0]; j0 ++)
            for(int j1 = goods[i].w[1]; j1 <= m[1]; j1 ++)
                for(int j2 = goods[i].w[2]; j2 <= m[2]; j2 ++)
                    for(int j3 = goods[i].w[3]; j3 <= m[3]; j3 ++)
                        for(int j4 = goods[i].w[4]; j4 <= m[4]; j4 ++)
	f[j0][j1][j2][j3][j4] = min(f[j0][j1][j2][j3][j4], f[j0 - goods[i].w[0]][j1 - goods[i].w[1]][j2 - goods[i].w[2]][j3 - goods[i].w[3]][j4 - goods[i].w[4]] + goods[i].c);
    
    cout << f[m[0]][m[1]][m[2]][m[3]][m[4]] << endl;
    return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	read_data();
	solve();
	return 0;
}
