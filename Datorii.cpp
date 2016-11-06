#include <fstream>
#define tata(x) (x)/2
#define fiu_stg(x) (x)<<1
#define fiu_dr(x) ((x)<<1)+1


using namespace std;

ifstream in("datorii.in");
ofstream out("datorii.out");

int arbint[4*100005], a[100005];
int n,m,op,li,ls;


void create_arbint(int poz,int st,int dr)
{
    if(st==dr)
    {
        arbint[poz]=a[st];
        return;
    }
    int mij=(st+dr)/2;
    create_arbint(fiu_stg(poz),st,mij);
    create_arbint(fiu_dr(poz),mij+1,dr);
    arbint[poz]=arbint[fiu_stg(poz)]+arbint[fiu_dr(poz)];
}

void update(int poz, int stg, int dr, int vpoz, int val)
{
    if(stg==dr)
    {
        arbint[poz]-=val;
        return;
    }
    int mij=(stg+dr)/2;
    if(vpoz>mij)
        update(fiu_dr(poz), mij+1, dr, vpoz, val);
    else
        update(fiu_stg(poz), stg, mij, vpoz, val);
    arbint[poz]=arbint[fiu_stg(poz)]+arbint[fiu_dr(poz)];

}

int query(int poz, int stg, int dr, int L, int R)
{
    if (stg>=L && dr<=R)
        return arbint[poz];
    int s=0;
    int mij=(stg+dr)/2;
    if(L<=mij)
        s=query(fiu_stg(poz), stg, mij, L, R);
    if (R>mij)
       s+=query(fiu_dr(poz), mij+1, dr, L, R);
    return s;
}

int main()
{
    in>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        in>>a[i];
    create_arbint(1,1,n);
    for(i=1;i<=m;i++)
    {
        in>>op>>li>>ls;
        if(!op)
            update(1,1,n,li,ls);
        if(op)
         out<<query(1,1,n,li,ls)<<'\n';
    }
    in.close();
    out.close();

    return 0;
}
