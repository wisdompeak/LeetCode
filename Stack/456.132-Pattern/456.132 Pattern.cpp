class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        if (nums.size()<3) return false;
        
        stack<int>Stack;
        vector<int>Mins(nums.size(),0);
        
        Mins[0]=nums[0];
        for (int i=1; i<nums.size(); i++)
            Mins[i]=min(Mins[i-1],nums[i]);
            
        int third=INT_MIN;    
        
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (Stack.empty() || nums[i]<=Stack.top())
                Stack.push(nums[i]);
            else
            {
                while (!Stack.empty() && nums[i]>Stack.top())
                {
                    third=max(third,Stack.top());
                    Stack.pop();
                }
                if (i-1>=0 && Mins[i-1]<third) return true;
                Stack.push(nums[i]);
            }
        }
        
        return false;
    }
};
