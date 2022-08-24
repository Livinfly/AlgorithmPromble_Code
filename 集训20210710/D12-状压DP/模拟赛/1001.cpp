#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10;

int a[N]; 

int main()
{
	for(int i = 1; i <= 8; i ++) cin >> a[i];
	sort(a + 1, a + 8 + 1);
	int my = a[1] + a[2] + a[3], pa = a[7] + a[8];
	
	if(pa > my) puts("Yes");
	else puts("No");
	
	return 0;
}
