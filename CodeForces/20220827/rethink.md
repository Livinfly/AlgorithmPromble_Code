## 闲言

好几天没打cf且没有打vp了qwq

这次个人感觉AB两题过得比之前快，C WA了一发，过了；D WA两发，没过。就润去睡觉了。

后续题解先咕一会儿。

`代码附在后面`

## A

容易分析出题中的情况有1~4个字母（不同的）

1. 1个，答案显然为0。
2. 2个，一次最多能涂两个相同颜色的，所以答案显然为1。
3. 3个，此时有一种字母有两个，分为两个相邻与两个相隔的情况，可以发现都只需要一步可以变为有三个相邻的状态，答案为2。
4. 4个，只能一个一个变，答案为3。

我在实现代码稍微麻烦了点，jls就是直接set，SSRS_是分类了，但不是完全无脑分类，通过第一个和第二个的cnt来分类。（对于stl还是不熟练QnQ）

## B

题意：求十字移动，有一片障碍的前提，从(1, 1)到(n, m)的最小步数。

因为求的是最小步数，我们只先考虑向下或向右的走法。

因为它只有一片是障碍，我们不难分析出，障碍只会严重影响一边的通行（靠左下的路线与靠右上的路线）。

容易发现，若靠左下的路线可以过的话，贴着左下边缘过的方式是绝对可以过得。同理可得靠右上的路线可过的话，贴着右上边缘过的方式亦可以过。

因为，障碍是以一个点为中心的范围。如果，边缘的走法可以过，那最小步数就为 `n+m-2`，否则若两边都不能过，容易想象出这是终点与起点被隔断的情况，即无解，也没有必要去分析其他的走法。

## C

题意：有a,b,d两个序列，通过ai+di的方式得到bi，再 `将bi排序`得到我们输入的bi序列，求每个 `个体 `di的 `可能的`最大和最小值。

简单分析题意后，得知，我们需要找到每个ai可能匹配上（加上di后相等）的bj，di的最大最小值就是bj-ai的最大最小值。

1. bj >= ai
2. bj要是ai可以选择的。这里的可以选择是指，它没有被某一个ai，或者某一块a(l~r)绑定。（我WA1发交在这里了QnQ）

关于第二点，我举一个例子

```
10 25 30 40
22 33 33 55
```

我们不难发现，a40只能和b55匹配，如果前面的某个数和b55匹配，a40将无法匹配，是不合法的。

所以，a30只能与两个b33匹配，而a25只能和另一个b33匹配。

所以这一块就绑定死了，a10无法尝试与这些绑定一起的匹配。

（因为题中样例只能看出一个会绑定，而一堆会绑定我把原题样例的a20改成a25。）

在代码实现上，因为a，b都是非递减序列，我们需要统计的大于ai的bj就是连续的，可以采用多指针的方式，线性求解。


补充jls的做法，最大值最小值分开处理。

1. 最小值就是能匹配的最小的值。
2. 最大值就是在满足a[j+1] <= b[j]前的bj与ai的最大值。（这个条件就概括掉我前面这个绑定起来的问题，tql）因为a[j+1]>b[j]的话，a[j+1]就只能在j+1之后的b中匹配。

## CODE

### A

```cpp
#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200;

bool vis[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    char ch[3];
    cin >> ch;
    for (int i = 0; i < 2; i++)
      if (!vis[ch[i]])
      {
        vis[ch[i]] = true;
        cnt++;
      }
    cin >> ch;
    for (int i = 0; i < 2; i++)
      if (!vis[ch[i]])
      {
        vis[ch[i]] = true;
        cnt++;
      }
    cout << cnt - 1 << '\n';
  }
  return 0;
}
```

### B

```cpp
#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    if (sx + d < n && sy - d > 1 || sx - d > 1 && sy + d < m)
      cout << n + m - 2 << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
```

### C

```cpp
#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  int T;
  cin >> T; // scanf("%d", &T);
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), d1(n + 1), d2(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    for (int i = n, l = n - 1, r = n; i > 0; i--)
    {
      while (l && b[l] >= a[i])
        l--;
      d1[i] = b[l + 1] - a[i], d2[i] = b[r] - a[i];
      if (l + 1 == i)
        r = l;
    }
    for (int i = 1; i <= n; i++)
      cout << d1[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++)
      cout << d2[i] << " \n"[i == n];
  }
  return 0;
}
```
