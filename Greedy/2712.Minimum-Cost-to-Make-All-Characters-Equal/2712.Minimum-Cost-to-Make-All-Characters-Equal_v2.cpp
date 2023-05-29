using LL = long long;
class Solution {
public:
    long long minimumCost(string s) 
    {
        LL ret1 = solve(s);
        for (int i=0; i<s.size(); i++)
            if (s[i]=='1')
                s[i]='0';
            else
                s[i]='1';
        LL ret2 = solve(s);
        return min(ret1,ret2);
    }
    
    LL solve(string s)
    {
        int total = 0;
        int n = s.size();
        for (int i=0; i<n; i++)
            total += (s[i]=='1');
        
        vector<LL>left(n);
        int lastOne = -1;
        LL sum = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='0')
            {
                left[i] = sum;
                continue;                
            }
            
            if (i>=1 && s[i-1]=='1')
                sum = sum+1;
            else
                sum += (i+1) + i;

            left[i] = sum;
            lastOne = i;
        }
        
        vector<LL>right(n);
        lastOne = n;
        sum = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i]=='0')
            {
                right[i] = sum;
                continue;                
            }
            
            if (i+1<n && s[i+1]=='1')
                sum  = sum+1;
            else
                sum += (n-i) + (n-i-1);
            right[i] = sum;
            lastOne = i;
        }
        
        LL ret = right[0];
        for (int i=0; i<n-1; i++)
            ret = min(ret, left[i]+right[i+1]);
        return ret;
    }
};
