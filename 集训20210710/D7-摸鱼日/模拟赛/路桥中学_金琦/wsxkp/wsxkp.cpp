#include <bits/stdc++.h>

using namespace std;

int main(){
	long long t;
	long long ans;
	freopen("wsxkp.in", "r", stdin);
    freopen("wsxkp.out", "w", stdout);
	cin>>t;
	ans=1+(t-1)%3;
	t=(t-1)/3;
	while(t>0){
		ans=ans+2+(t-2)%3;
		t=(t-2)/3;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
