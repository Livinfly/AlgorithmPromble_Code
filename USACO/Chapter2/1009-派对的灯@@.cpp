#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 110;

int n, c;
int onp[N], oncnt, offp[N], offcnt;
bool st[N];
string start;
map<string, int> S;

inline void read_data()
{
	cin >> n >> c;
	int t;
	oncnt = offcnt = 0;
	while(cin >> t, t != -1) onp[oncnt ++] = t;
	while(cin >> t, t != -1) offp[offcnt ++] = t;
	for(int i = 0; i < n; i ++) start += "1";
}
inline string op(string s, int type)
{
	string t = "";
	if(type == 0) //  op1
	{
		for(int i = 0; i < n; i ++)
			t += (char)('1' - s[i] + '0');
		return t;
	}
	if(type == 1) // op2
	{
		for(int i = 0; i < n; i ++)
			if(i & 1) t += s[i];
			else t += (char)('1' - s[i] + '0');
		return t;
	}
	if(type == 2) // op3
	{
		for(int i = 0; i < n; i ++)
			if(i & 1) t += (char)('1' - s[i] + '0');
			else t += s[i];
		return t;
	}
	// op4
	for(int i = 0; i < n; i ++)
		if(i % 3) t += s[i];
		else t += (char)('1' - s[i] + '0');
	return t;
}
inline void dfs(string state, int depth)
{
	if(depth == c) return;
	static string m[4];
	for(int i = 0; i < 4; i ++) 
	{
		m[i] = op(state, i);
		if(S.count(m[i]) && S[m[i]] == c) continue;
		S[m[i]] = max(S[m[i]], depth + 1);
// 		cout << m[i] << ' ' << S[m[i]] << endl;
		dfs(m[i], depth + 1);
	}
}
inline bool check(string s)
{
    for(int i = 0; i < oncnt; i ++)
        if(s[onp[i] - 1] == '0') return false;
    for(int i = 0; i < offcnt; i ++)
        if(s[offp[i] - 1] == '1') return false;
    return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read_data();
	S[start] = 0;
	dfs(start, 0);
// 	cout << endl;
	bool flag = false;
	for(map<string, int>::iterator it = S.begin(); it != S.end(); it ++)
	{
	    string state = it -> first;
	    int step = it -> second;
	   // cout << state << ' ' << step << endl;
		if(check(state)) 
		{
		    flag = true;
		    cout << state << endl;
		}
	}
	
	if(!flag) cout << "IMPOSSIBLE" << endl;
	
	return 0;
}
/*
过的有点莫名。。 
*/
