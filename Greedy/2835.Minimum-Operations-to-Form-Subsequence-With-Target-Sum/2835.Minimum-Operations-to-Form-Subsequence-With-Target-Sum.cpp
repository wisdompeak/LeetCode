class Solution {
public:
    int minOperations(vector<int>& nums, int target) 
    {
        vector<int>count(31, 0);
        for (int x: nums)
        {
            int i = 0;
            while (x>0)
            {                                
                x/=2;
                i++;        
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
            while (j<i)
            {
                count[j+1] += count[j] / 2;
                count[j] %= 2;
                j++;
            }
            if (j==i && count[i]>0)
            {
                count[i] -= 1;
                continue;
            }

            while (j<31 && count[j]==0)
                j++;
            if (j==31) return -1;
            count[j] -= 1;
            for (int k=j-1; k>=i; k--)
                count[k]+=1;
            ret += j-i;
        }

        return ret;        
    }
};
