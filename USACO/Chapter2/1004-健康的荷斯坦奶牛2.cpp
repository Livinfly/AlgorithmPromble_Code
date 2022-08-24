#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 30;

int n, m, maxn;
int cow[N];
vector<int> t, ans;

struct rec
{
	int vit[N];
} feeds[17];

inline bool check()
{
	static int sum[N];
	memset(sum, 0, sizeof sum);
	for(int i = 0; i < t.size(); i ++)
		for(int j = 0; j < n; j ++)
			sum[j] += feeds[t[i]].vit[j];
	for(int i = 0; i < n; i ++)
		if(sum[i] < cow[i]) return false;
	return true;
}
inline void dfs(int x) // �����Ĵ𰸴��ֵ����ĵ�С������ֻ�е��´𰸵ĳ���Сʱ����
{
	if(x >= m) 
	{
		if((ans.size() == 0 || ans.size() > t.size()) && check()) ans = t;
		return;
	}
	
	//ѡ
	t.push_back(x);
	dfs(x + 1);
	t.pop_back();
	//��ѡ 
	dfs(x + 1);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> cow[i];
	cin >> m;
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j ++)
			cin >> feeds[i].vit[j];
	
	dfs(0);
	
	cout << ans.size() << ' ';
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i] + 1 << ' ';
	cout << endl;
	
	return 0;
}

