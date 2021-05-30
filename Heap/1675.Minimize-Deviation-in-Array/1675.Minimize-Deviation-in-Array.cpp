class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        multiset<int>Set;
        for (auto x: nums)
        {
            if (x%2==0)
                Set.insert(x);
            else
                Set.insert(x*2);
        }

        int ret = INT_MAX;
        while (!Set.empty())
        {
            ret = min(ret, *Set.rbegin() - *Set.begin());
            int k = *Set.rbegin();
            Set.erase(prev(Set.end()));
            if (k%2==1)
                break;
            else
                Set.insert(k/2);
        }
        return ret;
    }
};
