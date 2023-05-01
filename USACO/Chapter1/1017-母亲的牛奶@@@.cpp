#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 25;

int a, b, c;
bool ans[N], st[N][N][N];

void dfs(int va, int vb, int vc)
{
	if(st[va][vb][vc]) return;
	
	st[va][vb][vc] = true;
	if(va == 0) ans[vc] = true; // no return
	
	dfs(min(a, va + vc), vb, vc - (min(a, va + vc) - va)); // c -> a
	dfs(va, min(b, vb + vc), vc - (min(b, vb + vc) - vb)); // c -> b
	dfs(min(a, va + vb), vb - (min(a, va + vb) - va), vc); // b -> a
	dfs(va, vb - (min(c, vb + vc) - vc), min(c, vb + vc)); // b -> c
	dfs(va - (min(b, va + vb) - vb), min(b, va + vb), vc); // a -> b
	dfs(va - (min(c, va + vc) - vc), vb, min(c, va + vc)); // a -> c
}

int main()
{
	cin >> a >> b >> c;
	
	dfs(0, 0, c);
	
	for(int i = 0; i < N; i ++)
		if(ans[i]) printf("%d ", i);
	puts(""); 
	
	return 0;
}
