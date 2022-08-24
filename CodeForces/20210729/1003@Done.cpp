#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --)
	{
		cin >> n >> m;
		m ++;
		int ans = 0;
		for(int k = 30; k >= 0 && n < m; k --)
			if((n >> k & 1) == 0 && (m >> k & 1)) ans |= 1 << k, n |= 1 << k; 
		cout << ans << endl;
	}
    return 0;
}
/*
a xor b = c <-> a xor c = b
so let's think about find the smallest k -> n ^ k >= m + 1
no existing means that k doesn't exist
to build the smallest k can n ^ k >= m + 1
let p = m + 1
ni == pi -> ki = 0
ni == 1 && pi == 0 -> ki = 0 (the res >= m + 1 && min(k))
ni == 0 && pi == 1 -> ki = 1 (the request is the front i-1 bits' res <= m)
*/ 
