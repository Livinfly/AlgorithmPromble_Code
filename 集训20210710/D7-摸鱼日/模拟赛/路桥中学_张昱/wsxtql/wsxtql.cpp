#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll wjl=1e9+7;
ll l,n,k,m;
long long qp(long long x,long long y){
	ll anss=1;
	while(y){
		if(y&1){
			anss=anss*x;
		}
		y>>=1;x=x*x;
	}
	return anss;
}
int main(int argc, char** argv) {	
	freopen("wsxtql.in", "r", stdin);
	freopen("wsxtql.out", "w", stdout);
	cin>>n>>k>>m;
	ll s=n;
	ll ans=qp(s,k);
	for(int i=1;i<=m;i++){
		s=s-2;
		ans=min(ans,qp(s,k));
	}
	cout<<ans%wjl<<endl;
	return 0;
}
