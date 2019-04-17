#include<bits/stdc++.h>
using namespace std;
int tp,n,m,a,b,c[105];
mt19937_64 gen;

int main(int argc, char* argv[]){
    tp = atoi(argv[1]);
    gen.seed(2385629 + tp);
    if (tp==0) printf("5 2 4\n1 1 1 5 5\n");
    else if (tp==1) printf("5 2 4\n1 1 1 3 5\n");
    else if (tp<8){
        // all 1.0
        int d=tp;
        n=gen()%13+6;
        a=5*d,b=a+gen()%(d-1)+1;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",d); printf("%d\n",d);
    } else if (tp<14){
        // all 1.0
        int d=tp;
        n=gen()%13+6;
        b=5*d,a=b-gen()%(d-1)-1;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",d); printf("%d\n",d);
    } else if (tp<24){
        // small gen
        n=10;
        int sum=0;
        for (int i=1;i<=n;i++) c[i]=gen()%10+1,sum+=c[i];
        b=min(100,sum-1-int(gen()%6));
        a=b-1-gen()%5;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<29){
        // big gen
        n=100;
        int sum=0;
        for (int i=1;i<=n;i++) c[i]=gen()%100+1,sum+=c[i];
        b=min(100,sum/2+int(gen()%50));
        a=b-1-gen()%50;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<34){
        // m small + (n-m) huge
        n=100;
        int m=10+(tp-29)*20;
        a=80+gen()%10; b=a+1+gen()%10;
        for (int i=1;i<=m;i++) c[i]=gen()%10+1;
        for (int i=m+1;i<=n;i++) c[i]=50+gen()%50+1;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<36){
        // all 1
        n=gen()%50+11;
        a=n/2; b=n/2+gen()%3+1;
        for (int i=1;i<=n;i++) c[i]=1;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<38){
        // b-a very large
        n=100;
        int sum=0;
        for (int i=1;i<=n;i++) c[i]=gen()%40+1,sum+=c[i];
        b=min(100,sum/2); a=b-80;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<42){
        // b-a very small
        n=100;
        int sum=0;
        for (int i=1;i<=n;i++) c[i]=gen()%20+21,sum+=c[i];
        b=91+rand()%10; a=b-1-gen()%3;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<44){
        // many 2 and one 1
        n=36+gen()%36; a=tp; b=tp+1;
        for (int i=1;i<=n;i++) c[i]=2;
        c[gen()%n+1]=1;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    } else if (tp<50){
        // many 3 and two 2
        n=25+gen()%25; a=tp; b=tp+1+(tp-44)/3;
        for (int i=1;i<=n;i++) c[i]=3;
        c[gen()%(n-1)+2]=1; c[1]=1;
        printf("%d %d %d\n",n,a,b);
        for (int i=1;i<n;i++) printf("%d ",c[i]); printf("%d\n",c[n]);
    }
    return 0;
}
