#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_board=1000000001;
mt19937_64 gen;
int a[4],b[4],tp;
int p[4],q[4];
int main(int argc, char *argv[]){
    tp = atoi(argv[1]);
    gen.seed(2358297 + tp);
    while (true){
        for (int i=0;i<4;i++) b[i]=gen()%max_board;
        sort(b,b+4);
        bool flag=0;
        for (int i=0;i<3;i++) if (b[i]==b[i+1]) flag=1;
        if (!flag) break;
    }
    for (int i=0;i<4;i++) a[i]=b[i];
    while (true){
        for (int i=0;i<4;i++) b[i]=gen()%max_board;
        sort(b,b+4);
        bool flag=0;
        for (int i=0;i<3;i++) if (b[i]==b[i+1]) flag=1;
        if (!flag) break;
    }
    cin >> tp;
    int o=tp%2;
    tp/=2;
    if (tp%3==0) {
        p[0]=a[0]; p[2]=a[1];
        q[0]=a[2]; q[2]=a[3];
    } else if (tp%3==1) {
        p[0]=a[0]; p[2]=a[2];
        q[0]=a[1]; q[2]=a[3];
    } else if (tp%3==2) {
        p[0]=a[0]; p[2]=a[3];
        q[0]=a[1]; q[2]=a[2];
    }
    tp/=3;
    if (tp%3==0) {
        p[1]=b[0]; p[3]=b[1];
        q[1]=b[2]; q[3]=b[3];
    } else if (tp%3==1) {
        p[1]=b[0]; p[3]=b[2];
        q[1]=b[1]; q[3]=b[3];
    } else if (tp%3==2) {
        p[1]=b[0]; p[3]=b[3];
        q[1]=b[1]; q[3]=b[2];
    }
    tp/=3;
    if (tp) swap(p[1],q[1]),swap(p[3],q[3]);
    if (o){
        for (int i=0;i<4;i++) swap(p[i],q[i]);
    }
    for (int i=0;i<4;i++) cout << p[i] << (i == 3 ? '\n' : ' ');
    for (int i=0;i<4;i++) cout << q[i] << (i == 3 ? '\n' : ' ');
}
