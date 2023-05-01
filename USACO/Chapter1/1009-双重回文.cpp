#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n, s, z, cnt;

vector<int> nums;

bool check(int x, int p)
{
    nums.clear();
    while(x) nums.push_back(x % p), x /= p;
    
    for(int i = 0; i <= nums.size() / 2; i ++)
        if(nums[i] != nums[nums.size() - i - 1]) return false;
    return true;
}

int main()
{
    cin >> n >> s;
    z = s + 1;
    while(cnt < n)
    {
        bool is_hui = false, flag = false;
        for(int i = 2; i <= 10; i ++)
        {
            if(flag && check(z, i)) 
            {
                cout << z << endl;
                is_hui = true;
                cnt ++;
                break;
            }
            if(check(z, i)) flag = true;
        }
        z ++;
    }
    
    return 0;
}
