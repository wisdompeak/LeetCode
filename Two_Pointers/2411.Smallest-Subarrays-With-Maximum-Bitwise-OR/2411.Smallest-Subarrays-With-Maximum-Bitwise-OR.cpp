class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        int j = n-1;
        vector<int>rets(n);
        vector<int>count(32);
        for (int i=n-1; i>=0; i--)
        {
            for (int k=0; k<32; k++)
                count[k] += ((nums[i]>>k)&1);

            
            while (j>i && isOK(nums[j], count))
            {
                for (int k=0; k<32; k++)
                    count[k] -= ((nums[j]>>k)&1);
                j--;
            }
            
            rets[i] = j-i+1;
        }
        return rets;
        
    }
    
    bool isOK(int num, vector<int>&count)
    {
        for (int k=0; k<32; k++)
        {
            if (count[k] > 0 && (count[k] - ((num>>k)&1) <= 0)) 
                return false;
        }
        return true;
    }
};
