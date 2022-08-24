#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N =  10086, mod = 1e9 + 7;

ll t;

int main(){
	//freopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopenfreopen
	//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
	freopen("wsxkp.in","r",stdin);
	freopen("wsxkp.out","w",stdout);
	scanf("%lld",&t);
	ll b = 1, sum = 0, last = 1, tim = 0;
	if(t == 1){
		printf("1\n");
		return 0;
	}
	while(sum < t){
		last = b;
		b = b * 3;
		sum += last + b;
		tim += 2;
	}
	if(sum == t){
		printf("%lld\n",tim);
		return 0;
	}
	sum -= last + b; tim -= 2; last /= 3; b /= 3;
	ll lef = t - sum;
	while(lef && b){
		while(lef - b >= 0) lef -= b, tim ++;
		b /= 3;
	}
	printf("%lld\n",tim);
	return 0;
}





























