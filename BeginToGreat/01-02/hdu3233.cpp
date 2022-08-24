#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e4 + 10;

priority_queue<double, vector<double>, greater<double> > heap;
int T, n, B;
double a[N];
double res;

void init()
{
	res = 0;
	memset(a, 0, sizeof a);
}

int main()
{
	int casee = 0;
  while(scanf("%d%d%d", &T, &n, &B) && T && n && B)
  {
  	init();
  	casee ++;
  	for(int i = 0; i < T; i ++)
  	{
  		double x; int per;
  		scanf("%lf %d", &x, &per);
  		a[i] = x*(100-per)/100;
		}
		sort(a, a+T);
		for(int i = 0; i < n; i ++)
			heap.push(a[i]);
		int num = n;
		while(num < T)
		{
			auto t = heap.top();
			heap.pop();
			heap.push(t+a[num]);
			num ++;
		}
		double sub_sum = 0;
		while(heap.size())
		{
			auto t = heap.top();
			int siz = heap.size();
			heap.pop();
			t -= sub_sum, sub_sum += t;
			res += t*siz/B;
		}
		printf("Case %d: %.2f\n\n", casee, res);
	}
  
  
  return 0;
}
/*
后知后觉，可以直接全加起来然后除啊，总速度又不变ono 
*/
