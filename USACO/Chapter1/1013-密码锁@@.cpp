#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int a[5], b[5], conn[5];

int main()
{
	cin >> n;
	for(int i = 0; i < 3; i ++) cin >> a[i];
	for(int i = 0; i < 3; i ++) cin >> b[i];
	
	for(int i = 0; i < 3; i ++) conn[i] = max(5 - min(abs(a[i] - b[i]), abs(a[i] - b[i] - n)), 0); // 可能是两头的
	
	int res = 1;
	for(int i = 0; i < 3; i ++) res *= conn[i];
	
	cout << min(250 - res, n * n * n) << endl; // n == 1
	
	return 0;
}
/*
是"对应"的位置上的数字差 2 以内 

过得莫名？？
*/
