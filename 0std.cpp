#include <stdio.h>
int f[201][20001];  // f[可选物品件数][剩余背包容量]
int max(int a, int b);
int main() {
  int n, i, j, tot = 0;
  int w[201];  //每件物品的价值，大小记得+1,便于数组下标与物品序号一一对应
  w[0] = 0;
  scanf("%d", &n);
  for (i = 1; i < n + 1; i++) {
    scanf("%d", &w[i]);
    tot += w[i];
  }
  for (i = 0; i < n + 1; i++) {
    for (j = 0; j < tot / 2 + 1; j++) {
      f[i][j] = 0;
    }
  }
  for (i = 1; i < n + 1;
       i++) {  //只需讨论一人的拿法：设该循环讨论的是A,总价值A<=B
    if (w[i] > (tot / 2)) {  //若有一物超过总价值一半：把该物给B，其余物品均给A
      f[n][tot / 2] = tot - w[i];
      break;
    }
    for (j = 1; j < tot / 2 + 1; j++) {  // 0-1背包算法
      if (w[i] > j) {
        f[i][j] = f[i - 1][j];
      } else {
        f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + w[i]);
      }
    }
  }
  printf("%d", tot - 2 * f[n][tot / 2]);  // tot-2*f[n][tot/2] ==
                                          // (tot-f[n][tot/2])-f[n][tot/2]
  return 0;
}
int max(int a, int b) {
  int s = a;
  if (b > a) s = b;
  return s;
}