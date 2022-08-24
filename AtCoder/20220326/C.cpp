#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 2e5 + 10;

int n, k;
int a[N], b[N];
bool flag = false;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i ++) cin >> a[i];
  for(int i = 1; i <= n; i ++) cin >> b[i];
  bool f1 = true, f2 = true, t1, t2;
  for(int i = 2; i <= n; i ++)
  {
    t1 = f1 && abs(a[i]-a[i-1]) <= k || f2 && abs(a[i]-b[i-1]) <= k;
    t2 = f1 && abs(b[i]-a[i-1]) <= k || f2 && abs(b[i]-b[i-1]) <= k;
    f1 = t1, f2 = t2;
    // cout << f1 << ' ' << f2 << endl;
  }
  if(f1 || f2) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}