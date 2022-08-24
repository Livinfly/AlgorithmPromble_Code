#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 10, M = 210;

int n, m;
bool f[N]; // i as end is_ok
string dic[M], str, t;

int main()
{
	while(cin >> dic[++ n], dic[n] != ".");
	n --;
	while(cin >> t) str += t;
	m = str.size();
	str = ' ' + str;
	f[0] = true;
	for(int i = 1; i <= m; i ++)
	    for(int j = 1; j <= n; j ++)
	    {
	        if(!f[i] && dic[j].size() <= i && str.substr(i - dic[j].size() + 1, dic[j].size()) == dic[j])
	            f[i] |= f[i - dic[j].size()];
	    }
	for(int i = m; i >= 0; i --)
	    if(f[i] || !i)
	    {
	        cout << i << endl;
	        break;
	    }
	return 0;
}
