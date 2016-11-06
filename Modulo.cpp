#include <fstream>

using namespace std;
ifstream in("modulo.in");
ofstream out("modulo.out");
int a,b,c,rez=1,power;


int main()
{  in>>a>>b>>c;
   power=a;
    while(b)
    {
        if(b & 1)
            rez=(1ll*rez*power)%c;
        power=(1ll*power*power)%c;
        b>>=1;
    }
out<<rez;

    return 0;
}
