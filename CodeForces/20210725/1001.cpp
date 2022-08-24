#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 55;

int n;
char str[N], s1[N];


int main()
{
    ios::sync_with_stdio(0); 
    int T; cin >> T;
    while(T --)
    {
    	cin >> n >> str + 1;
    	int res = n;
    	memcpy(s1, str, sizeof s1);
    	sort(s1 + 1, s1 + n + 1);
    	for(int i = 1; i <= n; i ++)
    		if(str[i] == s1[i]) res --;
    	cout << res << endl;
	}
    
    return 0;
}
