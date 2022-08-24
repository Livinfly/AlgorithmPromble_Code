#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 6600;

int tt, stk[20];
int n, cnt;
char dic[3] = {' ', '+', '-'};
string ans[N];

bool check(string s1)
{
    memset(stk, 0, sizeof stk);
	tt = 0;
	stk[0] = -233;
	string t = "";
	for(int i = 0; i < s1.size(); i ++)
	    if(s1[i] != ' ') t += s1[i];
    s1 = t;
    // cout << s1 << endl;
	for(int i = 0; i < s1.size(); i ++)
	{
	    ++ tt;
		if(s1[i] >= '0' && s1[i] <= '9')
		{
			while(s1[i] >= '0' && s1[i] <= '9') 
			{
			    stk[tt] = stk[tt] * 10 + s1[i] - '0';
			    i ++;
			}
			i --; // 1231
		}
		else if(s1[i] == '+') stk[tt] = -1;
		else stk[tt] = -2;
		
		if(tt >= 3 && stk[tt] >= 0)
		{
		    int t1 = stk[tt --], t2 = stk[tt --], t3 = stk[tt --];
		    for(int i = 1; i <= 3; i ++) stk[tt + i] = 0; // 123
    		if(t2 == -1)
    		{
    			stk[++ tt] = t3 + t1;
    		}
    		else
    		{
    			stk[++ tt] = t3 - t1;
    		}
		}
	}
	
// 	cout << stk[tt] << endl;
	
	return stk[tt] == 0;
}
void dfs(int x, string s1) // 0-> ' ' , 1 -> +, 2 -> -
{
	s1 += (char)(x + 48);
// 	cout << s1 << endl;
	if(x == n)
	{
// 		if(s1 == "1-2 3+4+5+6+7") 
		if(check(s1)) ans[cnt ++] = s1;
		return;
	}
	for(int i = 0; i < 3; i ++)
		dfs(x + 1, s1 + dic[i]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	dfs(1, "");
	
	for(int i = 0; i < cnt; i ++)
	    cout << ans[i] << endl;
	
	return 0;
}
