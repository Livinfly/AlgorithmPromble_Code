#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 15;

int n;
char g[N][N], ans[N][N], t[N][N];

bool check()
{
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            if(t[i][j] != ans[i][j]) return false;
    return true;
}
void op1()
{
    static char c[N][N];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            c[j][n - i - 1] = t[i][j];
    memcpy(t, c, sizeof c);
}
void op4()
{
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n / 2; j ++)
            swap(t[i][j], t[i][n - j - 1]);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> g[i];
    for(int i = 0; i < n; i ++) cin >> ans[i];
    
    memcpy(t, g, sizeof t);
    
    op1();
    if(check()) 
    {
        cout << 1 << endl;
        return 0;
    }
    op1();
    if(check()) 
    {
        cout << 2 << endl;
        return 0;
    }
    op1();
    if(check()) 
    {
        cout << 3 << endl;
        return 0;
    }
    memcpy(t, g, sizeof t);
    op4();
    if(check()) 
    {
        cout << 4 << endl;
        return 0;
    }
    op1();
    if(check()) 
    {
        cout << 5 << endl;
        return 0;
    }
    op1();
    if(check()) 
    {
        cout << 5 << endl;
        return 0;
    }
    op1();
    if(check()) 
    {
        cout << 5 << endl;
        return 0;
    }
    
    memcpy(t, g, sizeof t);
    if(check())
    {
        cout << 6 << endl;
        return 0;
    }
    
    cout << 7 << endl;
    
    return 0;
}
