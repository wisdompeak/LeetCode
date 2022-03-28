using LL = long long;
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) 
    {
        vector<LL>rets;
        for (int k: queries)
        {
            if (intLength==1)
            {
                if (k>9)
                    rets.push_back(-1);
                else
                    rets.push_back(k);                
                continue;
            }
            
            if (intLength%2==0)
            {
                int m = intLength/2;
                if (k > 9*pow(10, m-1))
                {
                    rets.push_back(-1);
                    continue;
                }
                else
                {
                    LL a = pow(10, m-1) + k - 1;
                    LL b = flip(a);
                    rets.push_back(a*pow(10,m)+b);                    
                }
            }
            else
            {
                int m = intLength/2;
                if (k > 9*pow(10, m-1)*10)
                {
                    rets.push_back(-1);
                    continue;
                }
                else
                {
                    LL k1 = (k-1)/10;
                    LL k2 = (k-1)%10;
                    
                    LL a = pow(10, m-1) + k1;
                    LL b = flip(a);
                    LL c = k2;
                    
                    rets.push_back(a*pow(10,m+1)+c*pow(10,m)+b);                    
                }
            }            
        }
        return rets;
    }
    
    LL flip(LL x)
    {
        LL ret = 0;
        while (x>0)
        {
            ret = ret*10+(x%10);
            x/=10;
        }
        return ret;
    }
};
