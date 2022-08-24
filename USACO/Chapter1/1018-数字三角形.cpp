#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510;

int n;
int dp[N][N];

int main()
{
    cin >> n;
	for(int i = 1; i <= n; i ++)
	    for(int j = 1; j <= i; j ++) 
	        cin >> dp[i][j];
	
	for(int i = n - 1; i > 0; i --)
	    for(int j = 1; j <= i; j ++)
	        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
	
	cout << dp[1][1] << endl;
	
	
	return 0;
}
/*
打了挺多遍了，挺清晰吧，但是识别这个模型的话... 
*/
