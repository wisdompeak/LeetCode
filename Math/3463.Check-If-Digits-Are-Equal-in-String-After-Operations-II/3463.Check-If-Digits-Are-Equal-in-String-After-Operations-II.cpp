using LL = long long;

class Solution {
public:
    bool hasSameDigits(string s) 
    {
        return check(s,5) && check(s,2);
    }

    long long Lucas(long long n, long long m, long long p) {
      if (m == 0) return 1;
      return (C(n % p, m % p) * Lucas(n / p, m / p, p)) % p;
    }
    
    long long C(int n, int m)
    {
        long long cnt = 1;
        for(int i = 0; i < m; i++)
        {
            cnt *= n - i;
            cnt /= i + 1;
        }
        return cnt;
    }
    
    bool check(string s, int p)
    {
        int n = s.size();

        int m = n-2;
        int ret1 = 0;
        for (int i=0; i<n-1; i++)
        {
            ret1 += (s[i]-'a') * Lucas(m, i, p) % p;            
            ret1 %= p;            
        }
                
        int ret2 = 0;
        for (int i=1; i<n; i++)
        {
            ret2 += (s[i]-'a') * Lucas(m, i-1, p) % p;
            ret2 %= p;            
        }
        
        return ret1==ret2;
    }

};
