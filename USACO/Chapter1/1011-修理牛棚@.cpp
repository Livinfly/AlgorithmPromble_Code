#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210;

int n, m, sum;
int w[N], d[N];


int main()
{
	cin >> m >> sum >> n;
	for(int i = 0; i < n; i ++) cin >> w[i];
	sort(w, w + n);
	
	for(int i = 0; i < n - 1; i ++) d[i] = w[i + 1] - w[i] - 1;
	
	sort(d, d + n - 1);
	
	int res = n;
	for(int i = 0; i < n - m; i ++)
	{
	    res += d[i];
	}
	
	cout << res << endl;
	
	return 0;
}
/*
我没有证明的贪心 

几个点用一个木板盖掉所需要多花的木板长度
最多只能用m块板，所以最小承受 n - m 个合并的费用
很容易想到选择 n - m个小的费用

然后我好像就证明了？？ 
*/
