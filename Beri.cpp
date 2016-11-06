#include <fstream>
using namespace std;
ifstream in ("beri.in");
ofstream out("beri.out");
long long n,k,q,x,y,z,c[10000001];

int main()
{
  in>>n>>k>>q>>x>>y>>z;
  long long i,cost=0,li=1,ls=n,stg,dr,mij,aux;
  long long ck=k;
  c[1]=q;
  x%=z;
  y%=z;
  for(i=2;i<=n;i++)
    c[i]=(c[i-1]*x+y)%z+k;
  x=n-k+1;
  while(li<ls)
      {stg=li;
      dr=ls;
      mij=c[(li+ls)/2];
      while(stg<=dr)
            {while(c[stg]<mij)
                stg++;
            while(c[dr]>mij)
                dr--;
            if(stg<=dr)
                {aux=c[stg];
                c[stg]=c[dr];
                c[dr]=aux;
                stg++;
                dr--;
                }
            }
     if(x<=dr)
         ls=dr;
     else
        if(x>=stg)
              li=stg;
          else
              {li=x;
              ls=x;}
      }
while(k>0)
    {cost+=c[n];
    n--;
    k--;}
cost-=(ck*(ck-1))/2;
out<<cost;
in.close();
out.close();

    return 0;
}
