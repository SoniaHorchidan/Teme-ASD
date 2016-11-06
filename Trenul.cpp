#include <iostream>
#include <fstream>
using namespace std;
ifstream in("trenul.in");
ofstream out("trenul.out");
int n, m;
 
int main()
{
    in>>n>>m;
    int q, i, prim=1, ultim=n;
    for(i=1;i<=m;i++)
    {
        in>>q;
        if(q==2)
        {
            out<<prim<<' '<<prim+1<<"\n";
            prim+=2;
        }
        else
            if(q==3)
            {
                out<<ultim<<' '<<ultim-1<<' '<<ultim-2<<"\n";
                ultim-=3;
            }
            else
                if(q==1)
                {
                    out<<ultim<<"\n";
                    ultim--;
                }
    }
    in.close();
    out.close();
    return 0;
}