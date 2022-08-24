#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1010;

int n, cnt;
string str;

int main()
{
	cin >> n;
	cin >> str;
	str = " " + str;
	for(int i = 1; i <= str.size(); i ++)
	{
//		cout << str << endl;
		if(str[i] == str[i - 1]) cnt ++;
		else cnt = 0;
		if(cnt == 2)
		{
			str.erase(str.begin() + i - 2, str.begin() + i + 1);
			cnt = 0;
			i = 1;
		}
	}
	
//	cout << str << endl;
	
	if(str.size() == 1) puts("Yes");
	else puts("No");
	
	return 0;
}
