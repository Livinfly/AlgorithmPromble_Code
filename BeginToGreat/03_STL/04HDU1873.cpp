#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n;
priority_queue<PII> heap[3];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("i.txt", "r", stdin);
  // freopen("o.txt", "w", stdout);
  while (cin >> n)
  {
    for(int i = 0; i < 3; i ++)
      while(heap[i].size())
        heap[i].pop();
    int id = 0;
    while(n --)
    {
      string op;
      cin >> op;
      if(op == "IN")
      {
        int a, b;
        cin >> a >> b;
        a --;
        heap[a].push({b, --id});
      }
      else
      {
        int a;
        cin >> a;
        a --;
        if(heap[a].empty())
          cout << "EMPTY" << endl;
        else 
        {
          cout << -heap[a].top().second << endl;
          heap[a].pop();
        }
      }
    }
  }
  return 0;
}