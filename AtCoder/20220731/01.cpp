#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = n;; i++)
		if (i % 4 == 2)
		{
			cout << i << endl;
			return 0;
		}
	return 0;
}