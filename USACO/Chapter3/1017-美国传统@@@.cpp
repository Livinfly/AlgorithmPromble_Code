#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30;

int pos[N]; // ([char] - 'A') in in_order's pos 
string pre_order, in_order, post_order;

inline void build(int il, int ir, int pl, int pr)
{
    if(il > ir) return;
    int p = pos[pre_order[pl] - 'A'];
    build(il, p - 1, pl + 1, pl + 1 + p - 1 - il);
    build(p + 1, ir, pl + 1 + p - 1 - il + 1, pr);
    post_order += pre_order[pl];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> in_order >> pre_order;
	int n = in_order.size();
	for(int i = 0; i < n; i ++) pos[in_order[i] - 'A'] = i;
	build(0, n - 1, 0, n - 1);
	cout << post_order << endl;
	return 0;
}
