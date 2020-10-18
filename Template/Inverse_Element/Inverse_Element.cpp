#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 1e6+7, mod = 998244353;
LL inv[N];

/*********************************/
// Linear method to compute inv[i]
void main() 
{    
    int i;
    for(inv[1]=1,i=2;i<N;++i)
        inv[i]=(mod-mod/i) * inv[mod%i] % mod;
    
    ret = ret* inv[n] % mod;   // ret = (ret / n) % mod;    
}

/*********************************/
// Qucik Pow

LL quickPow(int x, int y) 
{
    LL ret = 1;
    LL cur = x;
    while (y) 
    {
        if (y & 1) 
        {
            ret = (LL)ret * cur % mod;
        }
        cur = (LL)cur * cur % mod;
        y >>= 1;
    }
    return ret;
}

LL inv(LL x) 
{
    return quickPow(x, mod - 2);
}
