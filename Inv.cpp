#include <fstream>
#include <iostream>
#define c 9917
 
using namespace std;
 
ifstream in("inv.in");
ofstream out("inv.out");
 
int nr_inv,n;
int a[100005],b[100005];
 
void interclasare( int p, int m, int q)
{
    int i=p,j=m;
    for(int k=p;k<q;k++)
    {
        if(i<m&&((j>=q)||(a[i]<=a[j])))
            b[k]=a[i++];
        else
        {
            if(a[j]<a[i])
                {
                    nr_inv=nr_inv+m-i;
                    nr_inv%=c;
                }
            b[k]=a[j++];
        }
    }
}
 
void Msort(int p, int q)
{
    int i;
    if(q>p+1)
    {
        int m=(p+q)/2;
        Msort(p,m);
        Msort(m,q);
        interclasare(p,m,q);
        for(i=p;i<q;i++)
            a[i]=b[i];
    }
}
 
int main()
{
    in>>n;
    int i;
    for(i=0;i<n;i++)
        in>>a[i];
 
    Msort(0,n);
 
    out<<nr_inv;
    in.close();
    out.close();
    return 0;
}