#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
const int E=100000;
const int maxn=E*3+10;
vector <pi> h[maxn];
bool vis[maxn];
int l,r,mid,n,m,u,v,w;
string s;
int _getid(){
    cin >> s;
    int ret=atoi(s.substr(2,s.size()-3).c_str());
    if (s[0]=='H') ret+=E; else if (s[0]=='O') ret+=E*2;
    return ret;
}

bool check(int x){
    memset(vis,0,sizeof(vis));
    queue <int> q;
    for (int i=1;i<=E;i++) q.push(i),vis[i]=1;
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (auto e:h[u]) if (e.second>x) {
            int v=e.first;
            if (!vis[v]) q.push(v),vis[v]=1;
        }
    }
    for (int i=E*2+1;i<=E*3;i++) if (vis[i]) return 1;
    return 0;
}

int main(){
    scanf("%d",&m);
    while (m--){
        u=_getid();
        cin >> s;
        v=_getid();
        cin >> s;
        w=atoi(s.substr(1,s.size()-2).c_str());
        h[u].pb((pi){v,w});
    }
    l=0; r=1e6+1;
    while (r-l>1){
        mid=(l+r)>>1;
        if (check(mid)) l=mid; else r=mid;
    }
    cout << r << endl;
    return 0;
}