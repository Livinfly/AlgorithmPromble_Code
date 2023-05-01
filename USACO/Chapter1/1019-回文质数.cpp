#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 7e5 + 10, INF = 1e7;

int cnt, prime[N];
bool vis[INF];
vector<int> nums;

void get_primes()
{
	for(int i = 2; i < INF; i ++)
	{
	    if(!vis[i]) prime[cnt ++] = i;
	    for(int j = 0; prime[j] * i < INF; j ++)
	    {
	        int t = prime[j] * i;
	        vis[t] = true;
	        if(i % prime[j] == 0) break;
	    }
	}
}
bool check(int x)
{
    nums.clear(); // forget
    
	while(x) nums.push_back(x % 10), x /= 10;
	for(int i = 0; i <= nums.size() / 2; i ++)
		if(nums[i] != nums[nums.size() - i - 1]) return false;
	
	return true;
}

int main()
{
	get_primes();
	int a, b;
	scanf("%d%d", &a, &b);
	int l = lower_bound(prime, prime + cnt, a) - prime;
	int r = lower_bound(prime, prime + cnt, b) - prime;
	
	for(int i = l; i <= r; i ++)
		if(check(prime[i])) printf("%d\n", prime[i]);
	
	return 0;
}
/*
1. 结论一，位数为偶数的所有回文数都是11的倍数，即不是质数（1e8 -> 1e7） 
*/
