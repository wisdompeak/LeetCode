class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int n = nums.size();
        list<int> List;
        unordered_map<int,list<int>::iterator>key2iter;
        for (int i=0; i<n; i++)
        {
            List.push_back(i);
            key2iter[i] = prev(List.end());
        }
        
        queue<int>q;
        for (int i=1; i<n; i++)
            if (nums[i-1]>nums[i])
                q.push(i);

        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            unordered_set<int>Set;
            while (len--)
            {
                int i = q.front();
                q.pop();
                
                auto iter = key2iter[i];
                if (Set.count(i))
                    Set.erase(i);
                if (next(iter)!=List.end())
                    Set.insert(*next(iter));
                List.erase(iter);
            }

            for (int i: Set)
            {
                if (key2iter[i]!=List.begin() && nums[*prev(key2iter[i])] > nums[i])
                    q.push(i);
            }
            step++;                
        }

        return step;
    }
};
