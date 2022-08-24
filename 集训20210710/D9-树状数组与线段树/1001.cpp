#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e4 + 10;

int n;
int w[N], tr[N];

int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
{
	for(; x < N; x += lowbit(x)) tr[x] += c;
}
int query(int x)
{
	int res = 0;
	for(; x; x -= lowbit(x)) res += tr[x];
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("data1.txt", "r", stdin);
	int T; cin >> T;
	for(int C = 1; C <= T; C ++)
	{
		memset(tr, 0, sizeof tr);
		cout << "Case " << C << ":" << endl;
		cin >> n;
		for(int i = 1; i <= n; i ++) 
		{
			cin >> w[i];
			add(i, w[i]);
		}
		
		int a, b;
		string op;
		while(cin >> op, op != "End")
		{
			cin >> a >> b;
			if(op == "Add")
			{
				add(a, b);
			}
			else if(op == "Sub")
			{
				add(a, -b);
			}
			else
			{
				cout << query(b) - query(a - 1) << endl;
			}
		}
		
		
		
	}
	
	return 0;
}
