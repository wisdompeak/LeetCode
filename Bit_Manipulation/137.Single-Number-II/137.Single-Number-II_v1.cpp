class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        vector<int>bits(32,0);
        
        for (int i=0; i<nums.size(); i++)
        {
            int k=nums[i];
            for (int j=0; j<32; j++)
            {
                bits[j]+=((k>>j)&1);
            }            
        }
        
        int result=0;
        for (int j=0; j<32; j++)
        {
            if (bits[j]%3!=0)
                result+= 1<<j;
        }
        
        return result;
    }
};
