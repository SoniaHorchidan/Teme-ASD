#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

std::ifstream in("teams.in");
ofstream out("teams.out");

int n,a,b,nr,smin,smax;
char s[100010];
vector <int> v;
vector <int>::iterator low,up;

void citire()
{
    in.getline(s,100010,EOF);
    int i,x;
    for(i=0; s[i]; i++)
        if(isdigit(s[i]))
        {
            x=0;
            for(;isdigit(s[i]);i++)
               x=x*10+s[i]-'0';
            v.push_back(x);
        }

}

int main()
{
    in>>n>>a>>b;
    int i;
    citire();
    sort(v.begin(), v.end());
    for(i=0;i<n-1;i++)
    {
        if(v[i]<a)
            smin=a-v[i];
        else
            smin=v[i];
        smax=b-v[i];
        low=lower_bound(v.begin()+i+1,v.end(),smin);
        up=upper_bound(v.begin()+i+1, v.end(),smax);
        if(up>v.end())
            up=v.end();
        if(up>low)
            nr+=(up-low);
       }

    out<<nr;
    in.close();
    out.close();

    return 0;
}
