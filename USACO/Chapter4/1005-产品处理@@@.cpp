#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1010;

struct rec
{
  int c, finish_time;
  friend bool operator < (const rec &a, const rec &b)
  {
    return a.finish_time > b.finish_time;
  }
};
int n, m1, m2;
int a[N], b[N];

inline void work(int m, int f[])
{
  priority_queue<rec> heap;
  for(int i = 0; i < m; i ++)
  {
    int c;
    cin >> c;
    heap.push((rec) {c, c});
  }
  for(int i = 1; i <= n; i ++)
  {
    rec t = heap.top(); heap.pop();
    f[i] = t.finish_time;
    t.finish_time += t.c;
    heap.push(t);
  }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m1 >> m2;
	work(m1, a);
	work(m2, b);
	int res = 0;
	for(int i = 1; i <= n; i ++)
	  res = max(res, a[i] + b[n-i+1]);
	cout << a[n] << ' ' << res << endl;
	return 0;
}