#include<bits/stdc++.h>
#define maxn 200005

using namespace std;
typedef long long ll;
bool flag;
int n,t;
const int E=25;
const int D=1000000;
ll tmp,prime[maxn],p[D+5],a[maxn];
mt19937 gen(time(NULL));

void prime_sieve(int n){
    p[1]=1; t=0;
    for (int i=2;i<=n;i++){
        if (!p[i]) prime[++t]=i;
        for (int j=1;j<=t;j++){
            if (1ll*prime[j]*i>n) break;
            p[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
}

void check(ll x){
    int cnt=0;
    for (int i=0;i<n;i++) if (a[i]%x==0) cnt++;
    if (cnt*2>=n) flag=true;
}

int main(){
    cin >> n;
    prime_sieve(D); flag=false;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int o=0;o<E;o++){
        tmp=a[rand()%n];
        for (int i=1;i<=t;i++){
            if (tmp%prime[i]==0){
                check(prime[i]);
                while (tmp%prime[i]==0) tmp/=prime[i];
            }
            if (1ll*prime[i]*prime[i]>tmp) break;
        }
        if (tmp>1) check(tmp);
        if (flag){puts("YES"); fprintf(stderr, "YES\n"); return 0;}
    }
    puts("NO"); fprintf(stderr, "NO\n");
    return 0;
}
