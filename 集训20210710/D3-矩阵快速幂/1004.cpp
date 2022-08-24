#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 6, P = 123456789;

LL n;
struct Matrix 
{
    LL m[N][N];
} m_init, m_ept;

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix res = m_ept;
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            for(int k = 0; k < N; k ++)
                res.m[i][j] = (res.m[i][j] + ((a.m[i][k] % P) * (b.m[k][j] % P)) % P) % P;
    return res;
}


void init()
{
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            m_ept.m[i][j] = 0;
    m_init = m_ept;
    for(int i = 0; i < N; i ++) m_init.m[i][i] = 1;
}
void work()
{
    Matrix ans, m;
    ans = m = m_ept;
    ans.m[0][0] = 2, ans.m[1][0] = 1, ans.m[2][0] = 27, 
        ans.m[3][0] = 9, ans.m[4][0] = 3, ans.m[5][0] = 1;
    
    m.m[0][0] = 1, m.m[0][1] = 2, m.m[0][2] = 1;
    m.m[1][0] = 1;
    m.m[2][2] = 1, m.m[2][3] = 3, m.m[2][4] = 3, m.m[2][5] = 1;
    m.m[3][3] = 1, m.m[3][4] = 2, m.m[3][5] = 1;
    m.m[4][4] = m.m[4][5] = 1;
    m.m[5][5] = 1;
    
    LL b = n - 1;
    while(b)
    {
        if(b & 1) ans = m * ans;
        m = m * m;
        b >>= 1;
    }
    
    printf("%d\n", ans.m[1][0]);
}

int main()
{
    init();
    int T; cin >> T;
    while(T --)
    {
        cin >> n;
        work();
    }
    
    return 0;
}
