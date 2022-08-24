#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, d;
int p[N];

inline string get_string(int n)
{
    string res = "";
    do
    {
        res += (char)(n % 10 + '0'), n /= 10;
    } while(n); // zero needs to be put
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
	cin >> n >> d;
	string res = "";
	res += get_string(n / d);
	res += '.';
	n %= d;
	if(!n) res += '0';
	else
	{
		memset(p, -1, sizeof p);
		string num = "";
		while(n && p[n] == -1)
		{
			p[n] = num.size();
			n *= 10;
			num += get_string(n / d);
			n %= d;
		}
		if(!n) res += num;
		else res += num.substr(0, p[n]) + '(' + num.substr(p[n]) + ')';
	}
	
	for(int i = 0; i < res.size(); i ++)
	{
	    cout << res[i];
	    if((i + 1) % 76 == 0) cout << endl;
	}
	
	return 0;
}
