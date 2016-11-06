#include <fstream>

using namespace std;

ifstream in("stergeri.in");
ofstream out("stergeri.out");

long long n;
int m, k;

struct
{
    int x,y;

}v[100005];


int main()
{

    int i;
    in>>n>>m>>k;
    for(i=1;i<=m;i++)
        in>>v[i].x>>v[i].y;
    for(i=m;i>=1;i--)
        if(k>=v[i].x)
            k+=v[i].y-v[i].x+1;
    out<<k;
    in.close();
    out.close();

    return 0;
}
