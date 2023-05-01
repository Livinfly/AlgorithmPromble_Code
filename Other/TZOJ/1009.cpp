#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 310;

int n, m;
int f[N][N];
string s1[N], s2[N];

inline void read_data()
{
	cin >> n; 
	getline(cin, s1[0]);
    for(int i = 1; i <= n; i ++)
    	getline(cin, s1[i]);
    cin >> m;
    getline(cin, s2[0]);
    for(int i = 1; i <= m; i ++)
    	getline(cin, s2[i]);
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	read_data();
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(s1[i] == s2[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    
    cout << (n - f[n][m]) + (m - f[n][m]) << endl;
    
    return 0;
}
