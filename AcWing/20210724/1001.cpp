#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int main()
{
    int T; cin >> T;
	while(T --)
	{
		cin >> n;
		cout << n << endl;
		for(int i = 1; i <= n; i ++)
			cout << i << endl;
	}
    
    return 0;
}
