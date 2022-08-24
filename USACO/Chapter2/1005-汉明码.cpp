#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1 << 8;

int n, b, d, maxn;
int ones[N];
vector<int> ans;

inline void prev_calu()
{
	for(int i = 0; i < N; i ++)
		ones[i] = ones[i >> 1] + (i & 1);
}
inline bool check(int x)
{
	for(int i = 0; i < ans.size(); i ++)
		if(ones[ans[i] ^ x] < d) return false;
	return true;
}
inline bool dfs(int x)
{
	if(ans.size() == n) return true;
	
	for(int i = x; i < maxn; i ++)
	{
		if(check(i)) 
		{
			ans.push_back(i);
			if(dfs(i + 1)) return true;
			ans.pop_back();
		}
	}
	return false;
}

int main()
{
	cin >> n >> b >> d;
	maxn = 1 << b;
	
	for(int i = 0; i < d; i ++)
		if(dfs(i)) break;
	
	for(int i = 0; i < ans.size(); i ++)
	{
		cout << ans[i] << ' ';
		if(i % 10 == 9) cout << endl;
	}
	
	return 0;
}
/*
就爆搜
不要不敢写，分析下时间复杂度即可
2^8 * 64 (* 8) 其实0一定在里面 
主要要知道“汉明距离”是 两个数xor后的二进制数的1的个数 
*/
