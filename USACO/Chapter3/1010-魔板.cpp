#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

string aim;
string m[3];
map<string, int> dist;
map<string, string> ans;

inline string op(string s, int type)
{
    if(type == 0)
    {
        for(int i = 0; i < 4; i ++) swap(s[i], s[i + 4]);
    }
    else if(type == 1)
    {
        char t1 = s[3], t2 = s[7];
        for(int i = 3; i; i --) s[i] = s[i - 1], s[i + 4] = s[i + 4 - 1];
        s[0] = t1, s[4] = t2;
    }
    else
    {
        swap(s[1], s[2]), swap(s[1], s[6]), swap(s[1], s[5]);
    }
    return s;
}
inline void bfs()
{
    queue<string> q;
    q.push("12348765");
    dist["12348765"] = 0, ans["12348765"] = "";
    while(q.size())
    {
        string t = q.front(); q.pop();
        if(t == aim) 
        {
            cout << dist[t] << endl;
            if(dist[t]) cout << ans[t] << endl; // none - format
            return;
        }
        for(int i = 0; i < 3; i ++)
        {
            m[i] = op(t, i);
            if(dist.count(m[i]) == 0) 
            {
                ans[m[i]] = ans[t] + (char)('A' + i);
                dist[m[i]] = dist[t] + 1;
                q.push(m[i]);
            }
        }
    }
    return;
}

int main()
{
	for(int i = 0; i < 4; i ++) 
	{
	    int a;
	    cin >> a;
	    aim += (char)(a + '0');
	}
	string t = "";
	for(int i = 7; i >= 4; i --)
	{
	    int a;
	    cin >> a;
	    t = (char)(a + '0') + t;
	}
	aim += t;
	bfs();
	return 0;
}
