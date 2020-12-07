class Solution {
    int n;
    int k;
    vector<int>visited;
    int ret = INT_MAX;
public:
    int minimumIncompatibility(vector<int>& nums, int k) 
    {
        unordered_map<int,int>count;
        for (auto x: nums)
            count[x]++;
        for (auto x: count)
            if (x.second > k)
                return -1;

        sort(nums.begin(), nums.end());
        this->k = k;
        this->n = nums.size();               
        visited.resize(n);
        
        visited[0] = 1;
        dfs(nums, 0, 1, nums[0], nums[0], 0);
        
        return ret;
    }
    
    void dfs(vector<int>& nums, int cur, int count, int low, int high, int sum)
    {
        if (count==n/k)
        {
            int j=0;
            while (j<n && visited[j]==1)
                j++;
            if (j==n)
            {
                ret = min(ret, sum+high-low);
            }
            else
            {
                visited[j]=1;
                dfs(nums, j, 1, nums[j], nums[j], sum+high-low);
                visited[j]=0;
            }
        }
        else
        {
            int last = -1;
            for (int i=cur+1; i<n; i++)
            {
                if (visited[i]==1) continue;
                if (nums[i]==nums[cur]) continue;
                if (i>cur+1 && nums[i]==last) continue;
                visited[i] = 1;
                dfs(nums, i, count+1, low, nums[i], sum);
                last = nums[i];
                visited[i] = 0;
            }            
        }
    }
};
