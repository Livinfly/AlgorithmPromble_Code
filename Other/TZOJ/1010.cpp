#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 65;

string dic11[5] = {"hi", "tsuki", "hoshi"}, 
	dic12[5] = {"haru", "natsu", "aki", "fuyu"}, 
	dic13[5] = {"ka", "mizu", "ki", "kin", "tsuchi"}, 
	dic21[15] = {"jia", "yi", "bing", "ding", "wu", "ji",
		 "geng", "xin", "ren", "gui"}, 
	dic22[15] = {"zi", "chou", "yin", "mao", "chen", "si",
		 "wu", "wei", "shen", "you", "xu", "hai"};
string s[5];
map<string, int> trans;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a1 = 1, a2 = 9, b1 = 0, b2 = 0, b3 = 4;
	for(int i = 0; i < 60; i ++)
	{
		string s1 = dic21[a1] + dic22[a2], s2 = dic11[b1] + dic12[b2] + dic13[b3];
		trans[s1] = b1 * 100 + b2 * 10 + b3, trans[s2] = a1 * 100 + a2;
		a1 ++, a2 ++, b1 ++, b2 ++, b3 ++;
		a1 %= 10, a2 %= 12, b1 %= 3, b2 %= 4, b3 %= 5;
	}
	
//	for(map<string, int>::iterator it = trans.begin(); it != trans.end(); it ++)
//		cout << it -> first << ' ' << it -> second << endl;
			
	int T; cin >> T;
	while(T --)
	{
		int op; cin >> op;
		if(op == 1)
		{
			string str = "", t;
			for(int i = 0; i < 3; i ++)
			{
				cin >> t;
				str += t;
			}
			int id = trans[str];
			cout << dic21[id / 100] << ' ' << dic22[id % 100] << endl;
		}
		else
		{
			string str = "", t;
			for(int i = 0; i < 2; i ++)
			{
				cin >> t;
				str += t;
			}
			int id = trans[str];
			cout << dic11[id / 100] << ' '<< dic12[id / 10 % 10] << ' ' << dic13[id % 10] << endl;
		}
	}
    
    return 0;
}
