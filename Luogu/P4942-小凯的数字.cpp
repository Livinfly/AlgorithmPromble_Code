#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL n, l, r, res;

int mod(int x)
{
  return (x%9+9)%9;
}

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
  cin >> n;
  while(n --)
  {
    cin >> l >> r;
    cout << mod((l+r)%9*(r-l+1)%9*5) << endl;
  }
  
  return 0;
}
