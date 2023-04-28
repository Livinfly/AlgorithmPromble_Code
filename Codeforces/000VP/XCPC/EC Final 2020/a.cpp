#include<bits/stdc++.h>
using namespace std;

int n,m;
int f[15][6];
char ss[4];
//DSHC
//23456789TJQKA

int vl[200],vr[200];
int dx[6],dy[6];

void solve() {
	memset(f,0,sizeof(f));
	for(int i = 1; i <= 5; i ++) {
		scanf("%s",ss+1);
		int x = vl[ss[1]],y = vr[ss[2]];
		if(i <= 2) f[x][y] = 2;
		else f[x][y] = 1;
		dx[i] = x; dy[i] = y;
	//	cout<<i<<" "<<" "<<ss[1]<<" "<<ss[2]<<" "<<x<<" "<<y<<"\n"; 
	}
	for(int i = 1; i <= 5; i ++)
	if(dy[i] != dy[1]) {
		printf("check\n");
		return;
	}
	int t = dy[1];
	int st = 0;
	for(int i = 2; i <= 10; i ++) {
		bool fl = 1; 
		for(int j = i; j <= i+4; j ++)
			if(!f[j][t]) fl = 0;
		if(fl) st = i;
	}
	/* 
	cout<<st<<"?\n";
	for(int i = 2; i <= 14; i ++)
		cout<<f[i][t]<<" ";
	cout<<"\n";*/
	if(!st) {
		printf("check\n"); 
		return;
	}
	for(int i = st+1; i <= 10; i ++) {
		bool fl = 1,fg = 0;
		
		for(int j = i; j <= i+4;  j ++) {
			if(f[j][t] == 2) fl = 0;
			if(f[j][t] == 1) fg = 1;
		}
		if(fl && fg) {
			printf("check\n");
			return;
		}
	}
	printf("allin\n");
	return;
	
	
}

signed main() {
	int T;
	cin >> T;
	string s1 = "23456789TJQKA";
	for(int i = 2; i <= 14; i ++)
		vl[s1[i-2]] = i;
	//cout<<vl['9']<<"\n";
	
	string s2 = "DSHC";
	for(int i = 1; i <= 4; i ++)
		vr[s2[i-2]] = i;
	
	while(T --) {
		solve();
	}
	return 0;
}
/*
1
5C 4C 3C 2C AC
*/