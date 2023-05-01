#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n, res = 1e9;
int h[N];

int get_sq(int x)
{
	return x * x;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> h[i];
	for(int l = 0; l + 17 <= 100; l ++)
	{
		int r = l + 17;
		int t = 0; 
		for(int i = 0; i < n; i ++)
			if(h[i] < l || h[i] > r) // forget!!
				t += min(get_sq(l - h[i]), get_sq(r - h[i]));
		res = min(res, t);
	}
	
	cout << res << endl;
	
	return 0;
}
