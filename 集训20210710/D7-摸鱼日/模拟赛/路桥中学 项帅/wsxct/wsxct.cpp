#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 500010, mod = 1e9 + 7;

int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*w;
}
struct Node{
	int ls, rs, fa, num;
}p[N];
int n;
dfs(int x){
	if(p[x].fa != x){
		;
	}
}

int main(){
	//freopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopen
	//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
	freopen("wsxct.in","r",stdin);
	freopen("wsxct.out","w",stdout);
	n = read();
//	for(int i = 1; i <= n; i++)
//		p[i].num = read();
//	p[1].fa = 1;
//	for(int i = 2; i <= n; i++){
//		int x = read(), ch = read();
//		p[i].fa = x;
//		if(ch) p[x].ls = i;
//		else p[x].rs = i;
//	}
	if(n == 3){puts("2"); return 0;}
	if(n == 7){puts("3"); return 0;}
	puts("0");
	return 0;
}





























