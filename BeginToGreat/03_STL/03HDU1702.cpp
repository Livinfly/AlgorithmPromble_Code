#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int n;
string str;
queue<int> q;
stack<int> stk;

void FIFO_calc()
{
  while (q.size())
    q.pop();
  while (n--)
  {
    string op;
    int x;
    cin >> op;
    if (op == "IN")
    {
      cin >> x;
      q.push(x);
    }
    else if (q.size())
    {
      cout << q.front() << endl;
      q.pop();
    }
    else
      cout << "None" << endl;
  }
}
void FILO_calc()
{
  while (stk.size())
    stk.pop();
  while (n--)
  {
    string op;
    int x;
    cin >> op;
    if (op == "IN")
    {
      cin >> x;
      stk.push(x);
    }
    else if (stk.size())
    {
      cout << stk.top() << endl;
      stk.pop();
    }
    else
      cout << "None" << endl;
  }
}
void work()
{
  n = -1;
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
    cin >> n >> str;
    if (str == "FIFO")
      FIFO_calc();
    else
      FILO_calc();
  }

  return 0;
}