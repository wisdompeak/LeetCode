class Solution {
public:
    int minNumberOperations(vector<int>& target) 
    {
        int ret = 0, curHeight = 0;
        for (int i=0; i<target.size(); i++)
        {
            ret += max(0, target[i] - curHeight);
            curHeight = target[i];
        }
        return ret;
    }
};
