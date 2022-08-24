#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int n;
map<int, string> dic;
map<string, int> cnt;
map<int, string>::iterator it;
inline void prev_calu()
{
	dic[1] = "I"; dic[4] = "IV"; dic[5] = "V"; dic[9] = "IX";
	dic[10] = "X"; dic[40] = "XL"; dic[50] = "L"; dic[90] = "XC";
	dic[100] = "C";dic[400] = "CD";dic[500] = "D";dic[900] = "CM";
	dic[1000] = "M"; 
}
inline void solve(int n)
{
	while(n >= 1000) cnt["M"] ++, n -= 1000;
	while(n >= 900) cnt["C"] ++, cnt["M"] ++, n -= 900;
	while(n >= 500) cnt["D"] ++, n -= 500;
	while(n >= 400) cnt["C"] ++, cnt["D"] ++, n -= 400;
	while(n >= 100) cnt["C"] ++, n -= 100;
	while(n >= 90) cnt["X"] ++, cnt["C"] ++, n -= 90;
	while(n >= 50) cnt["L"] ++, n -= 50;
	while(n >= 40) cnt["X"] ++, cnt["L"] ++, n -= 40;
	while(n >= 10) cnt["X"] ++, n -= 10;
	while(n >= 9) cnt["I"] ++, cnt["X"] ++, n -= 9;
	while(n >= 5) cnt["V"] ++, n -= 5;
	while(n >= 4) cnt["I"] ++, cnt["V"] ++, n -= 4;
	while(n >= 1) cnt["I"] ++, n -= 1;
}
inline void write_out()
{
	for(it = dic.begin(); it != dic.end(); it ++)
	{
		if(cnt.count(it -> second))
			cout << it -> second << ' ' << cnt[it -> second] << endl;
	}
}

int main()
{
	prev_calu();
	cin >> n;
	for(int i = 1; i <= n; i ++) solve(i);	
	write_out();
	
	return 0;
}
