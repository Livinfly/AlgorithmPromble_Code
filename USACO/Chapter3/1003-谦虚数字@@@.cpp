#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, k;
struct rec
{
    int v, p, k; // self_val, prime_val, prime_arr_pos 
    bool operator < (const rec &o) const
    {
        return v > o.v;
    }
};
priority_queue<rec> heap;
vector<int> ans;

int main()
{
	cin >> k >> n;
	n ++;
	ans.push_back(1);
	while(k --)
	{
	    int a; cin >> a;
	    heap.push((rec) {a, a, 0});
	}
	while(ans.size() < n)
	{
	    rec t = heap.top(); heap.pop();
	    ans.push_back(t.v);
	    heap.push((rec) {t.p * ans[t.k + 1], t.p, t.k + 1});
	    while(heap.top().v == t.v)
	    {
	        rec r = heap.top(); heap.pop();
	        heap.push((rec) {r.p * ans[r.k + 1], r.p, r.k + 1});
	    }
	}
	cout << ans.back() << endl;
	
	return 0;
}
