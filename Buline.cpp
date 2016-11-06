#include <fstream>
#include <climits>
#include <iostream>
using namespace std;
ifstream in ("buline.in");
ofstream out("buline.out");
int n,suma[400001],dek[400001],v[400001];

int main()
{ in>>n;
  int a,b,i;
  int prim,ultim,p=0,smax=-INT_MAX,l=0;
  for(i=1;i<=n;i++)
      {in>>a>>b;
      if(b==1)
          {v[i]=a;
          v[n+i]=a;}
      else
          {v[i]=a*(-1);
          v[n+i]=a*(-1);}
      suma[i]=suma[i-1]+v[i];}
  for(i=n+1;i<=2*n;i++)
      suma[i]=suma[i-1]+v[i];
  prim=1;
  ultim=0;
  for(i=1;i<=2*n;i++)
      {while(suma[i]<=suma[dek[ultim]] && prim<=ultim)
              ultim--;
      ultim++;
      dek[ultim]=i;
      if(dek[prim]==i-n)
          prim++;
      if(smax<suma[i]-suma[dek[prim]])
          {smax=suma[i]-suma[dek[prim]];
          p=dek[prim]+1;
          l=i-dek[prim];}
      }
 out<<smax<<' '<<p<<' '<<l;
 in.close();
 out.close();
    return 0;
}
