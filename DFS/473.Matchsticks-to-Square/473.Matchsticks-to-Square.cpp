class Solution {
    int sum = 0;
public:
    bool makesquare(vector<int>& nums) 
    {
        if (nums.size()==0) return false;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());                
        
        for (auto x:nums) sum+=x;
        if (sum%4!=0) return false;
        
        sum = sum/4;
        vector<int>visited(nums.size(),0);
        return DFS(nums,0,0,0,visited);
    }
    
    bool DFS(vector<int>& nums, int curIdx, int curEdge, int curSum, vector<int>& visited)
    {
        if (curEdge==4) return true;
        if (curSum==sum) return DFS(nums, 0, curEdge+1, 0, visited);
        if (curSum>sum) return false;
        if (curIdx==nums.size()) return false;
        
        for (int i=curIdx; i<nums.size(); i++)
        {
            if (visited[i]==1) continue;
            visited[i] = 1;
            if (DFS(nums,i+1,curEdge,curSum+nums[i],visited))
                return true;
            visited[i] = 0;
        }
        return false;        
    }
};
