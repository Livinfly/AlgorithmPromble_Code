#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int n;
int a[6];
LL f[35][35][35][35][35];

inline void prev_calu()
{
  f[0][0][0][0][0] = 1;
  for(int a1 = 0; a1 <= 30; a1 ++)
    for(int a2 = 0; a2 <= 30; a2 ++)
      for(int a3 = 0; a3 <= 30; a3 ++)
        for(int a4 = 0; a4 <= 30; a4 ++)
          for(int a5 = 0; a5 <= 30; a5 ++)
          {
            LL &t = f[a1][a2][a3][a4][a5];
            if(t == 0) continue;
            if(a1 < 30) f[a1+1][a2][a3][a4][a5] += t;
            if(a2 < a1 && a2 < 30) f[a1][a2+1][a3][a4][a5] += t;
            if(a3 < a2 && a3 < 30) f[a1][a2][a3+1][a4][a5] += t;
            if(a4 < a3 && a4 < 30) f[a1][a2][a3][a4+1][a5] += t;
            if(a5 < a4 && a5 < 30) f[a1][a2][a3][a4][a5+1] += t;
          }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	prev_calu();
	while(cin >> n, n)
	{
	  memset(a, 0, sizeof a);
	  for(int i = 1; i <= n; i ++) cin >> a[i];
	  cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
	}
	return 0;
}
/*
思路

把轮廓作为最优子结构

状态表示:f[][][][][] 第1行排了i个人…的方案数

时间复杂度-O(30^5)
*/