class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) 
    {
        stack<int>st1;
        stack<int>st2;
        
        vector<int>rets(nums.size(), -1);
        
        for (int i=0; i<nums.size(); i++)
        {
            while (!st2.empty() && nums[st2.top()] < nums[i])            
            {                
                rets[st2.top()] = nums[i];
                st2.pop();
            }
            
            vector<int>temp;
            while (!st1.empty() && nums[st1.top()] < nums[i])
            {                
                temp.push_back(st1.top());
                st1.pop();
            }
            
            reverse(temp.begin(), temp.end());
            for (auto x: temp)
                st2.push(x);
            
            st1.push(i);
        }
        
        return rets;
    }
};
