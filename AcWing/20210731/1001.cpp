#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		cout << (b - a % b) % b << endl;
	}
	return 0;
}
