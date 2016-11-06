#include <fstream>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

ifstream in("calandrinon.in");
ofstream out("calandrinon.out");

int n, fr[30];
bool ap[30];
char sir[1000001];
stack <char> s;


int main()
{
    in>>n;
    in>>sir;
    int i;
    for(i=0; i<n; i++)
        fr[sir[i]-'a']++;
    for(i=0; i<n; i++)
    {
        if(ap[sir[i]-'a']==0)
            {
                while(!s.empty() && sir[i]<s.top() && fr[s.top()-'a']!=1)
                {
                    ap[s.top()-'a']=0;
                    fr[s.top()-'a']--;
                    s.pop();
                }
                s.push(sir[i]);
                ap[sir[i]-'a']=1;
            }
            else
                fr[sir[i]-'a']--;

          }

    i=0;
    while(s.size()!=0)
        {
            sir[i]=s.top();
            s.pop();
            i++;
        }
    sir[i]=NULL;
    char aux;
    for(int j=0; j<=(i-1)/2; j++)
    {
        aux=sir[j];
        sir[j]=sir[i-1-j];
        sir[i-1-j]=aux;
    }
    out<<sir;
    in.close();
    out.close();


    return 0;
}
