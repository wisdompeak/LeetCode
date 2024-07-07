class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        unordered_set<int>Set, temp;
        int ret = INT_MAX;
        for (int x: nums)
        {
            for (int y: Set)
                temp.insert(y | x);
            temp.insert(x);

            for (int y: temp)
                ret = min(ret, abs(y-k));

            Set = temp;
            temp.clear();
        }
        return ret;        
    }
};
