#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 6;

int n, P;
struct Matrix
{
    int m[N][N];
} m, m_init, m_ept;

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix res;
    int t;
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
        {
            t = 0;
            for(int k = 0; k < N; k ++)
                t = (t + a.m[i][k] * b.m[k][j]) % P;
            res.m[i][j] = t;
        }
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
    Matrix ans;
    ans = m_ept;
    ans.m[0][0] = 6, ans.m[1][0] = 4, ans.m[2][0] = 2, ans.m[3][0] = 1;
    
    m = m_ept;
    m.m[0][0] = m.m[0][2] = m.m[0][3] = 1, m.m[0][1] = 0;
    for(int i = 1; i < N; i ++) m.m[i][i - 1] = 1;
    
    while(n)
    {
        if(n & 1) ans = m * ans;
        m = m * m;
        n >>= 1;
    }
    
    cout << ans.m[3][0] << endl;
}

int main()
{
    init();
    while(cin >> n >> P) work();
    
    return 0;
}