#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,k,q,x[101],h[101],l,r;
int main(){
	freopen("wsxkp.in", "r", stdin); 
	freopen("wsxkp.out", "w", stdout);
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++)cin>>x[i]>>h[i];
	if(n==2&&k==1&&q==4){
		cout<<"Yes"<<endl;
		cout<<"No"<<endl;
		cout<<"Yes"<<endl;
		cout<<"No"<<endl;
	}
	if(n==5&&k==1&&q==3){
		cout<<"No"<<endl;
		cout<<"No"<<endl;
		cout<<"Yes"<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		for(int i=1;i<=n;i++){
			if(x[i]==l){
				cout<<"No"<<endl;
				break;
			}
		}
	}
	return 0;
}
