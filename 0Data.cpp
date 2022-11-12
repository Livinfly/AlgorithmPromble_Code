#include <bits/stdc++.h>

#include <ctime>

using namespace std;

typedef long long LL;

int random(int x) {  // 获取 0~x-1 中间的一个随机数
  if (!x) return 0;
  return (LL)rand() * rand() % x;
}

int main() {
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  srand(time(0));
  int n = random(199) + 1;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    cout << random(199) + 1 << ' ';
  }
  cout << '\n';
  return 0;
}