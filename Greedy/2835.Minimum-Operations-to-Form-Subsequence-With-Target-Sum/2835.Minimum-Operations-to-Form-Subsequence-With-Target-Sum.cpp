class Solution {
public:
    int minOperations(vector<int>& nums, int target) 
    {
        vector<int>count(32,0);
        
        for (auto x: nums)
        {
            int i = 0;
            while (x>0)
            {
                i++;
                x/=2;
            }
            count[i-1] += 1;
        }
        
        vector<int>t;
        for (int i=0; i<31; i++)
        {
            if ((target>>i)&1)
                t.push_back(i);
        }
                
        int ret = 0;
        
        for (int i: t)
        {
            int j = 0;
            while (j < i)
            {
                count[j+1] += count[j] / 2;
                count[j] %= 2;
                j++;
            }
            if (j == i && count[j] > 0)
            {
                count[j] -= 1;
                continue;
            }            
            
            while (j<31 && count[j] == 0)
                j++;
            if (j==31) return -1;
            
            count[j] -= 1;
            for (int t=j-1; t>=i; t--)
                count[t]+=1;
            ret += j-i;
        }
        
        return ret;
    }
};
