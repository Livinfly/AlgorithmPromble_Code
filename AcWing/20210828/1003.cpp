#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e6 + 10, P = 131;

ULL hx[N], p_base[N];
int len;
string str;

inline void prev_calu()
{
  p_base[0] = 1;
  for(int i = 1; i < N; i ++) p_base[i] = p_base[i-1] * P;
}
inline ULL H(int l, int r)
{
  return hx[r]-hx[l-1]*p_base[r-l+1];
}
inline bool check(int mid)
{
  // if(mid == 6) 
  // {
  //   cout << "YES" << endl;
  //   cout << 1 << ' ' << mid << endl;
  //   cout << len-mid+1 << ' ' << len << endl;
  //   cout << H(1, mid) << ' ' << H(len-mid+1, len) << endl;
  // }
  if(H(1, mid) != H(len-mid+1, len)) return false; // 前后没有
  // if(mid == 6) cout << "YES" << endl;
  // 寻找中间
  ULL aim = H(1, mid);
  for(int i = 2; i < len-mid+1; i ++)
    if(H(i, i+mid-1) == aim) return true;
  return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	prev_calu();
  int T; cin >> T;
  while(T --)
  {
    cin >> str;
    len = str.size();
    str = " " + str;
    for(int i = 1; i <= len; i ++)
      hx[i] = hx[i-1]*P+str[i]-'a'+1;
    int l = 1, r = len, ans = 0;
    for(int i = len-2; i > 0; i --)
      if(check(i)) 
      {
        ans = i;
        break;
      }
    if(ans) cout << str.substr(1, ans) << endl;
    else cout << "not exist" << endl;
  }
	return 0;
}