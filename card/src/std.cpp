#include<bits/stdc++.h>
using namespace std;
typedef double db;
int d[105],n,a,b;
db f[105],nf[105],dp[105][105][105];
db C(int x,int y){
    return f[x]*nf[y]*nf[x-y];
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n;i++) scanf("%d",&d[i]);
    f[0]=nf[0]=1;
    for (int i=1;i<=n;i++) f[i]=f[i-1]*i,nf[i]=nf[i-1]/i;
    db ans=0;
    for (int o=1;o<=n;o++){
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<n;j++) for (int k=0;k<=b;k++) dp[i][j][k]=dp[i-1][j][k];
            if (i==o) continue;
            for (int j=1;j<n;j++) for (int k=d[i];k<=b;k++) dp[i][j][k]+=dp[i-1][j-1][k-d[i]];
        }
        int l=a-d[o],r=min(a,b-d[o]);
        for (int i=r;i>l;i--)
            for (int j=0;j<n;j++)
                ans+=dp[n][j][i]/C(n,j)/(n-j);
    }
    printf("%.12f\n",ans);
    return 0;
}
