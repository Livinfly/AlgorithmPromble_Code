#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n;
string str;
set<string> books;

int main()
{
	while(scanf("%d", &n) == 1)
	{
		books.clear();
		while(n --)
		{
			cin >> str;
			books.insert(str);
		}
		
		printf("%d\n", books.size());
	}
	
	return 0;
}
