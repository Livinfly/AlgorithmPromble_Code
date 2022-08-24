#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int N = 15;

int n;
string s1, s2;
stack<char> stk;
vector<int> ans;

bool work()
{
	int p1 = 1, p2 = 1;
	while(stk.size()) stk.pop();
	stk.push('#');
	while(p2 <= n)
	{
		while(p1 <= n && stk.top() != s2[p2])
		{
			ans.push_back(1);
			stk.push(s1[p1]);
			p1 ++;
		}
		while(p2 <= n && stk.top() == s2[p2])
		{
			ans.push_back(0);
			stk.pop();
			p2 ++;
		}
		if(p1 > n && stk.size() != 1) return false;
	}
	return true;
}


int main()
{
	while(scanf("%d", &n) == 1)
	{
		ans.clear();
		cin >> s1 >> s2;
		s1 = " " + s1;
		s2 = " " + s2; 
		 
		if(work())
		{
			puts("Yes.");
			for(int i = 0; i < ans.size(); i ++)
				if(ans[i] == 1) puts("in");
				else puts("out");
		}
		else puts("No.");
		puts("FINISH");
	}
	
	return 0;
}
