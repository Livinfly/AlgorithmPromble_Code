#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int a[N], s[N];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	int cnt = 0;
	for(int i = 1; i + 1 <= n; i ++) // s[n] - s[n] == 0
	    if(s[i] == s[n] - s[i]) cnt ++;
    cout << cnt << endl;
    
    return 0;
}
