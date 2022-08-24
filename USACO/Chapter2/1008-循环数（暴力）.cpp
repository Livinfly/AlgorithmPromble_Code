#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 1e7;

int n;
bool st[8];
vector<int> nums;

bool check(int x)
{
	memset(st, 0, sizeof st);
	nums.clear();
	while(x) nums.push_back(x % 10), x /= 10; // 0~len-1 低位到高位 
	reverse(nums.begin(), nums.end());
	int len = nums.size(), p;
	for(int i = 0; i < len; i ++)
		for(int j = i + 1; j < len; j ++)
			if(nums[i] == nums[j]) return false;
	p = 0;
	while(!st[p])
	{
		st[p] = true;
		p = (p + nums[p]) % len;
	}
	if(p) return false;
	for(int i = 0; i < len; i ++)
		if(!st[i]) return false;
	return true;
}

int main()
{
	cin >> n;
	for(int i = n + 1; i <= INF; i ++)
		if(check(i))
		{
			cout << i << endl;
			return 0;
		}
	
	return 0;
}
