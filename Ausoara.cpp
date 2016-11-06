#include <fstream>
using namespace std;
ifstream in("ausoara.in");
ofstream out("ausoara.out");
int n,m;
int sir[10000];
 
int main()
{
    int i,j,l,x,p,pp;
    in>>n>>m;
    l=m;
    for(i=0;i<m;i++)
        in>>sir[i];
    n--;
    for(i=1;i<=n;i++)
    {
 
        in>>m;
        p=0;
        pp=0;
        for(j=0;j<m;j++)
        {
            in>>x;
            while(x>sir[p] && p<l)
                p++;
            if(x==sir[p] && p<l)
            {
                sir[pp]=sir[p];
                p++;
                pp++;
            }
        }
        l=pp;
    }
    out<<l<<' ';
    for(i=0;i<l;i++)
        out<<sir[i]<<' ';
 
    in.close();
    out.close();
    return 0;
}