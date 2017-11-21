class Solution {
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

        vector<int>sets(k,0);
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int>visited(nums.size(),0);
        return DFS(nums,sets,0,visited,sum,0);
    }

    bool DFS(vector<int>&nums, vector<int>&sets, int curSet, vector<int>&visited, int sum, int curNum)
    {
        if (curSet==sets.size()) return true;
        if (sets[curSet]==sum) return DFS(nums,sets,curSet+1,visited,sum,0);

        for (int i=curNum; i<nums.size(); i++)
        {
          if (visited[i]==1) continue;

          if (sets[curSet]+nums[i]<=sum)
          {
             visited[i]=1;
             sets[curSet]+=nums[i];
             if (DFS(nums,sets,curSet,visited,sum,i+1)) return true;
             sets[curSet]-=nums[i];
             visited[i]=0;
          }
        }

        return false;
    }
};
