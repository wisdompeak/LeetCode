class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int,int>Map;
        for (int i=0; i<nums.size(); i++)
            Map[nums[i]]++;
        
        int lastFreq=0;
        int lastNum;
        int result=0;
        for (auto a:Map)
        {
            if (lastFreq==0)
            {
                lastNum=a.first;
                lastFreq=a.second;
            }
            else
            {
                if (lastNum+1==a.first)
                    result = max(result,lastFreq+a.second);
                lastNum = a.first;
                lastFreq = a.second;
            }
        }
        
        return result;
        
    }
};
