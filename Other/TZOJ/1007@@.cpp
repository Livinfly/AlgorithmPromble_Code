#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int n, m, cnt;
int pos[N], type[N]; // space 1... 
string str[N], tstr; // 0...

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m;
	getline(cin, tstr);
	getline(cin, tstr);
    for(int i = 0; i < tstr.size(); i ++)
    {
    	string t = "";
    	while(tstr[i] != ' ' && i < tstr.size())
    	{
    		t += tstr[i];
    		i ++;
		}
		str[cnt] = t;
		pos[++ cnt] = i;
	}
	
	for(int i = 
    
    return 0;
}
