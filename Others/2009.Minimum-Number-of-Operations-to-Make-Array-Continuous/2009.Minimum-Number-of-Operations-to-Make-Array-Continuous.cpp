class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int N = nums.size();
        unordered_set<int>st(nums.begin(), nums.end());
        vector<int>arr(st.begin(), st.end());
        sort(arr.begin(), arr.end());
                    
        int j = 0;
        int ret = INT_MAX;
        for (int i=0; i<arr.size(); i++)
        {
            while (j<arr.size() && arr[j]-arr[i]+1<=N)
            {
                ret = min(ret, N-(j-i+1));                  
                j++;                
            }
        }
        return ret;
    }
};
