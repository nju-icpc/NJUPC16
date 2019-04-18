#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
const int E=100000;
const int maxn=E*3+10;
vector <pi> h[maxn];
mt19937_64 gen(time(NULL));
int except_ans=1e7;
int tp,n,m,cc;
const int M=1000000;
struct edge{
    int x,y,z;
}e[maxn*10];
void pt(int x){
    if (x<=E) printf("I[%d]",x);
    else if (x<=E*2) printf("H[%d]",x-E);
    else printf("O[%d]",x-E*2);
}
void print(edge u){
    pt(u.x);
    printf(" -> ");
    pt(u.y);
    printf(" (%d)\n",u.z);
}
void add_edge(int x,int y,int z){
    if (x>E*2) return;
    if (y<=E) return;
    if (x==y) return;
    if (x<=E&&y>E||x<=E*2&&y>E*2){
        if (z>except_ans) return;
    }
    cc++;
    e[cc]=(edge){x,y,z};
}
int main(int ac, char *argv[]){
    tp = atoi(argv[1]);
    mt19937_64 gen(123456+tp);
    if (tp>=10&&tp<20){
        // rand
        add_edge(gen()%E+1,gen()%E+1+E,gen()%M+1);
        add_edge(gen()%E+1+E,gen()%E+1+2*E,gen()%M+1);
        m=1e5*(tp-9)-2;
        for (int i=0;i<m;i++) add_edge(gen()%(E*2)+1,gen()%(E*2)+1+E,gen()%M+1);
    }
    if (tp>=20&&tp<25){
        // line
        int p[E+3];
        for (int i=1;i<=E;i++) p[i]=i;
        random_shuffle(p+1,p+E+1);
        int num=1;
        for (int i=20;i<tp;i++) num=num*10;
        for (int i=0;i<num;i++) add_edge(gen()%E+1,gen()%E+1+E,gen()%M+1);
        for (int i=0;i<num;i++) add_edge(gen()%E+1+E,gen()%E+1+E+E,gen()%M+1);
        for (int i=1;i<E;i++) add_edge(p[i]+E,p[i+1]+E,gen()%M+1);
    }
    if (tp>=25&&tp<30){
        int num=tp-24;
        for (int i=0;i<num;i++) {
            int u=gen()%E+1;
            for (int j=1;j<=E;j++) add_edge(u,j+E,gen()%M+1);
        }
        for (int i=0;i<num;i++) {
            int u=gen()%E+1+E+E;
            for (int j=1;j<=E;j++) add_edge(j+E,u,gen()%M+1);
        }
    }
    if (tp>=30&&tp<37){
        except_ans=(tp-29)*100000 + gen() % 100000;
        m=1000000-(tp-30)*100000;
        while (cc<m) add_edge(gen()%(E*2)+1,gen()%(E*2)+1+E,gen()%M+1);
    }
    cout << cc << endl;
    for (int i=1;i<=cc;i++) print(e[i]);
    return 0;
}
