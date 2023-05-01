#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL; // !!! 1~12Î»£¡£¡£¡ Î»£¡£¡£¡ 

LL n;
char dic[10][3] = {{}, {}, {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, 
    {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};

int main()
{
	ios::sync_with_stdio(false);
    cin >> n;
    int nums[15], len = 0;
    while(n) nums[len ++] = n % 10, n /= 10;
    
    reverse(nums, nums + len);
    
    bool ok = false;
    string s1;
    while(cin >> s1)
    {
        bool flag = true;
        if(s1.size() != len) continue;
        for(int i = 0; i < len; i ++)
        {
            bool yes = false;
            for(int j = 0; j < 3; j ++)
            {
                if(dic[nums[i]][j] == s1[i]) 
                {
                    yes = true;
                    break;
                }
                // cout << dic[nums[i]][j] << ' ' << s1[i] << endl;
            }
            if(!yes)
            {
                flag = false;
                break;
            }
        }
        if(flag) 
        {
            cout << s1 << endl;
            ok = true;
        }
    }
    
    if(!ok) cout << "NONE" << endl;
    
    return 0;
}
