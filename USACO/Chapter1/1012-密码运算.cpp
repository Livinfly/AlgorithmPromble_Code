#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10;

int n, cnt;
int m1, m2;
int r1, r2, r3;
bool st[N];
vector<int> nums;

bool check(int x, int len)
{
    int a = x;
    vector<int> t;
    while(a) t.push_back(a % 10), a /= 10;
    
    if(t.size() != len) return false;
    
    for(int i = 0; i < t.size(); i ++)
        if(!st[t[i]]) return false;
    
    return true;
}
void dfs(int len, int maxn)
{
    if(len == maxn)
    {
        for(int i = 0; i < nums.size(); i ++)
            for(int j = 0; j < nums.size(); j ++)
            {
                m2 = nums[i] * 10 + nums[j];
                
                r1 = nums[j] * m1, r2 = nums[i] * m1, r3 = r1 + r2 * 10;
                if(check(r1, 3) && check(r2, 3) && check(r3, 4))
                {
                    cnt ++;
                }
            }
        return;
    }
    for(int i = 0; i < nums.size(); i ++)
    {
        m1 = m1 * 10 + nums[i];
        dfs(len + 1, maxn);
        m1 = (m1 - nums[i]) / 10;
    }
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) 
	{
	    int a;
	    cin >> a;
	    st[a] = true;
	    nums.push_back(a);
	}
	
	dfs(0, 3);
	
	cout << cnt << endl;
	
	return 0;
}
/*
难得一次就写对的搜索题，思路还算清晰 
*/
