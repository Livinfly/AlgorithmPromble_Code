#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<string, string> dic;

string s1, s2;

int main()
{
//	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	while(cin >> s1)
	{
		if(s1 == "START") continue;
		if(s1 == "END") break;
		
		cin >> s2;
		dic[s2] = s1;
	}
	getline(cin, s1);
	while(getline(cin, s1))
	{
		if(s1 == "START") continue;
		if(s1 == "END") break;
		s2 = "";
		for(int i = 0; i < s1.size(); i ++)
		{
			
			if(s1[i] >= 'a' && s1[i] <= 'z')
			{
				s2 = s2 + s1[i];
//				cout << s2 << endl;
			}
			else
			{
				if(dic.count(s2)) cout << dic[s2];
				else cout << s2;
				s2 = "";
				cout << s1[i];
			}
		}
		if(s2.size()) cout << s2; // forget
		cout << endl;
	}
	
	return 0;
}
