#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e3 + 10;

int n, m, res;
struct rec
{
    int cnt, v;
    bool operator < (const rec &o) const
    {
        return v < o.v;
    }
} milks[N];


int main()
{
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i ++)
        scanf("%d%d", &milks[i].v, &milks[i].cnt);
    
    sort(milks, milks + n);
    
    for(int i = 0; i < n; i ++)
    {
        if(m >= milks[i].cnt)
        {
            res += milks[i].v * milks[i].cnt;
            m -= milks[i].cnt;
        }
        else
        {
            res += milks[i].v * m;
            break;
        }
    }
    
    cout << res << endl;
    
    return 0;
}
