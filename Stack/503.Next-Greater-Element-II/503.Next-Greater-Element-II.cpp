class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int N=nums.size();
        stack<pair<int,int>>Stack;
        vector<int>results(N,-1);
        
        for (int j=0; j<N*2; j++)
        {
            int i=j;
            if (i>=N) i=i-N;
            
            if (Stack.empty() || Stack.top().first>nums[i])
                Stack.push({nums[i],i});
            else
            {
                while (!Stack.empty() && Stack.top().first<nums[i])
                {
                    results[Stack.top().second]=nums[i];
                    Stack.pop();
                }
                Stack.push({nums[i],i});
            }
        }
        
        return results;
    }
};
