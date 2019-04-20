#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int n;
inline bool check(int x) {
    for (long long i=1;i*i<=a[x];i++) {
        if (x%i==0) {
            int s=0;
            if (i>1) {
                for (int j=1;j<=n;j++) if (a[j]%i==0) s++;
                if (s>=(n+1)/2) return true;
            }
            s=0;
            long long p=a[x]/i;
            for (int j=1;j<=n;j++) if (a[j]%p==0) s++;
            if (s>=(n+1)/2) return true;
        }
    }
    return false;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    random_shuffle(a+1,a+1+n);
    for (int i=1;i<=min(n,500);i++) if (check(i))
    return puts("YES"),0;
    puts("NO");
}
