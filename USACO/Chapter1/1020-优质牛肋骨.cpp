#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10;

int n, t;
int nums[N];

bool check(int x)
{
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i ++)
		if(x % i == 0) return false;
	return true;
}
void dfs(int x)
{
	if(x == n - 1)
	{
		for(int i = 1; i <= 9; i += 2)
		{
			t = t * 10 + i;
			if(check(t)) printf("%d\n", t);
			t /= 10;
		}
		return;
	}
	for(int i = 1; i <= 9; i ++) // 可证有0无解 
	{
		t = t * 10 + i;
		if(check(t)) dfs(x + 1);
		t /= 10;
	} 
}

int main()
{
	cin >> n;
	
	dfs(0);
	
	return 0;
}
