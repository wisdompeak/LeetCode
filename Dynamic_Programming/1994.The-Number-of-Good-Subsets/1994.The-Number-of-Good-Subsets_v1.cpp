class Solution {
    long M = 1e9+7;
public:
    int numberOfGoodSubsets(vector<int>& nums) 
    {        
        unordered_set<int>Set({2,3,5,6,7,10,11,13,14,15,17,19,21,22,23,26,29,30});        
        map<int,int>Map;        
        int count1 = 0;
        for (int x: nums)
        {
            if (Set.find(x)!=Set.end())            
                Map[x]+=1;            
            if (x==1)
                count1++;
        }

        int n = Map.size();
        vector<int>count;
        vector<int>digit;
        for (auto p: Map)
        {
            digit.push_back(p.first);
            count.push_back(p.second);
        }
        
        long ret = 0;
        for (int state=1; state<(1<<n); state++)
        {
            int flag = 1;
            for (int i=0; i<n; i++)
            {
                if (((state>>i)&1)==0) continue;
                for (int j=i+1; j<n; j++)
                {                    
                    if (((state>>j)&1)==0) continue;
                    if (gcd(digit[i], digit[j])!=1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag==0)
                    break;
            }

            if (flag==0) continue;

            long ans = 1;
            for (int i=0; i<n; i++)
            {
                if (((state>>i)&1)==0) continue;
                ans *= count[i];
                ans %= M;
            }
            ret = (ret+ans) % M;
        }

        ret = ret * quickMul(2, count1) % M;
        return ret;
    }

    long quickMul(long x, long N) {
        if (N == 0) {
            return 1;
        }
        long y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y % M: y * y  % M * x % M;
    }
};
