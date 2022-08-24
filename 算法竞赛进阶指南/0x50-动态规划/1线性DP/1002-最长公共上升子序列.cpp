#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 3010;

int n, S;
int a[N], b[N], f[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> b[i];
	for(int i = 1; i <= n; i ++)
	{
	  S = 0; // 清空决策候选集合
	  for(int j = 1; j <= n; j ++)
	  {
	    f[i][j] = f[i-1][j]; // 不选i
	    if(b[j-1] < a[i]) // 更新决策候选集合
	      S = max(S, f[i-1][j-1]+1);
	    if(a[i] == b[j]) // 更新f[][]
	      f[i][j] = max(f[i][j], S);
	  }
	}
  int res = 0;
	for(int i = 1; i <= n; i ++)
	  res = max(res, f[n][i]);
	cout << res << endl;
	return 0;
}
/*
思路
考虑到若寻找当前状态是哪个子序列贡献的(构成最长上升子序列-需要枚举两个上次的结尾位置)时间复杂度太高
因为两个子序列是公共的, 我们考虑只以其中一个作为结尾,优化掉一维

状态表示: f[i][j] 1~i, 1~j可以构成的以b[j]结尾的最长的LCIS的长度

当a[i] == b[j]时, 采取a[i]与b[j]配对的操作不会使状态变差, 枚举比b[j]小的数(此时前面可用的子串为a[1~i-1], b[1~j-1], 找到以b[k]结尾的最长的LCIS, 对a没有限制,所以此时a选择越多越好, 即i-1

O(n3)O(n3) 超时
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N], f[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    b[0] = -(1<<30); // init!!! 或者 开始赋值1
    for(int i = 1; i <= n; i ++)
      for(int j = 1; j <= n; j ++)
        if(a[i] != b[j]) f[i][j] = f[i-1][j];
        else
        {
          for(int k = 0; k < j; k ++)
            if(b[j] > b[k]) f[i][j] = max(f[i][j], f[i-1][k]+1);
        }
  int res = 0;
    for(int i = 1; i <= n; i ++)
      res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
}

优化
我们考虑当我们状态变化时,决策候选集合是怎么变的.

i在最外层属于阶段
j属于状态,阶段以外附加的一个状态
k是决策而不是状态
(在j变化时,i不变)当j这个状态变化时, k的取值范围(k<j&&b[k]<b[j])
决策候选集合 (能够转移的状态的集合?)

j   k   
1   0~0 b[k]<b[1]
2   0~1 b[k]<b[2]
3   0~2 b[k]<b[3]
发现j增大1时, 它的决策候选集合至多增加1
而且这个新的进入的决策就是j-1,
且之前的决策不变.
但是后面的合法性的b[j]变了, 每次的状态中, 他们的决策候选集合不能混用,
采取一次求一类决策候选集合.
决策: 不选a[i]的时候与S无关, 选a[i]的时候, 从状态表示出发那就必然选择b[j]
所以b[j] == a[i], 在更新S的时候用a[i]即可, 即选a[i]的时候选b[j]
决策候选集合中的元素为f[i-1][j-1]+1, 即选a[i],b[j]时前面合法长度的最大值
每个决策候选集合都可以表示为f[i-1][k]+1的形式!!

j   k   
1   0~0 b[k]<a[i]
2   0~1 b[k]<a[i]
3   0~2 b[k]<a[i]
选择一个数据结构(int)维护
维护一个集合S, 支持把一个新的决策j-1插入集合内,
求集合S中下标对应的f[i-1][k]+1值的max

int S;
b[j-1]<a[i] S=max(S, f[i-1][j-1]+1)(k = j-1为新决策)
决策集合的元素只增多不减少的情况像LCIS一样采用维护一个变量来记录决策集合的当前信息.

时间复杂度 O(n2)
(上文代码)
作者：zoler
链接：https://www.acwing.com/activity/content/code/content/1659737/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/