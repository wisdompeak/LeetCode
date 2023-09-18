class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        for (int i=0; i<n; i++)
            Map[nums[i]]++;
        
        int mx = 0;
        for (auto [k,v]: Map)
        {
            mx = max(mx, v);
        }        
       
        if (mx > n/2)
            return n - (n-mx)*2;
        else
            return (n%2);
        
    }
};
