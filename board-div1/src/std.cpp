#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int INF=1e8;
int dp[1<<13],s[1<<13],n,m,f[13],t[13],rk,fb[13];
int p[maxn],v[maxn];

int readint() {
        string str; cin >> str;
        if (str == "-") return -1;
        else return atoi(str.c_str());

}

int main(){
    cin >> m >> n;
    for (int i=0;i<n;i++) {
        f[i] = readint();
    }
    for (int i=0;i<n;i++){
        if (f[i]==-1) t[i]=INF;
        else {
            int mx=0;
            for (int j=0;j<n;j++) if (f[j]<f[i]) mx=max(mx,f[j]);
            t[i]=f[i]-mx;
            v[0]++;
        }
    }
    for (int i=0;i<n;i++) fb[i]=INF;
    for (int i=1;i<m;i++){
        for (int j=0;j<n;j++){
            int x = readint();
            if (x!=-1) v[i]++,p[i]+=x,fb[j]=min(fb[j],x);
        }
    }
    for (int i=0;i<(1<<n);i++)
        for (int j=0;j<n;j++) if (i&(1<<j)) s[i]+=t[j];
    for (int i=0;i<(1<<n);i++)
        for (int j=0;j<n;j++) if (i&(1<<j)) dp[i]=max(dp[i],dp[i^(1<<j)]+(s[i]<=fb[j]));
    sort(t,t+n);
    int tm=0;
    for (int i=0;i<n;i++) if (t[i]<INF) tm+=t[i],p[0]+=tm;
    rk=1;
    for (int i=1;i<m;i++) if (v[i]>v[0]||v[i]==v[0]&&p[i]<p[0]) rk++;
    cout << dp[(1<<n)-1] << ' ' << rk << endl;
    return 0;
}
