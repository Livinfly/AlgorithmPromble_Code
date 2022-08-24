#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 15;

int n;
int w[N];
string ss[N];
map<string, int> names;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        string s1;
        cin >> s1;
        ss[i] = s1;
        names[s1] = i;
    }
    for(int i = 1; i <= n; i ++)
    {
        string s1;
        cin >> s1;
        int s = names[s1];
        int sum, cnt;
        cin >> sum >> cnt;
        if(cnt == 0) continue;
        w[s] -= sum;
        w[s] += sum % cnt;
        for(int j = 1; j <= cnt; j ++)
        {
            string s2;
            cin >> s2;
            int t = names[s2];
            w[t] += (int)(sum / cnt);
        }
    }
    
    for(int i = 1; i <= n; i ++)
    {
        cout << ss[i] << ' ' << w[i] << endl;
    }
    
    return 0;
}
