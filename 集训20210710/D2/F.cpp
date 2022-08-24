#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 110;

int m1, m2, K, s;
int w[N], c[N], f[N][N];

int main()
{
    while(scanf("%d%d%d%d", &m1, &m2, &K, &s) == 4)
    {
        memset(f, 0, sizeof f);
        for(int i = 1; i <= K; i ++) scanf("%d%d", &w[i], &c[i]);
        
        for(int k = 1; k <= K; k ++) // class
            for(int i = 0; i <= s; i ++) // kill
                for(int z = 0; z <= i; z ++)
                    for(int j = c[k] * z; j <= m2; j ++)
                        f[i][j] = max(f[i][j], f[i - z][j - c[k] * z] + w[k] * z);
//        for(int i = 0; i <= s; i ++)
//        {
//            for(int j = 0; j <= m2; j ++)
//                printf("%d ", f[i][j]);
//            puts("");
//        }
        int res = f[s][m2], t1;
        if(res >= m1) 
        {
            for(int j = 0; j <= m2; j ++)
                if(f[s][j] >= m1)
                {
                    printf("%d\n", m2 - j);
                    break;
                }
        }
        else puts("-1");
    }
    
    return 0;
}