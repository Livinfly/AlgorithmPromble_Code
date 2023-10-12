#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353,E=1500;
int n,m,a[N],e[35],t,k;
map<int,int> mp;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        mp.clear();
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            mp[k^a[i]]=1;
        }
        int fl=-1;
        for(int i=1;i<=n;++i)
            if(mp[a[i]]){
                fl=1;
                break;
            }
        if(fl==-1){
            for(int i=1;i<=n;++i)
                if(!mp[a[1]^a[i]]){
                    fl=2;
                    break;
                }
            if(fl==-1){
                memset(e,0,sizeof(e));
                int s=0;
                sort(a+1,a+1+n);
                n=unique(a+1,a+1+n)-a-1;
                for(int i=1;i<=n;++i){
                    int x=k^a[i];
                    for(int j=29;j>=0;--j)
                        if(x>>j&1)
                            if(e[j])
                                x^=e[j];
                            else{
                                e[j]=x;
                                ++s;
                                break;
                            }
                }
                if((1<<s)!=n)
                    fl=2;
                else
                    fl=0;
            }
        }
        puts(fl==2?"Draw":(fl==1?"Alice":"Bob"));
    }
}
