## 高精度

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

struct HP
{
  int num[N];
  int len;
}tmp;

inline HP toHP(const string &str)
{
  memset(&tmp, 0, sizeof(HP));
  tmp.len = str.size();
  for(int i = tmp.len-1; i >= 0; i --)
    tmp.num[i] = str[tmp.len-i-1]-'0';
  return tmp;
}
inline int cmpHH(const HP &a, const HP &b)
{
  if(a.len > b.len) return 1;
  else if(a.len < b.len) return -1;
  else
  {
    for(int i = a.len-1; i >= 0; i --)
    {
      if(a.num[i] > b.num[i]) return 1;
      else if(a.num[i] < b.num[i]) return -1;
    }
  }
  return 0;
}
inline HP addHH(const HP &a, const HP &b)
{
  memset(&tmp, 0, sizeof(HP));
  int r = 0, len = max(a.len, b.len);
  for(int i = 0; i < len || r; i ++)
  {
    if(i < len) r += a.num[i]+b.num[i];
    tmp.num[tmp.len ++] = r%10;
    r /= 10;
  }
  return tmp;
}
inline HP subHH(const HP &a, const HP &b, bool &is_posi)
{
  memset(&tmp, 0, sizeof(HP));
  int t = cmpHH(a, b);
  if(t < 0) 
  {
    HP res = subHH(b, a, is_posi);
    is_posi = false;
    return res;
  }
  else is_posi = true;
  
  int r = 0;
  for(int i = 0; i < a.len; i ++)
  {
    r = a.num[i]-r;
    if(i < b.len) r -= b.num[i];
    tmp.num[tmp.len ++] = (r+10)%10;
    if(r < 0) r = 1;
    else r = 0;
  }
  while(tmp.len > 1 && tmp.num[tmp.len-1] == 0) tmp.len --;
  return tmp;
}
inline void Hprint(const HP &a)
{
  for(int i = a.len-1; i >= 0; i --)
    cout << a.num[i];
  cout << endl;
}


int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  HP a = toHP(s1), b = toHP(s2), res;
  bool flag;
  res = subHH(a, b, flag);
  if(!flag) cout << '-';
  Hprint(res);
  return 0;
}
```

## KMP

### 模板

```cpp
// 在s2中s1出现的所有位置（以0下标为开始）
ne[1] = 0;
for (int i = 2; i <= n; i++)
{
    ne[i] = ne[i - 1]; // 此处可用j,理论上效率会更高，但若分两次求ne数组，需要把j初始化为ne[i-1]
    while (ne[i] && s1[ne[i] + 1] != s1[i])
        ne[i] = ne[ne[i]];
    if (s1[ne[i] + 1] == s1[i])
        ne[i]++;
}
for (int i = 1, j = 0; i <= m; i++)
{
    while (j && s1[j + 1] != s2[i])
        j = ne[j];
    if (s1[j + 1] == s2[i])
        j++;
    if (j == n)
    {
        cout << i - 1 << ' ';
        j = ne[j];
    }
}
```

### 优化版

```cpp
// 建立一个ch[i][j]数组，记录离i位置最近的前面（包括i）的j字母的位置
// 每一轮的更新
ne[i] = ch[ne[i - 1]][str[i] - 'a'];
ch[i - 1][str[i] - 'a'] = i;
for (int j = 'a'; j <= 'z'; j++)
{
    if (j == str[i])
        continue;
    ch[i - 1][j - 'a'] = ch[ne[i - 1]][j - 'a'];
}
```

## 字符串哈希

```cpp
// 取模常用值131, 13331; ULL自动溢出取模
const int N = 1e5 + 10, P = 131;

ULL hx[N], p[N];

ULL H(int l, int r) 
{
  return hx[r] - hx[l-1]*p[r-l+1];
}
s = " " + s;
p[0] = 1;
for(int i = 1; i <= n; i ++)
    hx[i] = hx[i-1]*P + s[i], p[i] = p[i-1]*P;
```

## 线性筛素数

```cpp
void get_primes(int x)
{
  for (int i = 2; i <= x; i++)
  {
    if (!st[i])
      prime[cnt++] = i;
    for (int j = 0; prime[j] <= x / i; j++)
    {
      st[prime[j] * i] = true;
      if (i % prime[j] == 0)
        break;
    }
  }
}
```

## 合数分解

```cpp
LL factor[110][2]; // 0存质因子，1存数量
LL getFactors(LL x)
{
    fatCnt = 0;
    LL tmp = x;
    for(int i = 0; prime[i] <= tmp/prime[i]; i ++)
    {
        factor[fatCnt][1] = 0;
        if(tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i];
            while(tmp % prime[i] == 0)
            {
                factor[fatCnt][1] ++;
                tmp /= prime[i];
            }
        }
    }
    if(tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt ++][1] = 1;
    }
    return fatCnt;
}
```

## ex\_gcd及求逆元

```cpp
LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return;
    }
    LL d = ex_gcd(b, a%b, x, y);
    LL t = x;
    x = y, y = t-a/b*y;
    return d;
}
// 逆元
LL inv(LL a, LL p)
{
    LL x, y;
    LL d = ex_gcd(a,p,x,y);
    if(d == 1) return (x%n+n)%n;
    return -1;
}
// 简洁写法 a < p 且 a, p互质
LL inv(LL a, LL p)
{
    if(a == 1) return 1;
    return inv(m%a, m)*(m-m/a)%m;
}
// 欧拉函数
LL inv(LL a, LL p) // p - prime
{
    return qpm(a,p-2,p);
}

```

