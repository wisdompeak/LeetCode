#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7,mod=998244353;
ll inv[N];

int main() 
{
    int i;
    for(inv[1]=1,i=2;i<N;++i)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    
    // ....

    ret = ret* inv[n]%mod;   // ret = (ret / n) % M;    
}
