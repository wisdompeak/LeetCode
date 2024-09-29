using LL = long long;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) 
    {
        LL n = 1;
        int t = 0;
        while (n<k)
        {
            n*=2;
            t++;
        }
        
        int count = 0;
        for (int i=t-1; i>=0; i--)
        {
            if (k>n/2)
            {
                if (operations[i]==0)
                    k = k-n/2;
                else
                {
                    k = k-n/2;
                    count++;
                }                    
            }
            n/=2;            
        }
        return 'a' + (count) % 26;
    }
};
