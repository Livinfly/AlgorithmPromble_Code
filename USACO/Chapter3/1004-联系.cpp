#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

#define x first
#define y second

using namespace std;


int a, b, n;
string str;

struct rec
{
    string s;
    bool operator < (const rec &o) const
    {
        return s.size() > o.s.size() || (s.size() == o.s.size() && s > o.s);
    }
};
typedef pair<int, rec> PIR;

map<rec, int> cnt;
map<rec, int>::iterator it;
priority_queue<PIR> heap;

int main()
{
    ios::sync_with_stdio(0);
	cin >> a >> b >> n;
	string t;
	while(cin >> t) str += t;
	for(int len = a; len <= b; len ++)
    {
        for(int l = 0; l + len - 1 < (int) str.size(); l ++)
            cnt[(rec) {str.substr(l, len)}] ++;
    }
	for(it = cnt.begin(); it != cnt.end(); it ++)
	   heap.push(make_pair(it -> y, (rec) {it -> x.s}));
    int i = 0;
	while(heap.size() && i < n)
	{
	    int chg = 1;
	    i ++;
	    PIR t = heap.top(); heap.pop();
	    cout << t.x << endl;
	    cout << t.y.s << ' ';
	    while(heap.size() && heap.top().x == t.x)
	    {
	        chg ++; chg %= 6;
	        PIR r = heap.top(); heap.pop();
	        cout << r.y.s << ' ';
	        if(!chg) cout << endl;
	    }
	    if(chg) cout << endl;
	}
	
	return 0;
}
