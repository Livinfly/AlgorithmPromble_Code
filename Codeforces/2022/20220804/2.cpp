#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int a[N];

void Print_()
{
  for (int i = 1; i <= n; i++)
  {
    cout << a[i];
    if (i == n)
      cout << endl;
    else
      cout << ' ';
  }
}
void work(int n)
{
  cout << n << endl;
  for (int i = 1; i <= n; i++)
    a[i] = i;
  Print_();
  swap(a[1], a[n]);
  Print_();
  for (int i = n; i > 2; i--)
  {
    swap(a[i - 1], a[i]);
    Print_();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n;
    work(n);
  }
  return 0;
}