class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int ret = 0;

        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==0) continue;
            int j = i;
            int count = 0;
            int firstNeg = -1;

            while (j<nums.size() && nums[j]!=0)
            {
                count += (nums[j]<0);
                if (count % 2 ==0)
                    ret = max(ret, j-i+1);
                else if (firstNeg!=-1)
                    ret = max(ret, j-firstNeg);

                if (firstNeg==-1 && nums[j]<0)
                    firstNeg = j;
                j++;
            }
            i = j;
        }
        return ret;
    }
};
