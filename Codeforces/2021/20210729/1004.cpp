#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

string res;
int n;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --)
	{
		res = "";
		cin >> n;
		if(n == 1) // Runtime Error
		{
			cout << 'a' << endl;
			continue;
		}
		res.append(n >> 1, 'a');
		res.append("b");
		res.append((n >> 1) - 1, 'a');
		if(n & 1) res.append("c");
		cout << res << endl;
	}
    
    return 0;
}
/*
even : aaaaabaaaa -> 10
odd : aaaaabaaaac
*/
