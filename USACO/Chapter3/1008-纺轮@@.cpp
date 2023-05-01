#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 360;

int v[5], s;
bool st[5][N]; // i group, j angle avaiable?

int main()
{
    for(int i = 0; i < 5; i ++)
    {
        int A, len;
        cin >> v[i] >> s;
        for(int j = 0; j < s; j ++)
        {
            cin >> A >> len;
            for(int j = A; j <= A + len; j ++) 
                st[i][j % N] = true;
        }
    }
    for(int i = 0; i < N; i ++) // Time
        for(int j = 0; j < N; j ++) // Angle
        {
            bool flag = true;
            for(int k = 0; k < 5; k ++) // group
            {
                int t = j - v[k] * i; // j = (orgin) + v[k] * time 
                t = (t % N + N) % N;
                if(!st[k][t]) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag) 
            {
                cout << i << endl;
                return 0;
            }
        }
    cout << "none" << endl;
    return 0;
}
