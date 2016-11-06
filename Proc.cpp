#include <iostream>
#include <fstream>

using namespace std;

ifstream in("proc.in");
ofstream  out("proc.out");

long long n, p, k, d, tmin;

int verifica(long long T)
{
    long long x=0, y=0,m, i;
    for(i=1;i<=p;i++)
    {
        x+=T/i/2;
        y+=T/i%2;
    }
    if(x>=d && ((y+2*(x-d))>=k))
        return 1;
    return 0;
}


int main()
{
    in>>n>>k>>p;
    d=n-k;
    long long li=0, ls=2*n;
    tmin=ls;
    while(li<=ls)
    {
        long long mij=(li+ls)/2;
        if(verifica(mij))
        {
            tmin=mij;
            ls=mij-1;

        }
        else
            li=mij+1;
    }

    out<<tmin;
    in.close();
    out.close();

    return 0;
}
