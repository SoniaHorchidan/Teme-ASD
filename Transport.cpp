#include <fstream>

using namespace std;
ifstream in("transport.in");
ofstream out("transport.out");
int n,k,suma,v[16001],minim,stg,dr;

int verificare(int mij,int k)
{   int i=1,suma;
    while(i<=n && k>0)
        {suma=0;
        while(i<=n && suma<mij )
            {suma+=v[i];
            i++;
            }
        if(suma>mij)
            i--;
        k--;
        }
    if(i<=n)
        return 0;
    return 1;
}


int main()
{   in>>n>>k;
    int i,mij;
    for(i=1;i<=n;i++)
        {in>>v[i];
        if(v[i]>stg)
            stg=v[i];
        suma+=v[i];
        }
    dr=suma;
    while(stg<suma)
        { mij=(stg+suma)/2;
         if(!verificare(mij,k))
            stg=mij+1;
         else
            {suma=mij;
            dr=mij;}
        }
out<<dr;
in.close();
out.close();


    return 0;
}
