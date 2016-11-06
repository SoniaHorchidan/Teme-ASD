#include <iostream>
#include <fstream>
using namespace std;
ifstream in("reactii.in");
ofstream out ("reactii.out");
int n,m,nr;

struct interval
{ int li,ls;
}s[15000];


int divide()
{ if(s[nr-1].ls+1==s[nr].li)
    {s[nr-1].ls=s[nr].ls;
    nr--;
    return 1;}
else
    if(s[nr-1].li==s[nr].ls+1)
        { s[nr-1].li=s[nr].li;
        nr--;
        return 1;}
return 0;

}

int main()
{ in>>n>>m;
int i,x;
while(m>0)
    {nr=0;
    for(i=1;i<=n;i++)
        {in>>x;
        nr++;
        s[nr].li=x;
        s[nr].ls=x;
        while(nr>1 && divide());}
    if(nr==1)
        out<<1<<endl;
    else
        out<<0<<endl;
    m--;
    }
in.close();
out.close();

    return 0;
}
