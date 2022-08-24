#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long qsm(int x,int y){
	long long ans=1;
    while(y){
    	if(y&1)ans=ans*x%mod;
	x=x*x%mod;
	y>>=1;
	}	
	return ans;
}
int main(){
	freopen("wsxtql.in", "r", stdin);
    freopen("wsxtql.out", "w", stdout);
	long long n,k,m,sum=0,ans2=0;
	sum=n;
	cin>>n>>k>>m;
	ans2=qsm(sum,k);
	for(int i=1;i<=m;i++){
		sum=sum-2;
		ans2=min(ans2,qsm(sum,k));
	}
	cout<<ans2<<endl;
	
	return 0;
}
