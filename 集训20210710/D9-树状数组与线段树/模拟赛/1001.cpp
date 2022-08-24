#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m, sum, cnt, res;
int tmer[N];
bool st[N];
struct rec
{
	int w, c, time, num;
	bool operator <(const rec &o) const
	{
		return w - c > o.w - o.c;
	}
} term[N];

void init()
{
	memset(term, 0, sizeof term);
	memset(st, 0, sizeof st);
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
	{
		init();
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++)
			scanf("%d%d%d%d", &term[i].c, &term[i].w, &term[i].time, &term[i].num);
		
		sort(term + 1, term + n + 1);
		
		scanf("%d%d", &sum, &cnt);
		
		for(int i = 1; i <= cnt; i ++)
		{
			int hh, mm;
			scanf("%2d:%2d", &hh, &mm);
			tmer[i] = hh * 60 + mm;
		}
		
		sort(tmer + 1, tmer + cnt + 1);
		
		res = 0;
		for(int j = 1; j <= n; j ++)
		{
			for(int i = 2; i <= cnt; i ++)
				for(int k = 1; k <= min(cnt, i - 1); k ++)
					if(!st[j] && sum > 0 && tmer[i] - tmer[i - k] >= term[j].time)
					{
						if(sum >= term[j].num) 
						{
							res += term[j].num * (term[j].w - term[j].c);
							sum -= term[j].num;
							st[j] = true;
						}
						else 
						{
							res += sum * (term[j].w - term[j].c);
							sum = 0;
						}
					}
		}
		
		cout << res << endl;
	}
	
	return 0;
}
