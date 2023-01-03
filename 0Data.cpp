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
  int n = random(100)+1;
  printf("%d\n", n);
  for(int i = 0; i < n; i ++) {
    int a = random(10000000)+1, b = random(10000000)+1;
    if(a > b) swap(a, b);
    if(a == b) b = a+1;
    printf("%d %d\n", a, b);
  }
  
  return 0;
}