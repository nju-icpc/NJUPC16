#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef unsigned long long ull;
const ull E=1000000000000ull;
const ull D=1000000;
int N;
int cnt;
ull mp,bp[25],ap[25],p[35],a[maxn];
mt19937_64 gen;
ull myrand(ull E){
    return (gen())%E+1;
}
bool is_prime(ull x){
    for (ull i=2;i*i<=x;i++) if (x%i==0) return false;
    return true;
}

int main(int argc, char* argv[]) {
    int type = atoi(argv[1]);
    N = atoi(argv[2]);
    int shuf = atoi(argv[3]);
    int seed = atoi(argv[4]);
    gen.seed(seed);

    p[0]=2;
    for (int i=1;i<=30;i++){
        p[i]=p[i-1]+1;
        while (!is_prime(p[i])) p[i]++;
    }
    mp=myrand(1e8)+9e8;
    while (!is_prime(mp)) mp++;
    for (int i=0;i<20;i++){
        bp[i]=myrand(E/5)+E*3/4;
        while (!is_prime(bp[i])) bp[i]++;
        //cout << bp[i] << endl;
    }
    for (int i=0;i<20;i++){
        ap[i]=myrand(D/5)+D*3/4;
        while (!is_prime(ap[i])) ap[i]++;
        //cout << ap[i] << endl;
    }
    if (type == 1) {
        for (int i=0;i<N;i++) a[++cnt]=myrand(E);
    } else if (type == 2) {
        for (int i=0;i<N;i++) a[++cnt]=bp[gen()%20];
    } else if (type == 3) {
        for (int i=0;i<N/3;i++) a[++cnt]=ap[0]*ap[1];
        for (int i=0;i<N/3;i++) a[++cnt]=ap[0]*ap[2];
        for (int i=0;i<N/3;i++) a[++cnt]=ap[1]*ap[2];
    } else if (type == 4) {
        for (int i=0;i<20;i++){
            for (int j=0;j<N/40;j++) a[++cnt]=mp*p[i];
            for (int j=0;j<N/40;j++) a[++cnt]=bp[i];
        }
    } else if (type == 5) {
        for (int i=0;i<N;i++) a[++cnt]=(ull)128*81*25*7*11*13*17*19;
    } else if (type == 6) {
        for (int i=0;i<N/2-1;i++) a[++cnt]=(ull)128*81*25*7*11*13*17*19;
        for (int i=0;i<N/4;i++) a[++cnt]=bp[0];
        for (int i=0;i<N/4+1;i++) a[++cnt]=bp[1];
    } else if (type == 7) {
        for (int i=0;i<N;i++) a[++cnt]=bp[gen()%2];
    } else if (type == 8) {
        for (int i=0;i<N/2-1;i++) a[++cnt]=2;
        for (int i=0;i<N/2-1;i++) a[++cnt]=3; 
        a[++cnt]=5;
    } else if (type == 9) {
        for (int i=0;i<5;i++) for (int j=i+1;j<5;j++)
        for (int k=0;k<N/10;k++) a[++cnt]=ap[i]*ap[j];
    } else if (type == 10) {
        for (int i=0;i<4;i++) for (int j=i+1;j<4;j++)
        for (int k=0;k<N/6;k++) a[++cnt]=ap[i]*ap[j];
        a[++cnt]=ap[6]*ap[7];
    } else if (type == 11) {
        int X=11; //X=16;
        for (int i=0;i<N;i++){
            ull res=1;
            for (int j=0;j<8;j++) res*=p[gen()%X];
            a[++cnt]=res;
        }
    } else if (type == 12) {
        int X=12;
        for (int i=0;i<N;i++){
            ull res=1;
            for (int j=0;j<6;j++) res*=p[gen()%X];
            a[++cnt]=res;
        }
    } else if (type == 13) { 
        ull res=1; for (int i=0;i<20;i++) if (res*p[i]<=E) res*=p[i];
        for (int i=0;i<N;i++) a[++cnt]=res;
    } else if (type == 14) {
        for (int i=0;i<3;i++) for (int j=i;j<3;j++)
        for (int k=0;k<N/6;k++) a[++cnt]=ap[i]*ap[j];
    } else if (type == 15) {
        for (int i=0;i<N;i++) a[++cnt]=ap[gen()%20]*ap[gen()%20];
    } else if (type == 16) {
        for (int i=0;i<N/2;i++) a[++cnt]=myrand(E);
        for (int i=0;i<N/2-1;i++) a[++cnt]=bp[0];
    } else if (type == 17) {
        for (int i=0;i<N/2;i++) a[++cnt]=myrand(E);
            for (int i=0;i<N/2;i++) a[++cnt]=ap[0]*ap[gen()%20];
    } else if (type == 18) {
        for (int i=0;i<N/2;i++) a[++cnt]=ap[gen()%20]*ap[0];
        for (int i=0;i<N/2-1;i++) a[++cnt]=(ull)128*81*25*7*11*13*17*19;
    }
    printf("%d\n", cnt);
    if (shuf) shuffle(a+1, a+cnt+1, mt19937(~seed));
    for (int i=1;i<cnt;i++) printf("%llu ",a[i]);
    printf("%llu\n",a[cnt]);
    return 0;
}
