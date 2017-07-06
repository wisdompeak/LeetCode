class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
    {
        stack<int>Stack;
        unordered_map<int,int>Map;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (Stack.empty() || Stack.top()>nums[i])
                Stack.push(nums[i]);
            else
            {
                while (!Stack.empty() && Stack.top()<nums[i])
                {
                    Map[Stack.top()]=nums[i];
                    Stack.pop();
                }
                Stack.push(nums[i]);
            }
        }
        
        vector<int>results;
        for (int i=0; i<findNums.size(); i++)
        {
            if (Map.find(findNums[i])==Map.end())
                results.push_back(-1);
            else
                results.push_back(Map[findNums[i]]);
        }
        
        return results;
    }
};
