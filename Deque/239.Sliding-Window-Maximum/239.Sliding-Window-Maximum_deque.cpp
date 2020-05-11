class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {        
        vector<int>results;
        deque<int>q;
        for (int i=0; i<nums.size(); i++)
        {
            while (q.size()>0 && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);

            if (q.front()<=i-k)
                q.pop_front();

            if (i>=k-1)
                results.push_back(nums[q.front()]);
        }
        return results;
    }
};
