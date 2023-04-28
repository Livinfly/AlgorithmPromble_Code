#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

const int N=1e6+10;
int n,m;
ll k,pw[N];

void dfs(int id,ll rk,int lst1,int lst2){
	if(id>n) return;
	ll res,ys;
	if(id==1) res=rk/(m-1)/pw[n-2];
	else res=rk/pw[n-id];
	if(res<1){
		ll nxt=1;
		if(lst1>0&&lst1<=nxt){
			++nxt;
			if(lst2>0&&lst2<=nxt) ++nxt;
		}
		else if(lst2>0&&lst2<=nxt){
			++nxt;
			if(lst1>0&&lst1<=nxt) ++nxt;
		}
		printf("%lld ",nxt);
		dfs(id+1,rk,nxt,lst1);
	}
	else{
		if(id==1) ys=rk%(pw[n-2]*(m-1));
		else ys=rk%pw[n-id];
		ll nxt=res;
		if(ys!=0) ++nxt;
		if(lst1>0&&lst1<=nxt){
			++nxt;
			if(lst2>0&&lst2<=nxt) ++nxt;
		}
		else if(lst2>0&&lst2<=nxt){
			++nxt;
			if(lst1>0&&lst1<=nxt) ++nxt;
		}
		printf("%lld ",nxt);
		if(ys!=0) dfs(id+1,ys,nxt,lst1);
		else{
			if(id==1) dfs(id+1,pw[n-2]*(m-1),nxt,lst1);
			else dfs(id+1,pw[n-id],nxt,lst1);
		}
	}
}

signed main(){
//	freopen("1.in","r",stdin);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(m==1){
		if(k>1) puts("-1");
		else{
			for(int i=1;i<=n;++i) printf("%d ",1);
		}
	}
	else if(m==2){
		if(k>2) puts("-1");
		else if(k==2){
			for(int i=1,now=2;i<=n;++i,now=3-now){
				printf("%lld ",now);
			}
		}
		else{
			for(int i=1,now=1;i<=n;++i,now=3-now){
				printf("%lld ",now);
			}
		}
	}
	else{
		if(n==1){
			if(k>m) puts("-1");
			else printf("%lld\n",k);
			return 0;
		}
		double ee=1.0*k/m/(m-1);
		for(int i=1;i<=n-2;++i) ee/=(m-2);
		if(ee>1) return puts("-1"),0;
		if(m>3){
			ll cc=0,tmp=k/(m-2);
			while(tmp>=1) ++cc,tmp/=(m-2);
			pw[0]=1;
			for(int i=1;i<=cc;++i) pw[i]=pw[i-1]*(m-2);
			for(int i=cc+1;i<=n;++i) pw[i]=k+1;
		}
		else{
			for(int i=0;i<=n;++i) pw[i]=1;
		}
		dfs(1,k,0,0);
	}
	return 0;
}