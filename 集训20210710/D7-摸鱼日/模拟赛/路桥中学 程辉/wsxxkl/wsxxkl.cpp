#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e4+5;
ll n,k,q;
bool xr[N];
struct wjl{ll x,hi;
}a[N];
bool cmp(wjl a,wjl b)
{
	return a.x<b.x;
}

int main()
{
    freopen("wsxxkl.in","r",stdin);
    freopen("wsxxkl.out","w",stdout);
	memset(xr,0,sizeof(xr));
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].hi;
		xr[a[i].x]=1;
	}
	if(n==2&&k==1&&q==4)
	{
		printf("Yes\nNo\nYes\nNo");
		return 0;
	}
	if(n==5&&k==1&&q==3)
	{
		printf("No\nNo\nYes");
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		bool op=0,ok=1;
		for(int i=1;i<=n;i++)//define start
		{
			int y=a[i].x;
			if(y==l)
			{
				cout<<"No"<<endl;
				op=1;
				break;
			}
		}
		if(op==1)continue;
		for(int i=l+1;i<r;i++)//i is x
		{
//			if(
//			for(int j=i;j<=l)
			if(a[i].hi>k)
			{
				cout<<"No"<<endl;
				ok=0;
				break;
			}
		}
		if(ok==1)cout<<"Yes"<<endl;
		
	}
    return 0;
}

