#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 710;

int n, res, cnt;
char str[N];


int main()
{
    cin >> n >> str + 1;
    
    for(int i = 1; i <= n; i ++) str[i + n] = str[i];
    
    for(int i = 1; i < n * 2; i ++)
    {
        cnt = 2;
        char ch = '#';
        if(str[i] != 'w' && ch == '#') ch = str[i];
        for(int j = i - 1; j > 0; j --)
        {
            if(str[j] != 'w' && ch == '#') ch = str[i];
            if(str[j] == 'w' || str[j] == ch) cnt ++;
            else break;
        }
        
        ch = '#';
        if(str[i + 1] != 'w' && ch == '#') ch = str[i + 1];
        for(int j = i + 2; j < n * 2; j ++)
        {
            if(str[j] != 'w' && ch == '#') ch = str[j];
            if(str[j] == 'w' || str[j] == ch) cnt ++;
            else break;
        }
        
        res = max(res, cnt);
    }
    
    cout << min(res, n) << endl;
    
    return 0;
}
