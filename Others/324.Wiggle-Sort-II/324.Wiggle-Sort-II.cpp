class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        int i = (N-1)/2;
        int j = N-1;
        
        int flag = 0;
        vector<int>result;
        for (int k=0; k<N; k++)
        {
            if (flag==0)
            {
                result.push_back(nums[i]);
                i--;
            }
            else
            {
                result.push_back(nums[j]);
                j--;
            }
            flag = 1-flag;
        }
        nums = result;
    }
};
