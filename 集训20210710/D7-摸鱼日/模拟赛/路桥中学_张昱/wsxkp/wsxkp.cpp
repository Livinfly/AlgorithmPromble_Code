#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,ans,n,m;
int main(int argc, char** argv) {
freopen("wsxkp.in", "r", stdin);
freopen("wsxkp.out", "w", stdout);
    cin>>t;
	ans=1+(t-1)%3;
	t=(t-1)/3;
	while(t>0){
		ans=ans+(t-2)%3+2;
		t=(t-2)/3;
	}	
	cout<<ans<<endl;
	return 0;
}
