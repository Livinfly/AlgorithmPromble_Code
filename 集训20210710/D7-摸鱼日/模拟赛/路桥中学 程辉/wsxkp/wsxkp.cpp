#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,rea,sped,vt,min1=99999999;
int qpower(int a,int b)
{
	if(!b)return 1;
	int ans=qpower(a*a,b>>1);
	if(b&1)ans=(ans*a);
	return ans;
}

int main()
{
	freopen("wsxkp.in","r",stdin);
	freopen("wsxkp.out","w",stdout);
	cin>>t;
	if(t<4)
	{
		cout<<t;
		return 0;
	}
	
	for(int i=1;;i++)//sped times
	{
		rea=1;//reset
	    sped=1;
	    vt=1;
	    
		for(int j=1;j<=i;j++)//sped
		{
			sped*=3;
			vt+=sped;
			rea++;
		}
		if(i!=1)
		for(int j=1;j<i;j++)//sped donw
		{
			sped/=3;
			vt+=sped;
			rea++;
		}
		if(vt==t)
		{
			cout<<rea;
			return 0;
		}
		if(vt==(t-3))
		{
			cout<<rea+1;
			return 0;
		}
	}
	return 0;
}
