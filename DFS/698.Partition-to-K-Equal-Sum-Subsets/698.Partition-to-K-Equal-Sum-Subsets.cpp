class Solution {
    int K;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        if (k==0) return false;
        if (k==1) return true;
        int SUM=0;
        for (int i=0; i<nums.size(); i++)
            SUM+=nums[i];
        if (SUM%k!=0) return false;
        int sum=SUM/k;

        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int>visited(nums.size(),0);
        K=k;
        
        return DFS(nums,0,0,0,sum,visited);
    }

    bool DFS(vector<int>& nums, int curPos, int curGroup, int curSum, int SUM, vector<int>&visited)
    {
        if (curGroup==K) return true;
        if (curSum==SUM) return DFS(nums,0,curGroup+1,0,SUM,visited);
        if (curSum>SUM) return false;
        if (curPos==nums.size()) return false;
        
        for (int i=curPos; i<nums.size(); i++)
        {
            if (visited[i]==1)
                continue;
            if (curPos!=i && visited[i-1]==0 && nums[i]==nums[i-1])
                continue;
            visited[i]=1;
            if (DFS(nums,i+1,curGroup,curSum+nums[i],SUM,visited))
                return true;
            visited[i]=0;
        }
        return false;
    }
};
