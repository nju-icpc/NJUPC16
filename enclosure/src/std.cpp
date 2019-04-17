#include<bits/stdc++.h>
using namespace std;
int x[4],y[4];
int main(){
    for (int i=0;i<4;i++) cin >> x[i] >> y[i];
    if (x[1]<x[2]
        ||x[3]<x[0]
        ||y[1]<y[2]
        ||y[3]<y[0]
        ||x[2]<x[0]&&x[1]<x[3]&&y[2]<y[0]&&y[1]<y[3]
        ||x[0]<x[2]&&x[3]<x[1]&&y[0]<y[2]&&y[3]<y[1]) puts("3");
    else if (x[2]<x[0]&&x[1]<x[3]&&y[0]<y[2]&&y[3]<y[1]
        ||x[0]<x[2]&&x[3]<x[1]&&y[2]<y[0]&&y[1]<y[3]) puts("6");
    else puts("4");
}
