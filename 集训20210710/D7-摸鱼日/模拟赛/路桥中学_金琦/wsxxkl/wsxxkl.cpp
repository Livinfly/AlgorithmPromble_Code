#include <bits/stdc++.h>
#define N 50010
using namespace std;
long long a[N];
int main(){
	freopen("wsxxkl.in", "r", stdin);
    freopen("wsxxkl.out", "w", stdout);  
	long long  n,k,q;
	memset(a,0,sizeof(a));
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int x,h;
		cin>>x>>h;
		a[x]=h;
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		int flag=1;
		for(int j=l;j<=r;j++){
			if(j==l&& a[j]) {
				flag=0;break;
			}
			if(a[j]){
				if(a[j-1] || a[j+1] || a[j]>k) {flag=0;break;
				}
			}
		}
		if(flag==0)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
