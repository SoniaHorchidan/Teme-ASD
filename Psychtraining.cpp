#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("psychtraining.in");
ofstream out ("psychtraining.out");

int n,m,nr;
char v[15][510];

void rezolva(int li, int ls, int nivel)
{   int i;
    if(nivel>10)
        return ;
    else
    {
        int mij=(li+ls)/2;
        for(i=li; i<=ls; i++)
            if(i<=mij)
                v[nivel][i]='a';
            else
                v[nivel][i]='b';
        rezolva(li,mij, nivel+1);
        rezolva(mij+1,ls,nivel+1);

    }
}

int main()
{
    int i, j;
    in>>n>>m;
   /* while(p<n)
        p*=2;*/

    out<<"10"<<'\n';
    rezolva(1,n,1);
    for(i=1; i<=10; i++)
        {for(j=1;j<=n;j++)
            out<<v[i][j];
        out<<'\n';}

    in.close();
    out.close();

    return 0;
}
