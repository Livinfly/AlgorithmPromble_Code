#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 1010;

int n, depth;
int nums[N];

bool dfs(int u, int ans)
{
	nums[u] = ans;
	if(ans <= 0) return false;
  if (u == depth)
    return ans == n;
  if (u > 0)
  {
    int maxn = ans;
    for (int i = 0; i < depth - u; i++)
    {
    	if(maxn >= n) break;
    	maxn *= 2;
		}
    if (maxn < n)
      return false;
  }
  for (int i = u; i >= 0; i--)
  {
    int t = ans + nums[i];
    if (dfs(u + 1, t))
    	return true;
    t = ans - nums[i];
    if (dfs(u + 1, t))
    	return true; 
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
//  freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n, n)
  {
    depth = 0;
    while (!dfs(0, 1))
    	depth++;
    cout << depth << endl;
  }
  return 0;
}
