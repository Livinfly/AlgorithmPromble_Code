#include <iostream>
#include <cstdio>

using namespace std;

int n, Y = 1900, D, day = 0;
int cnt[7]; // 7, 1~6, 6/7/1/2/3/4/5 ans
int m1[15] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // ?
int m2[15] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // ?

int main()
{
    cin >> n;
    while(Y < 1900 + n)
    {
        if(Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0)) // ??
        {
            for(int i = 0; i < 12; i ++)
            {
                cnt[(day + 13) % 7] ++;
                day += m2[i];
                day %= 7;
            }
        }
        else
        {
            for(int i = 0; i < 12; i ++)
            {
                cnt[(day + 13) % 7] ++;
                day += m1[i];
                day %= 7;
            }
        }
        
        Y ++;
    }
    
    cout << cnt[6] << ' ' << cnt[0] << ' ';
    for(int i = 1; i <= 5; i ++) cout << cnt[i] << ' ';
    cout << endl;
    
    return 0;
}
