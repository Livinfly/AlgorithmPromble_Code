#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 125010;

int n, m, a, b;
bool st[N];
vector<int> nums;
vector<PII> ans;

int main()
{
	cin >> n >> m;
	for(int i = 0; i <= m; i ++)
		for(int j = 0; j <= m; j ++)
		{
			int t = i * i + j * j;
			if(!st[t])
			{
				nums.push_back(i * i + j * j);
				st[t] = true;
			}
		}
	
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i ++) // a
	{
		int a = nums[i];
		for(b = 1; a + b * (n - 1) <= 2 * m * m && b <= m * m; b ++) // b
		{
			bool flag = true;
			for(int k = 0; k < n; k ++) // n
			{
				int t = a + k * b;
				if(!st[t]) 
				{
					flag = false;
					break;
				}
			}
			if(flag) ans.push_back(make_pair(b, a));
		}
	}
	
	if(ans.size() == 0) puts("NONE");
	else
	{
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i ++)
			printf("%d %d\n", ans[i].y, ans[i].x);
	}
	
	
	return 0;
}
