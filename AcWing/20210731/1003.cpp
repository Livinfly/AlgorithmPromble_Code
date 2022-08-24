#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL s[N], f[26][26];
string str;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> str;
	LL res = 0;
	for(int i = 0; str[i]; i ++)
    {
    	int t = str[i] - 'a';
    	for(int j = 0; j < 26; j ++)
    	{
    		f[j][t] += s[j];
    		res = max(res, f[j][t]);
		}
		s[t] ++;;
		res = max(res, s[t]); // single one
	}
    
    cout << res << endl;
    
    return 0;
}
