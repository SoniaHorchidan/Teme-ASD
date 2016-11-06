#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

queue <long long> b;
int  n;
long long s,fr[1000000],a[1000000],ok;
ifstream in("k1.in");
ofstream out("k1.out");

void citire()
{
    int i,poz=0;
    for(i=0;i<n;i++)
    {
        in>>a[i];
        fr[a[i]]++;
    }
    for(i=0;i<=10000;i++)
    {
        int k=0;
        while(k<fr[i])
        {
            a[poz]=i;
            poz++;
            k++;
        }
    }
}

long long extragere_min(int &i)
{
    long long x;
    if(i<n)
    {
        if(a[i]<=b.front() && i<n)
        {
            x=a[i];
            i++;
        }
        else
            if(!b.empty())
            {
                x=b.front();
                b.pop();
            }
        if(a[i]<=b.front() && i<n)
        {
            x+=a[i];
            i++;
        }
        else
            if(!b.empty())
            {
                x+=b.front();
                b.pop();
            }
            else
                if(i<n)
                {
                    x+=a[i];
                    i++;
                }
        b.push(x);
        return x;
    }
    if(b.size()>1)
    {
        x=b.front();
        b.pop();
        if(!b.empty())
        {
            x+=b.front();
            b.pop();
        }
        b.push(x);
        return x;
        }
}

int main()
{
     in>>n;
    citire();
    b.push(a[0]+a[1]);
    s=a[0]+a[1];
    int i=2;
    ok=1;
    while(ok)
    {
        s+=extragere_min(i);
        if(i>=n && b.size()<=1)
            ok=0;
    }
    out<<s;
    return 0;
}
