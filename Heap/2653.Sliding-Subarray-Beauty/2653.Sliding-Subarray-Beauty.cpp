class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        multiset<int>Set1;
        multiset<int>Set2;
        vector<int>rets;

        for (int i=0; i<nums.size(); i++)
        {
            if (Set1.size() < x)
                Set1.insert(nums[i]);
            else
            {
                int v = *Set1.rbegin();
                if (v > nums[i])
                {
                    Set1.erase(Set1.find(v));
                    Set2.insert(v);
                    Set1.insert(nums[i]);
                }
                else
                {
                    Set2.insert(nums[i]);
                }
            }

            if (Set1.size() + Set2.size() == k)
            {
                int v = *Set1.rbegin();
                rets.push_back(min(v, 0));
            }

            if (i>=k-1)
            {
                int v = nums[i-k+1];
                auto iter = Set2.find(v);
                if (iter!=Set2.end())
                    Set2.erase(iter);
                else
                {
                    Set1.erase(Set1.find(v));
                    if (!Set2.empty())
                    {
                        Set1.insert(*Set2.begin());
                        Set2.erase(Set2.begin());
                    }                    
                }
            }
        }

        return rets;
    }
};
