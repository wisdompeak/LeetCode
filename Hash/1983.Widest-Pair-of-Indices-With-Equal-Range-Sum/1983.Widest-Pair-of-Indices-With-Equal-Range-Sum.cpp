class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) 
    {
        int sum = 0;
        int n = nums1.size();
        vector<int>pre1(n+1);
        vector<int>pre2(n+1);
        
        for (int i=1; i<=n; i++)
            pre1[i] = pre1[i-1]+nums1[i-1];
        for (int i=1; i<=n; i++)
            pre2[i] = pre2[i-1]+nums2[i-1];
        
        vector<int>diff(n+1);
        for (int i=0; i<=n; i++)
            diff[i] = pre1[i]-pre2[i];
        
        unordered_map<int,int>Map;
        Map[0]=0;
        int ret = 0;
        for (int i=1; i<=n; i++)
        {
            if (Map.find(diff[i])!=Map.end())                          
                ret = max(ret, i-Map[diff[i]]);                            
            else
                Map[diff[i]] = i;
        }
        return ret;
        
    }
};
