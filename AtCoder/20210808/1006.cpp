#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int n;
string s1, s2;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s1;
	s2 = s1 = " " + s1;
	for(int i = 1; i <= n; i ++)
	{
		string t1 = s1.substr(i);
		for(int j = 1; j <= n; j ++)
		{
			string t2 = s2.substr(j);
			
		}
	}
	
    return 0;
}
