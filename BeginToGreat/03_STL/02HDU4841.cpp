#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int n, m, p;
vector<int> man;

void work()
{
	int sum = n<<1;
	for(int i = 0; i < sum; i ++)
		man.push_back(i);
	for(int i = 0; i < n; i ++)
	{
		p = (p+m-1)%man.size();
		man.erase(man.begin()+p);
	}
	for(int i = 0, j = 0; i < sum; i ++)
	{
		if(i && !(i%50)) cout << endl;
		if(j < man.size() && i == man[j]) 
		{
			cout << 'G';
			j ++;	
		}
		else cout << 'B';
	}
	cout << endl << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("a.txt", "r", stdin);
//	freopen("b.txt", "w", stdout);
	while(cin >> n >> m)
	{
		man.clear();
		p = 0;
		work();
	}
	return 0;
}
