#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("loto.in");
ofstream out("loto.out");

struct tip
{
   long long suma;
   long long a, b, c;
}sume[1000005];

long long n, v[105],elem[8];
long long s,p=1;

int compara(tip a,tip b)
{
    if(a.suma<b.suma)
        return 1;
    else
        return 0;
}

void afisare(tip x, tip y)
{
    out<<v[x.a]<<' '<<v[x.b]<<' '<<v[x.c]<<' '<<v[y.a]<<' '<<v[y.b]<<' '<<v[y.c];
}


void cauta()//long long x, long long &r, long long &s, long long &t, long long li, long long ls)
{
   int i,j,mij;
    long long s1,s2;
    i=1;j=p-1;
    while(i<=j)
    {
        s1=sume[i].suma;
        s2=s-sume[i].suma;
        while(i<=j && sume[j].suma>s2)
            j--;
        if(i>j)
        {
            out<<"-1";
            break;
        }
        if (sume[j].suma!=s2)
        {
            i++;
            continue;
        }
        afisare(sume[i], sume[j]);
        break;
    }
    if (i>j)
        out<<"-1";


}

int main()
{
    in>>n>>s;
    long long i,j,k,ok=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0;
    long long ss=0;
    for(i=1;i<=n;i++)
        in>>v[i];
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            for(k=j;k<=n;k++)
                {
                    sume[p].suma=v[i]+v[j]+v[k];
                    sume[p].a=i;
                    sume[p].b=j;
                    sume[p].c=k;
                    p++;
                }
    sort(sume+1,sume+p,compara);
    cauta();

    in.close();
    out.close();


    return 0;
}
