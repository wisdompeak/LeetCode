class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int n = nums.size();
        list<int> List;
        unordered_map<int,list<int>::iterator>idx2iter;
        for (int i=0; i<n; i++)
        {
            List.push_back(i);
            idx2iter[i] = prev(List.end());
        }
        
        queue<int>q;
        for (int i=n-1; i>=1; i--)
            if (nums[i-1]>nums[i])
                q.push(i);

        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            vector<int>temp;
            while (len--)
            {
                int i = q.front();
                q.pop();
                
                auto iter = idx2iter[i];                
                if (next(iter)!=List.end() && (temp.empty() || *next(iter)!=temp.back()))
                {
                    temp.push_back(*next(iter));
                }
                    
                List.erase(iter);
            }

            for (int idx: temp)
            {                
                auto iter = idx2iter[idx];
                if (iter!=List.begin() && nums[*prev(iter)] > nums[idx])
                    q.push(idx);
            }
            step++;                
        }
        return step;
    }
};
