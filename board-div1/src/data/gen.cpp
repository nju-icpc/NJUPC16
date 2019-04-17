#include<bits/stdc++.h>
using namespace std;
int a[1005][13],p[13],c[1005][13],n,m,t[13],f[13];
int _G(int x,int y){
    while (1){
        int ret=rand()%299+1;
        bool flag=0;
        for (int i=0;i<y;i++) if (c[x][i]==ret) flag=1;
        if (flag) continue;
        return ret;
    }
}

int main(int argc, char* argv[]){
    int tp = atoi(argv[1]);
    mt19937 gen(20193840+tp);
    if (tp==0){
        printf("3 3\n80 90 100\n10 20 100\n- 5 15\n");
        return 0;
    } else if (tp==1){
        printf("5 4\n30 50 - 115\n80 15 75 -\n30 40 - 120\n70 80 180 105\n- - 1 -\n");
        return 0;
    } else if (tp<6){
        //small-small rand
        n=tp*2; m=10;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                if (gen()%4==0) c[i][j]=-1;
                else c[i][j]=_G(i,j);
            }
    } else if (tp<10){
        //big-small rand
        n=1000; m=10;
        for (int i=0;i<m;i++) c[0][i]=1+i;
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++){
                if (gen()%4==0) c[i][j]=-1;
                else c[i][j]=_G(i,j);
            }
    } else if (tp<12){
        //small-all fb
        n=1000; m=10;
        for (int i=0;i<m;i++) f[i]=10*(i+1);
        for (int i=0;i<m;i++) c[0][i]=f[i];
        random_shuffle(f,f+m);
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++)
                c[i][j]=rand()%10+f[j];
    } else if (tp<14){
        //small-notall fb
        n=1000; m=10;
        for (int i=0;i<m;i++) f[i]=10*(i+1);
        for (int i=0;i<m;i++) c[0][i]=f[i];
        random_shuffle(f,f+m);
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++)
                c[i][j]=rand()%10+f[j]-1;
    } else if (tp<16){
        //several fb
        n=1000; m=13;
        int p=5+rand()%3;
        for (int i=0;i<m;i++) f[i]=10*(i+1);
        for (int i=0;i<m;i++) c[0][i]=f[i];
        random_shuffle(f,f+m);
        for (int i=0;i<m;i++) f[i]=min(f[i],p*10);
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++){
				int t;
				while (t){
					t=rand()%10+f[j];
					bool flag=0;
					for (int k=0;k<j;k++) if (c[i][k]==t) flag=1;
					if (flag) continue;
					break;
				}
                c[i][j]=t;
			}
    } else if (tp<18){
        //big-big rand
        n=1000; m=13;
        for (int i=0;i<m;i++) c[0][i]=1+i;
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++){
                if (gen()%4==0) c[i][j]=-1;
                else c[i][j]=_G(i,j);
            }
    } else if (tp<20){
        //big-all fb
        n=1000; m=13;
        for (int i=0;i<m;i++) f[i]=10*(i+1);
        for (int i=0;i<m;i++) c[0][i]=f[i];
        random_shuffle(f,f+m);
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++)
                c[i][j]=rand()%10+f[j];
    } else if (tp<22){
        //big-notall fb
        n=1000; m=13;
        for (int i=0;i<m;i++) f[i]=10*(i+1);
        for (int i=0;i<m;i++) c[0][i]=f[i];
        random_shuffle(f,f+m);
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++)
                c[i][j]=rand()%10+f[j]-1;
    } else if (tp==22){
        //special
        n=1000; m=10;
        for (int i=0;i<m;i++) c[0][i]=-1;
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++){
                if (gen()%4==0) c[i][j]=-1;
                else c[i][j]=_G(i,j);
            }
    } else if (tp==23){
        //special
        n=1000; m=10;
        for (int i=0;i<m;i++) c[0][i]=i+1;
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++){
                c[i][j]=-1;
            }
    } else if (tp==24){
        //special
        n=5; m=10;
        for (int i=0;i<m;i++) c[0][i]=-1;
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++){
                if (gen()%8==0) c[i][j]=_G(i,j);
                else c[i][j]=-1;
            }
    } else if (tp==25){
        printf("2 1\n-\n-\n");
        return 0;
    } else if (tp==26){
        printf("2 1\n15\n-\n");
        return 0;
    } else if (tp==27){
        printf("2 1\n-\n15\n");
        return 0;
    } else if (tp==28){
        printf("2 2\n10 40\n20 25\n");
        return 0;
    } else if (tp==29){
        printf("2 2\n25 20\n10 30\n");
        return 0;
    }
    printf("%d %d\n",n,m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) if (j==m-1) {
            if (c[i][j] == -1) printf("-\n");
            else printf("%d\n",c[i][j]); 
        } else {
            if (c[i][j] == -1) printf("- ");
            else printf("%d ",c[i][j]);
        }
    }
}
