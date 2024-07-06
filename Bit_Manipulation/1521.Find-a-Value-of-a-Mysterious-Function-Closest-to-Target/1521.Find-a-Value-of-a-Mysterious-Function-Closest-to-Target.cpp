class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) 
    {
        set<int>Set, temp;
        int ret = INT_MAX;
        for (int x: arr)
        {
            for (auto y: Set)
                temp.insert(y&x);
            temp.insert(x);

            for (int y: temp)
                ret = min(ret, abs(y-target));
            
            Set = temp;
            temp.clear();
        }

        return ret;
    }
};
