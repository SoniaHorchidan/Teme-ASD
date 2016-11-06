#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream in ("muzeu.in");
ofstream out("muzeu.out");


int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
int A[251][251], n;

struct Element
{
    int l,c,d;
}x,y;

queue <Element> coada;


int main()
{
    int i,j,k;
    char c;
    in>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            in>>c;
            if(c=='#')
                A[i][j]=-2;
            else
                if(c=='P')
                {
                    x.l=i;
                    x.c=j;
                    coada.push(x);
                    A[i][j]=0;
                }
                else
                    A[i][j]=-1;
        }
    while(!coada.empty())
    {
         x=coada.front();
         coada.pop();
        for(k=1;k<=4;k++)
        {
            y.l=x.l+dx[k];
            y.c=x.c+dy[k];
            if(A[y.l][y.c]==-1)
            {
                y.d=x.d+1;
                A[y.l][y.c]=y.d;
                coada.push(y);
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            out<<A[i][j]<<' ';
        out<<'\n';
    }

    in.close();
    out.close();

    return 0;
}
