#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

stack<char> stk;
string ch;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen('a.txt', 'r', stdin);
  // freopen('b.txt', 'w', stdout);
  int T;
  cin >> T;
  getline(cin, ch);
  while (T--)
  {
    getline(cin, ch);
    for (int i = 0; i < ch.size(); i++)
    {
      if (ch[i] == ' ')
      {
        while (stk.size())
        {
          cout << stk.top();
          stk.pop();
        }
        cout << ch[i];
      }
      else
        stk.push(ch[i]);
    }
    while (stk.size())
    {
      cout << stk.top();
      stk.pop();
    }
    cout << endl;
  }

  return 0;
}