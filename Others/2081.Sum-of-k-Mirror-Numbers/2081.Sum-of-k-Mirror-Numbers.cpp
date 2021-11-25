using LL = long long;
class Solution {
    int temp[100];
public:
    long long kMirror(int k, int n) 
    {                
        int d = 1;
        vector<LL>rets;
            
        while (1)
        {            
            if (d%2==0)            
            {
                int len = d/2;
                for (LL i=pow(10, len-1); i<pow(10, len); i++)
                {
                    LL a = getPalindrome(i, 0);
                    if (checkOK(a, k))
                        rets.push_back(a);
                    if (rets.size()==n)
                        return accumulate(rets.begin(), rets.end(), 0LL);
                }
            }
            else 
            {
                int len = d/2+1;
                for (LL i=pow(10, len-1); i<pow(10, len); i++)
                {                    
                    LL a = getPalindrome(i, 1);                                        
                    if (checkOK(a, k))
                        rets.push_back(a);
                    if (rets.size()==n)
                        return accumulate(rets.begin(), rets.end(), 0LL);
                }
            }
            d++;
        }
        
        return 0;
    }
    
    LL getPalindrome(LL x, int flag)
    {
        LL y = x;
        LL z = 0;
        int count = 0;
        while (y>0)
        {            
            count++;
            z = z*10+(y%10);
            y/=10;
        }
        
        if (flag==1) x /= 10;
        
        for (int i=0; i<count; i++)
            x = x*10;
        
        return x+z;            
    }
    
    bool checkOK(LL x, int k)
    {
        int t = 0;        
        while (x>0)
        {
            temp[t] = x%k;
            x/=k;
            t++;
        }
        int i = 0, j = t-1;
        while (i<j)
        {
            if (temp[i]!=temp[j])
                return false;
            i++;
            j--;
        }        
        return true;
    }
};
