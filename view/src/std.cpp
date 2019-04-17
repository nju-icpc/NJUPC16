#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn][maxn],n,m,mx,r[maxn],c[maxn];

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> a[i][j];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]) printf("#"); else printf(".");
            mx=max(mx,a[i][j]);
            r[i]=max(r[i],a[i][j]);
            c[j]=max(c[j],a[i][j]);
        }
        puts("");
    }
    puts("");
    for (int h=mx-1;h>=0;h--) {
        for (int j=0;j<m;j++)
            if (h<c[j]) printf("#"); else printf(".");
        puts("");
    }
    puts("");
    for (int h=mx-1;h>=0;h--) {
        for (int i=0;i<n;i++)
            if (h<r[i]) printf("#"); else printf(".");
        puts("");
    }
    return 0;
}
