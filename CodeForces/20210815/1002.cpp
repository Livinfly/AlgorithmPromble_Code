#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n, A, Z;
char str[N], dic[2] = {'B', 'R'}; // 0->B, 1->R

int main()
{
  ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
  while(T --)
  {
    cin >> n;
    cin >> str + 1;
    for(int i = 1; i <= n; i ++)
    {
        while(str[i] != '?' && i <= n) i ++;
        A = i;
        while(str[i] == '?' && i <= n) i ++;
        Z = i - 1;
        if(Z == n) 
        {
          for(int j = A, k = str[A-1]=='B'; j <= Z; j ++, k = 1-k)
            str[j] = dic[k];
        }
        else
        {
          for(int j = Z, k = (str[i]=='B'); j >= A; j --, k = 1-k)
            str[j] = dic[k];
        }
        // cout << A << ' ' << Z << endl;
    }
    cout << str + 1 << endl;
  }
    
  return 0;
}
