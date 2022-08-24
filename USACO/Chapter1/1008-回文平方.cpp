#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 310;

int n;
vector<int> nums, n2;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= 300; i ++)
    {
        n2.clear(), nums.clear();
        int t = i * i;
        bool flag = true;
        
        while(t) nums.push_back(t % n), t /= n;
        for(int j = 0; j <= nums.size() / 2; j ++)
            if(nums[j] != nums[nums.size() - j - 1]) flag = false;
        
        if(flag)
        {
            int t2 = i;
            while(t2) n2.push_back(t2 % n), t2 /= n;
            for(int j = n2.size() - 1; j >= 0; j --)
            {
                if(n2[j] >= 0 && n2[j] <= 9) cout << n2[j];
                else cout << (char)(n2[j] + 55);
            }
            cout << ' ';
            for(int j = nums.size() - 1; j >= 0; j --)
            {
                if(nums[j] >= 0 && nums[j] <= 9) cout << nums[j];
                else cout << (char)(nums[j] + 55);
            }
            cout << endl;
        }
    }
    
    
    
    return 0;
}
