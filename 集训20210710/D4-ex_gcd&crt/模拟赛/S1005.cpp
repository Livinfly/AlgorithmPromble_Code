#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long LL;

const int N = 2e6 + 10, INF = 0x3f3f3f3f;

LL n, l, r;
LL k1, k2, p;
LL a[N], s[N];
LL f[N], g[N];

LL xorShift128Plus(){
  LL k3 = k1, k4 = k2;
  k1 = k4;
  k3 ^= (k3 << 23);
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}

void gen(int n){
  for (int i = 1; i <= n; i++) a[i] = xorShift128Plus() % p;
}

int main()
{
	cin >> n >> l >> r >> k1 >> k2 >> p;
	gen(n);
	
	for(int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i];
	
	for(int i = 1; i <= n; i ++)
		for(int j = l; j <= r; j ++)
		{
			if(i < j) break;
			int c = 0;
			if(s[i] - s[i - j] > 0) c = 1;
			else if(s[i] - s[i - j] == 0) c = 0;
			else c = -1; 
			f[i] = max(f[i], f[i - j - 1] + c);
		}
	
	cout << f[n] << endl;
	
	memset(f, 0, sizeof f);
	
	for(int i = 1; i <= n; i ++)
		for(int j = l; j <= r; j ++)
		{
			if(i < j) break;
			int c = 0;
			if(s[i] - s[i - j] > 0) c = 1;
			else if(s[i] - s[i - j] == 0) c = 0;
			else c = -1; 
			f[i] = min(f[i], f[i - j - 1] + c);
		}
	
//	for(int i = 1; i <= n; i ++)
//		cout << s[i] << ' ';
//	cout << endl;
//	for(int i = 1; i <= n; i ++)
//		printf("%d ", f[i]);
//	cout << endl;
	
	cout << -f[n] << endl;
	
	return 0;
}
