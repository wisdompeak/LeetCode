class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) 
    {
        vector<multiset<int>>arr(4);
        
        for (auto& p: points)
        {
            arr[0].insert(p[0]+p[1]);
            arr[1].insert(p[0]-p[1]);
            arr[2].insert(-p[0]+p[1]);
            arr[3].insert(-p[0]-p[1]);
        }
        
        int ret = INT_MAX/2;
        for (auto& p: points)
        {
            arr[0].erase(arr[0].find(p[0]+p[1]));
            arr[1].erase(arr[1].find(p[0]-p[1]));
            arr[2].erase(arr[2].find(-p[0]+p[1]));
            arr[3].erase(arr[3].find(-p[0]-p[1]));
            
            int ans = 0;
            ans = max(ans, *prev(arr[0].end()) - *arr[0].begin());
            ans = max(ans, *prev(arr[1].end()) - *arr[1].begin());
            ans = max(ans, *prev(arr[2].end()) - *arr[2].begin());
            ans = max(ans, *prev(arr[3].end()) - *arr[3].begin());
            
            ret = min(ret, ans);
            
            arr[0].insert(p[0]+p[1]);
            arr[1].insert(p[0]-p[1]);
            arr[2].insert(-p[0]+p[1]);
            arr[3].insert(-p[0]-p[1]);
        }
        
        return ret;
    }
};
