#include<fstream>
#include<vector>
#define M 7919
using namespace std;
ifstream in("oite.in");
ofstream out("oite.out");
vector <long> v[M];
long long c, l, nr, i, j, k, s, oi[1024];

int main()
{
    in>>c>>l;
    for(i=1; i<=c; i++)
        in>>oi[i];
    for(i=1; i<=c-1; i++)
        {
            for(j=i+1; j<=c; j++)
            {
                s=l-oi[i]-oi[j];
                int p=s%M;
                if(s>=0)
                    for(k=0; k<v[p].size(); k++)
                        if(v[p][k]==s)
                            nr++;
            }
            for(j=1;j<i;j++)
            {
                long long sum=oi[i]+oi[j];
                v[sum%M].push_back(sum);
            }

        }
    out<<nr<<'\n';

    return 0;
}
