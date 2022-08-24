#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int N=10001;
ll dp[N][N];
int main(){
	freopen("wsxtql.in", "r", stdin); 
	freopen("wsxtql.out", "w", stdout);
	int n,m,k;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		dp[i][1]=i;dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=dp[i][1]*dp[i][j-1]%mod;
		}
	}
	cout<<dp[n][k]%mod<<endl;
	return 0;
} 
