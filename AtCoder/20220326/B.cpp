#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2010;

int n;
bool st[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i ++) 
  {
    int t;
    cin >> t;
    if(t >= 0) st[t] = true;
  }
  for(int i = 0; i < N; i ++)
  {
    if(!st[i])
    {
      cout << i << endl;
      break;
    }
  }
  
  return 0;
}
