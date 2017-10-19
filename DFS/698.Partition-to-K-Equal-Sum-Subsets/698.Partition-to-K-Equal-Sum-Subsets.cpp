class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        if (k==1) return true;
        if (k>nums.size()) return false;
        
        sort(nums.begin(),nums.end());
        
        int SUM=0;
        for (int i=0; i<nums.size(); i++)
            SUM+=nums[i];
        
        if (SUM%k!=0) return false;
        
        int sum = SUM/k;
        int N = nums.size();
        
        vector<int>subsetSum(k,0);
        vector<int>visited(N,0);
        
        return DFS(nums, subsetSum, visited, sum, k, 0, N-1);
    }
    
    bool DFS(vector<int>& nums, vector<int>& subsetSum, vector<int>& visited, int sum, int k, int curSet, int lastNum)
    {
        if (curSet==k) return true;
        
        if (subsetSum[curSet] == sum)
            return DFS(nums,subsetSum, visited, sum, k, curSet+1, nums.size()-1);
                
        for (int i=lastNum; i>=0; i--)
        {
            if (visited[i]==1) continue;
            
            if (subsetSum[curSet]+nums[i]<=sum)
            {
                subsetSum[curSet]+=nums[i];
                visited[i]=1;
                
                if (DFS(nums,subsetSum,visited,sum,k,curSet, i-1))
                    return true;
                
                subsetSum[curSet]-=nums[i];
                visited[i]=0;
            }
        }        
        return false;
    }
};
