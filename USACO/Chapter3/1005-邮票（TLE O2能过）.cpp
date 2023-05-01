#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

const int N = 2e6 + 10;

int n, s;
int w[N];
bitset<N> f[210]; // choose i can get_state_j

int main()
{
	cin >> s >> n;
	f[0][0] = 1;
	for(int i = 0; i < n; i ++) cin >> w[i];
	for(int i = 0; i < n; i ++)
	    for(int j = 1; j <= s; j ++)
	        f[j] |= f[j - 1] | f[j - 1] << w[i];
	for(int i = 0; i < N; i ++)
	    if(!f[s][i])
	    {
	        cout << i - 1 << endl;
	        return 0;
	    }
	
	return 0;
}
