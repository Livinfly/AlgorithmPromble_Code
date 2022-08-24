#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
int a[N]; 

int main()
{
	ios::sync_with_stdio(false);
	while(cin >> n >> m)
	{
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; i ++)
			a[i] = i;
		int i = 0;
		do
		{
			i ++;
		} while(next_permutation(a + 1, a + n + 1) && i < m - 1);
		cout << a[1];
		for(int i = 2; i <= n; i ++)
			cout << ' ' << a[i];
		cout << endl;
	}
	
	
	
	return 0;
}
