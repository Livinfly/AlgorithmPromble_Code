#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;



int main()
{
  int a;
  cin >> a;
  printf("%02d:%02d\n", 21+a/60, a%60);
  return 0;
}
