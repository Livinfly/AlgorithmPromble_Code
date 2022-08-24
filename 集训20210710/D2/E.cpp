#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10;

int n, m;
int v[N];
double w[N], f[N]; // ±&#187;&#190;ü&#184;&#197;&#194;ê 

int main()
{
    while(cin >> m >> n, n || m)
    {
        for(int i = 0; i <= m; i ++) f[i] = 1;
        for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
        
        for(int i = 1; i <= n; i ++)
            for(int j = m; j >= v[i]; j --)
            {
                f[j] = min(f[j], f[j - v[i]] * (1 - w[i]));
//                printf("f[%d] = %f\n", j, f[j]);
            }
//        for(int i = 0; i <= m; i ++)
//            printf("%.2f ", f[i]);
        
        printf("%.1lf%%\n", (1 - f[m]) * 100);
    }
    
    return 0;
}