#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i ++) cin >> a[i];
  int res = 0;
  for(int i = 1; i <= n; i ++)
  {
    f[i] = 1;
    for(int j = 1; j < i; j ++)
      if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
  res = max(res, f[i]);
  }
  cout << res << endl;
  return 0;
}