class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) 
    {
        unordered_map<int,int>Map;
        for (int i=0; i<target.size(); i++)
            Map[target[i]] = i;
        
        vector<int>q;
        for (int i=0; i<arr.size(); i++)
        {
            if (Map.find(arr[i])==Map.end())
                continue;
            int x = Map[arr[i]];
            if (q.empty() || q.back() < x)
                q.push_back(x);
            else
            {
                auto iter = lower_bound(q.begin(), q.end(), x);
                *iter = x;
            }
        }
        return target.size() - q.size();        
    }
};
