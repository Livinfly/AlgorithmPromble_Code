#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("wsxkp.in", "r", stdin); 
	freopen("wsxkp.out", "w", stdout);
	ll t,time,ans=1;
	cin>>t;
	ll speed=1;
	if(t==0){
		cout<<0<<endl;
		return 0;
	}
	t=t-1;
	while(t>0){
		if(t>speed*3){
			speed*=3;
			ans++;
		}
		if(t<speed*3&&t>speed){
			ans++;
		}
		if(t<speed&&speed!=1){
			speed/=3;
			ans++;
		}
		if(t<=speed&&speed==1)ans++;
		t-=speed;
	}
	cout<<ans<<endl;
	return 0;
}
