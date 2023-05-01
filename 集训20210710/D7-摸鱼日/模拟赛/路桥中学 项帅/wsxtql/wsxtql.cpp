#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N =  10086, mod = 1e9 + 7;

ll n, k, m;

int main(){
	//freopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopen
	//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
	freopen("wsxtql.in","r",stdin);
	freopen("wsxtql.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&m);
	if(n <= 2 * m){
		if(n & 1) puts("1");
		else puts("0");
		return 0;
	}
	n -= 2 * m;
	ll t = k, num = n, res = 1;
	while(t){
		if(t & 1){
			res = (res * num) % mod;
		}
		num = (num * num) % mod;
		t >>= 1;
	}
	printf("%lld\n",res);
	return 0;
}





























