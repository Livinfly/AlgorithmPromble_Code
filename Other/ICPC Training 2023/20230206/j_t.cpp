#include<bits/stdc++.h>
using namespace std;

int m,n;
int a[1005];

int hw(int l,int r) {
	while(l < r) {
		if(a[l] != a[r]) 
			return 0;
		l ++;
		r --;
	}
	return 1;
}

int qwq() {
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
			ans += hw(i,j);
	return ans; 
}

signed main() {
	n = 14;
	int an = 0x3f3f3f3f;
	for(int i = 0; i < (1<<n); i ++) {
		for(int j = 0; j < n; j ++)
			a[j] = (bool)((1<<j)&i);
		an = min(an,qwq());
	}
	cout<<an<<"\n";
	for(int i = 0; i < (1<<n); i ++) {
		for(int j = 0; j  < n; j ++)
			a[j] = (bool)((1<<j)&i);
		if(qwq() == an) {
			for(int j = n-1; j >= 0; j --)
				cout<<a[j];
			cout<<"\n";
		}
		
	}
	
	return 0;
}