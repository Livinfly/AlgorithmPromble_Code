#include<bits/stdc++.h>
using namespace std;

const int M=365;
struct node
{
	int v,sum;
	int k[10],f[10];//k是宽度，f是初始位置
}a[10];

int sum[M];

int main()
{
	for (int i=1;i<=5;i++)
	{
		cin>>a[i].v>>a[i].sum;
		for (int j=1;j<=a[i].sum;j++)
			cin>>a[i].f[j]>>a[i].k[j];
	}
	for (int i=0;i<360;i++)//第i秒
	{
		memset(sum,0,sizeof (sum));//每次都要memset
		for (int j=1;j<=5;j++)//第j个轮子
			for (int k=1;k<=a[j].sum;k++)//第k个缺口
				for (int w=0;w<=a[j].k[k];w++)//w是缺口的度数
					sum[(a[j].f[k]+i*a[j].v+360+w)%360]++;//注意要%360,否则会RE
		for (int j=0;j<360;j++)
			if (sum[j]==5)
			{
				cout<<i;
				return 0;
			}
	}
	cout<<"none";//找不到
	return 0;
}
