#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int a[5], ans[5];
LL sum;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i = 0; i < 4; i ++)
	{
	    cin >> a[i];
	    sum += a[i];
	}
	sum /= 3;
	for(int i = 0; i < 4; i ++)
	    ans[i] = sum - a[i];
	sort(ans, ans + 4);
	for(int i = 1; i < 4; i ++)
	    cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
