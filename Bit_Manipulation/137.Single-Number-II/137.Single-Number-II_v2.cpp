class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int count1 = 0, count2 = 0;
        for (auto x: nums)
        {
            int count1_new = 0, count2_new = 0;
            for (int i=0; i<32; i++)
            {
                int hi = (count1>>i)&1;
                int low = (count2>>i)&1;
                int sum = (hi*2+low+((x>>i)&1))%3;
                count1_new |= ((sum/2)<<i);
                count2_new |= ((sum%2)<<i);
            }       
            count1 = count1_new, count2 = count2_new;     
        }

        int ret = 0;
        for (int i=0; i<32; i++)
        {
            ret += ((count2>>i)&1)<<i;
        }
        return ret;
    }
};
