#include <iostream>
#include <fstream>
#define fiu_stg(x) (x)<<1
#define fiu_dr(x) ((x)<<1)+1

using namespace std;

ifstream in("schi.in");
ofstream out("schi.out");

int arbint[4*30005], a[30005], b[30005];
int n;

void arb_search(int vpoz,int val,int nod,int st,int dr)
{
    arbint[nod]++;
    if(st==dr)
    {
        b[st]=vpoz;
        return;
    }
    int mij=(st+dr)/2, x=mij-st+1;
    if(x-arbint[fiu_stg(nod)]>=val)
        arb_search(vpoz,val,fiu_stg(nod),st,mij);
    else
    {
        val-=x-arbint[fiu_stg(nod)];
        arb_search(vpoz,val,fiu_dr(nod),mij+1,dr);
    }
}

int main()
{
    in>>n;
    int i;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=n;i>=1;i--)
        arb_search(i,a[i],1,1,n);
    for(i=1;i<=n;i++)
        out<<b[i]<<'\n';

    in.close();
    out.close();
    return 0;
}
