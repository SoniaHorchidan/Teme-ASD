#include <fstream>
 
using namespace std;
long long k, ciur[1500000];
 
int main()
{ ifstream in("prim.in");
ofstream out ("prim.out");
long long i,j;
in>>k;
for(i=2;i<1500000;i++)
    ciur[i]=1;
for(i=2;i*i<=1500000;i++)
    if(ciur[i])
        for(j=2;j*i<1500000;j++)
            ciur[i*j]=0;
i=0;
j=0;
while(i<=k)
    {if(ciur[j])
        i++;
    j++;}
j--;
out<<j*j;
in.close();
out.close();
    return 0;
}
