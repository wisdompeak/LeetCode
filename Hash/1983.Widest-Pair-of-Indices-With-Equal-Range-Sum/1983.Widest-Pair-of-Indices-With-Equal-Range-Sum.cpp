class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) 
    {                
        vector<int>arr;
        for (int i=0; i<nums1.size(); i++)
            arr.push_back(nums1[i]-nums2[i]);
                
        unordered_map<int,int>Map;
        Map[0] = -1;        
        
        int presum = 0;
        int ret = 0;
        for (int i=0; i<arr.size(); i++)
        {
            presum += arr[i];
            if (Map.find(presum)!=Map.end())                          
                ret = max(ret, i-Map[presum]);                            
            else
                Map[presum] = i;
        }
        return ret;
        
    }
};
