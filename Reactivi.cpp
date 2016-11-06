#include <fstream>
#include <iostream>
using namespace std;
ifstream in("reactivi.in");
ofstream out("reactivi.out");
int n,nrfrig,fmin,fmax,minfr,maxfr;

struct reactiv
{ int tmin,tmax;
};

reactiv r[8001];

int quick( int li, int ls)
{   reactiv x;
    int stg=li, dr=ls, aux;
    x.tmin=r[li].tmin;
    x.tmax=r[li].tmax;
    while (stg<dr)
    {
        while (stg<dr && r[dr].tmin>=x.tmin)
        dr--;
        r[stg]=r[dr];
        while(stg<dr && r[stg].tmin<=x.tmin)
            stg++;
        r[dr]=r[stg];
        r[stg]=x;
    }
return stg;

}


void sortare( int li, int ls)
{if(li<ls)
    {int m=quick(li,ls);
    if(li<m)
        sortare(li,m-1);
    if(m<ls)
        sortare(m+1,ls);}
}

int main()
{    int i;
    in>>n;
    for(i=1;i<=n;i++)
        in>>r[i].tmin>>r[i].tmax;
    sortare(1,n);
    fmin=r[1].tmin;
    fmax=r[1].tmax;
    nrfrig=1;
    for(i=2;i<=n;i++)
        {
        minfr=fmin;
        maxfr=fmax;
        if(minfr<r[i].tmin)
            minfr=r[i].tmin;
        if(maxfr>r[i].tmax)
            maxfr=r[i].tmax;
        if(minfr<=maxfr)
            {fmin=minfr;
            fmax=maxfr;}
        else
            {nrfrig++;
            fmin=r[i].tmin;
            fmax=r[i].tmax;}
        }
    for(i=1;i<=n;i++)
        cout<<r[i].tmin<<' '<<r[i].tmax<<endl;
out<<nrfrig;
in.close();
out.close();

    return 0;
}
