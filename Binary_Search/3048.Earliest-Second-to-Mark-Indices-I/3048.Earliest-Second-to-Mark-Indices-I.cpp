class Solution {
    int n,m;
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) 
    {
        n = nums.size();
        m = changeIndices.size();
        nums.insert(nums.begin(), 0);
        changeIndices.insert(changeIndices.begin(), 0);
        
        int left=1, right=m;
        while (left < right)
        {
            int mid = left + (right-left)/2;
                        
            if (isOK(mid, nums, changeIndices))
                right = mid;
            else
                left = mid+1;
        }
        
        if (!isOK(left, nums, changeIndices)) return -1;
        else return left;
    }
    
    bool isOK(int m, vector<int>& nums, vector<int>& changeIndices)
    {
        vector<int>last(n+1);
        for (int i=1; i<=m; i++)        
            last[changeIndices[i]]=i;
        
        for (int i=1; i<=n; i++)
            if (last[i]==0) return false;        
                
        int count = 0;
        for (int i=1; i<=m; i++)
        {
            int idx = changeIndices[i];           
                
            if (i!=last[idx])
            {
                count++;
            }
            else
            {                
                count -= nums[idx];
                if (count < 0) return false;
            }
        }
        
        return true;
    }
};
