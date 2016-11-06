#include <fstream>
#include <iostream>
using namespace std;

int n,m;
char numar[1000001], v[1000001];

int main()
{ ifstream in ("trompeta.in");
ofstream out ("trompeta.out");
in>>n>>m;
in>>numar;
int i,nr_elem=0;
v[0]=numar[0];
nr_elem=1;
for(i=1;i<n;i++)
    {while(numar[i]>v[nr_elem-1] && nr_elem>0 && n-i>m-nr_elem)
                nr_elem--;
    v[nr_elem]=numar[i];
    nr_elem++;}
out<<v;
in.close();
out.close();
    return 0;
}
