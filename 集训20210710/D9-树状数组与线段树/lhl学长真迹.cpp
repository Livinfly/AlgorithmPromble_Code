#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e5+3;

struct Node{
	int l,r;
	int val,lza,lzm;
	void operator *= (int y) {
		lzm=lzm*y; val=val*y; lza=lza*y;
	}
	Node operator * (int y){
		return (Node){l,r,val*y,lza*y,lzm*y};
	}
};

signed main()
{
	return 0;
}
