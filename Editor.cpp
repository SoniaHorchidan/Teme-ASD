#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
int t;
char s[60000];
vector <char> stiva;
stack <char> stiva2;

int main()
{ ifstream in("editor.in");
ofstream out("editor.out");
int i,j,x;
in>>t;
for(i=1;i<=t;i++)
    {while(stiva.size()>0)
        stiva.pop_back();
    while(stiva2.size()>0)
        stiva2.pop();
    in>>s;
    x=strlen(s);
    for(j=0;j<x;j++)
        if(s[j]=='*' && stiva.size()>0)
            stiva.pop_back();
        else
            if(s[j]!='*')
                stiva.push_back(s[j]);
    stiva.pop_back();
    if(stiva.size()==0)
        out<<":)\n";
    else
        {if(stiva[0]==')' || stiva[0]==']')
            out<<":(\n";
        else
            {stiva2.push(stiva[0]);
            x=stiva.size();
            for(j=1;j<x;j++)
                if(stiva2.size()==0)
                    stiva2.push(stiva[j]);
                else
                    {if(stiva2.top()=='(' && stiva[j]==')')
                       stiva2.pop();
                    else
                        if(stiva2.top()=='[' && stiva[j]==']')
                                stiva2.pop();
                        else
                            stiva2.push(stiva[j]);
                    }
            if(stiva2.size()==0)
                out<<":)\n";
            else
                out<<":(\n";
            }

        }
    }
in.close();
out.close();

    return 0;
}
