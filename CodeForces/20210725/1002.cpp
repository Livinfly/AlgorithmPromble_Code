#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e4 + 10;

int n;
struct rec
{
	int r[5];
	bool operator > (const rec &o) const
	{
		int cnt = 0;
		for(int i = 0; i < 5; i ++)
			if(r[i] < o.r[i]) cnt ++;
		return cnt >= 3;
	}
} ath[N];

void read_data()
{
	cin >> n;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < 5; j ++)
			cin >> ath[i].r[j];
}
void solve()
{
	int gold = 0;
	for(int i = 1; i < n; i ++)
		if(ath[i] > ath[gold]) gold = i;
	for(int i = 0; i < n; i ++)
		if(i != gold && ath[i] > ath[gold]) 
		{
			cout << -1 << endl;
			return;
		}
	cout << gold + 1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while(T --)
	{
		read_data();
		solve();
	}
    
    return 0;
}
