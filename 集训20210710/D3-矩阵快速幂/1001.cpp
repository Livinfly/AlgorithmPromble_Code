#include iostream
#include algorithm
#include cstdio
#include cstring

using namespace std;

const int N = 11, P = 9973;

int n, K;
struct Matrix
{
    int m[N][N];
} a, m_init;
Matrix operator  (const Matrix &a, const Matrix &b)
{
    Matrix res;
    int t;
    for(int i = 0; i  n; i ++)
        for(int j = 0; j  n; j ++)
        {
            t = 0;
            for(int k = 0; k  n; k ++)
                t = (t + a.m[i][k]  b.m[k][j]) % P;
            res.m[i][j] = t;
        }
    return res;
}
int qpm(Matrix a, int b)
{
    Matrix ans = m_init;
    while(b)
    {
        if(b & 1) ans = ans  a;
        a = a  a;
        b = 1;
    }
    int res = 0;
    for(int i = 0; i  n; i ++)
        res += ans.m[i][i];
    return res % P;
}

int main()
{
    for(int i = 0; i  N; i ++)
        m_init.m[i][i] = 1;
    int T; cin  T;
    while(T --)
    {
        cin  n  K;
        for(int i = 0; i  n; i ++)
            for(int j = 0; j  n; j ++)
                cin  a.m[i][j];
        cout  qpm(a, K)  endl;
    }
    
    return 0;
}