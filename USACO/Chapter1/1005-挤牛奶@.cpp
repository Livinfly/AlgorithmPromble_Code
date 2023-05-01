#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5010;

int n;
struct rec
{
    int l, r;
    bool operator < (const rec &o)const
    {
        return l < o.l;
    }
} seg[N];


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> seg[i].l >> seg[i].r;
    
    seg[0] = (rec){0, 0};
    sort(seg + 1, seg + n + 1);
    
    int ans1 = 0, ans2 = 0, l = seg[1].l, r = seg[1].r;
    for(int i = 2; i <= n; i ++)
    {
        if(seg[i].l <= r) r = max(r, seg[i].r);
        else
        {
            ans1 = max(ans1, r - l);
            ans2 = max(ans2, seg[i].l - r);
            l = seg[i].l, r = seg[i].r;
        }
    }
    
    ans1 = max(ans1, r - l);
    
    cout << ans1 << ' ' << ans2 << endl;
    
    
    return 0;
}
/*
1. 连续时间段最长长度 
2. 没有人挤奶的时间段的最长长度

之前AC过，现在并不太会，需要重做吧。。。 
*/
