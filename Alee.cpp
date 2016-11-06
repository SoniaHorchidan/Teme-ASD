#include <iostream>
#include <fstream>
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

struct Element
{ int l,c;
unsigned d;
};

Element C[176*176],x,y;
int A[180][180],n,m,x1,y1,x2,y2,i,j,k,IncC,SfC,p,q;

int main()
{ ifstream f("alee.in");
ofstream g("alee.out");
f>>n>>m;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        A[i][j]=-2;
for(i=1;i<=m;i++)
    {f>>p>>q;
    A[p][q]=-1;}
f>>x1>>y1>>x2>>y2;
for(i=1;i<=n;i++)
    A[i][0]=A[i][n+1]=-1;
for(i=1;i<=n;i++)
    A[0][i]=A[n+1][i]=-1;

x.l=x1;
x.c=y1;
A[x1][y1]=0;
C[IncC]=x;

int ok=0;
while(IncC<=SfC&&ok==0)
{ x=C[IncC++];
for(k=1;k<4;k++)
    {y.l=x.l+dx[k];
    y.c=x.c+dy[k];
    if(y.l==x2&&y.c==y2)
        {A[y.l][y.c]=y.d+1;
        ok=1;}
    else
        if(A[y.l][y.c]==-2)
            {y.d=x.d+1;
            A[y.l][y.c]=y.d;
            C[++SfC]=y;
            }
    }
}

g<<A[x2][y2]+1;

f.close();
g.close();



    return 0;
}
