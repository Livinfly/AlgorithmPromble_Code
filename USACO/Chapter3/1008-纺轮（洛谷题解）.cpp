#include<bits/stdc++.h>
using namespace std;

const int M=365;
struct node
{
	int v,sum;
	int k[10],f[10];//k�ǿ�ȣ�f�ǳ�ʼλ��
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
	for (int i=0;i<360;i++)//��i��
	{
		memset(sum,0,sizeof (sum));//ÿ�ζ�Ҫmemset
		for (int j=1;j<=5;j++)//��j������
			for (int k=1;k<=a[j].sum;k++)//��k��ȱ��
				for (int w=0;w<=a[j].k[k];w++)//w��ȱ�ڵĶ���
					sum[(a[j].f[k]+i*a[j].v+360+w)%360]++;//ע��Ҫ%360,�����RE
		for (int j=0;j<360;j++)
			if (sum[j]==5)
			{
				cout<<i;
				return 0;
			}
	}
	cout<<"none";//�Ҳ���
	return 0;
}
