#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 200;
const double eps = 1e-6;
 
int n, cnt;
struct rec
{
	int a, b;
	double val;
	bool operator < (const rec &o) const
	{
		return val + eps < o.val;
	}
} nums[N * N];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void dfs(int a, int b)
{
	if(a > b || a >= n || b > n || gcd(a, b) != 1) return;
	nums[cnt ++] = (rec){a, b, 1.0 * a / b};
	
	dfs(a + 1, b);
	dfs(a, b + 1);
}



int main()
{
	scanf("%d", &n);
	
// 	dfs(0, 1);
    for(int a = 0; a <= n; a ++)
        for(int b = 1; b <= n; b ++)
        {
            if(a > b || a > n || b > n || gcd(a, b) != 1) continue; // a > n, no >= , n = 1 wrong 
	        nums[cnt ++] = (rec){a, b, 1.0 * a / b};
        }
	
	sort(nums, nums + cnt);
	for(int i = 0; i < cnt; i ++)
		printf("%d/%d\n", nums[i].a, nums[i].b);
	
	return 0;
}
/*
暴力枚举出所有的分子和分母
化为最简分数，判重
用结构体存储，排序
xxxxxxxx
暴力枚举出所有的分子和分母
互质判最简分数
用结构体存储，排序 
*/
