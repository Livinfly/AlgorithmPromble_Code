#include <bits/stdc++.h>
#define mid	(l + r) / 2
#define ls	now * 2
#define rs	now * 2 + 1
using namespace std;
int n, q, l, r;
int flag = 0;
void build( int now, int l, int r, int *a )
{
	if ( l == r )
	{
		cin >> a[now]; return;
	}
	build( ls, l, mid, a );
	build( rs, mid + 1, r, a );
	a[now] = a[ls] + a[rs];
	return;
}


int query( int now, int l, int r, int L, int R, int *a )
{
	if ( a[ls] + a[rs] != a[now] )
		flag = 1;
	if ( L <= l && r <= R )
		return(a[now]);
	int sum = 0;
	if ( L <= mid )
		sum += query( ls, l, mid, L, R, a );
	if ( mid + 1 <= R )
		sum += query( rs, mid + 1, r, L, R, a );
	return(sum);
}


int main()
{
	cin >> n >> q;
	int a[4 * n];
	memset( a, 0, sizeof(a) );
	build( 1, 1, n, a );
	for (int i = 1 ; i <= q ; i++ )
	{
		cin >> l >> r;
		cout << query( 1, 1, n, l, r, a ) << endl;
	}
	return 0 ;
}