#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> PII;

struct Node
{
	PII p[4];
	int s = 0;
	int toint()
	{
		int t = 0;
		for (int i = 0; i < 4; i++)
		{
			t = t * 10 + this->p[i].first;
			t = t * 10 + this->p[i].second;
		}
		return t;
	}
	friend bool operator<(const Node &a, const Node &b)
	{
		return a.s < b.s;
	}
} st[2];

int dxy[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};
map<int, int> d[2];
// 未用到
bool read_data()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			cin >> st[i].p[j].first >> st[i].p[j].second;
	return true;
}
// 判断是否P点已被别的棋子占用
bool used_pos(PII p, Node t)
{
	//	cout << "used_posxxxx\n";
	//	cout << p.first << ' ' << p.second << endl;
	for (int i = 0; i < 4; i++)
	{
		//		cout << t.p[i].first << ' ' << t.p[i].second << endl;
		if (t.p[i] == p)
			return true;
	}
	//	cout << endl;
	return false;
	;
}
// 队列q扩展一次
int expand(queue<Node> &q, map<int, int> &mp1, map<int, int> &mp2)
{
	Node t = q.front();
	q.pop();

	for (int i = 0; i < 4; i++) // which change
	{
		int x = t.p[i].first, y = t.p[i].second;
		for (int j = 0; j < 4; j++) // direction
		{
			int nx = x + dxy[j][0], ny = y + dxy[j][1];
			if (nx < 1 || nx > 8 || ny < 1 || ny > 8)
				continue;
			if (used_pos(make_pair(nx, ny), t))
			{
				nx += dxy[j][0], ny += dxy[j][1];
				if (nx < 1 || nx > 8 || ny < 1 || ny > 8)
					continue;
				if (used_pos(make_pair(nx, ny), t))
					continue;
			}
			// have found legal status, check if it had existed
			Node nt = t;
			nt.p[i] = make_pair(nx, ny), sort(nt.p, nt.p + 4), nt.s = nt.toint();

			if (!mp1.count(nt.s))
			{
				mp1[nt.s] = mp1[t.s] + 1;
				if (mp2.count(nt.s))
					return mp1[nt.s] + mp2[nt.s];
				//	cout << mp1[nt.s] + mp2[nt.s] << endl;
				if (mp1[nt.s] == 4)
					continue;
				q.push(nt);
			}
		}
	}
	return 9;
}
bool dbfs(Node A, Node Z)
{
	queue<Node> q[2];
	sort(A.p, A.p + 4), sort(Z.p, Z.p + 4);
	A.s = A.toint(), Z.s = Z.toint();
	q[0].push(A), q[1].push(Z);
	d[0][A.s] = 0, d[1][Z.s] = 0;

	while (q[0].size() && q[1].size())
	{
		int t;
		if (q[0].size() <= q[1].size())
			t = expand(q[0], d[0], d[1]);
		else
			t = expand(q[1], d[1], d[0]);
		if (t <= 8)
			return true;
	}
	for (int i = 0; i < 2; i++)
	{
		while (q[i].size())
		{
			int t;
			t = expand(q[i], d[i], d[1 - i]);
			if (t <= 8)
				return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//  freopen("i.txt", "r", stdin);
	//  freopen("o.txt", "w", stdout);
	while (cin >> st[0].p[0].first >> st[0].p[0].second)
	{
		for (int i = 0; i < 2; i++)
			d[i].clear();
		for (int i = 0; i < 2; i++)
			for (int j = 1 - i; j < 4; j++)
				cin >> st[i].p[j].first >> st[i].p[j].second;
		//		read_data();
		if (dbfs(st[0], st[1]))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
