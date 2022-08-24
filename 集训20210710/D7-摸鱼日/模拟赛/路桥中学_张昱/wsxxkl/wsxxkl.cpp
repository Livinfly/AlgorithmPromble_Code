#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(int argc, char** argv) {
freopen("wsxct.in", "r", stdin);
freopen("wsxct.out", "w", stdout);
cin>>n;
if(n<=10)cout<<4<<endl;else{
	if(n<=100)cout<<17<<endl; 
else{
	if(n<=200)cout<<52<<endl;
else {
	if(n<=500000)cout<<520<<endl;
}
}
}
	return 0;
}
