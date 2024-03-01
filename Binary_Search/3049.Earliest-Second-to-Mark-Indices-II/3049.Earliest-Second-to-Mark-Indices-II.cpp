using LL = long long;
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
    
    bool isOK(int t, vector<int>&nums, vector<int> changeIndices)
    {
        if (t<n) return false;
                
        vector<int>first(n+1, 0);
        for (int i=1; i<=t; i++)        
        {
            if (first[changeIndices[i]]==0 && nums[changeIndices[i]]!=0)
                first[changeIndices[i]]=i;    
            else
                changeIndices[i] = 0;
        }                       
                
        LL total = accumulate(nums.begin(), nums.end(), 0ll);
                              
        multiset<int>resets;
        for (int i=t; i>=1; i--)
        {
            int idx = changeIndices[i];
            
            if (idx == 0) continue;
            
            int marks = (t-i+1) - (resets.size() + 1);
            if (resets.size() +1 > marks)
            {                
                resets.insert(nums[idx]);                                
                resets.erase(resets.begin());
            }
            else
            {                
                resets.insert(nums[idx]);
            }           
        }        
        
        LL total_clear = 0;
        for (int x: resets) total_clear+=x;
        
        return total_clear + (t-n-resets.size()) >= total;
    }
};
