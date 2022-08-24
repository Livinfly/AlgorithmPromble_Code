#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;



int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int t = (a-c)*60+b-d;
  if(t <= 0) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
