class Solution {
public:
    int maxDepthBST(vector<int>& order) 
    {
        map<int,int>Map;
        Map[0] = 100001;                
        
        vector<int>depth(100005, 0);
        
        int ret = 0;
        for (auto x: order)
        {
            int left = prev(Map.upper_bound(x))->first;
            int right = Map[left];
            depth[x] = depth[left] + 1;
            
            if (left <= x-1) 
            {
                Map[left] = x-1;
                depth[left] = depth[x];
            }
            if (right >= x+1) 
            {
                Map[x+1] = right;
                depth[x+1] = depth[x];            
            }
            
            ret = max(ret, depth[x]);
        }
        
        return ret;
        
    }
};
