class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int sum=0;
        unordered_map<int,int>Map;
        Map[0]=-1;
        
        int result=0;
        for (int i=0; i<nums.size(); i++)
        {
            sum+=(nums[i]==1?1:-1);
            if (Map.find(sum)==Map.end())
                Map[sum]=i;
            else
            {
                result = max(result, i-Map[sum]);
            }
        }
        
        return result;
    }
};
