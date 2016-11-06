#include<fstream>
using namespace std;
ifstream in ("densitate.in");
ofstream out("densitate.out");
int n,q,a,b,nr_prm[500001];
bool ciur[500001];

int main()
{ in>>n>>q;
int i,j;
for(i=2;i<=n;i++)
    ciur[i]=1;
for(i=2;i*i<=n;i++)
    if(ciur[i])
        for(j=2;j*i<=n;j++)
            ciur[i*j]=0;
for(i=1;i<=n;i++)
    nr_prm[i]=nr_prm[i-1]+ciur[i];

while(q)
    {in>>a>>b;
    out<<nr_prm[b]-nr_prm[a-1]<<'\n';
    q--;}

in.close();
out.close();
    return 0;
}
