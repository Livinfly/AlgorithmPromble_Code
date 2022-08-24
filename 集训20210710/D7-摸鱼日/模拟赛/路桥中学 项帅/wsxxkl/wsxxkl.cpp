#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 50010, mod = 1e9 + 7;

int n, k, q, l, r;
int Map[100000010];
bool yes;
void dfs(int x, int h, int jx){
	if(h < Map[x]) return;
	if(x == r){
		yes = 1;
		return;
	}
	if(h == 0) jx = 0;
	if(h){
		if(yes) return; 
		if(jx <= k)
			dfs(x + 1, h + 1, jx + 1);
		else
			dfs(x + 1, h - 1, jx + 1);
	}
	else{
		if(yes) return;
		dfs(x + 1, h, jx);
		dfs(x + 1, h + 1, jx + 1);
	}
}

int main(){
	//freopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopen
	//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
	freopen("wsxxkl.in","r",stdin);
	freopen("wsxxkl.out","w",stdout);
	scanf("%d%d%d",&n, &k, &q);
	for(int i = 1; i <= n; i++){
		int x, h;
		scanf("%d%d",&x,&h);
		Map[x] = h;
	}
	for(int i = 1; i <= q; i++){
		scanf("%d%d",&l,&r);
		yes = 0;
		dfs(l, 0, 0);
		if(yes) puts("Yes");
		else puts("No");
	}
	return 0;
}





























