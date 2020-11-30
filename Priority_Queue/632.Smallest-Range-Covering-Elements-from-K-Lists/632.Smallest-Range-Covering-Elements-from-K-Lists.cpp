class Solution {
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return a.first>b.first;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int N=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        
        int MIN=INT_MAX;
        int MAX=INT_MIN;
        
        vector<int>range(2,0);
        for (int i=0; i<N; i++)
        {
            if (nums[i].size()==0) return range;
            q.push({nums[i][0],i});
            MIN=min(MIN,nums[i][0]);
            MAX=max(MAX,nums[i][0]);
        }
        range[0]=MIN;
        range[1]=MAX;
        
        vector<int>pointers(N,1);
        do
        {
            int k=q.top().second;
            if (pointers[k]==nums[k].size())
                return range;
            q.pop();
            q.push({nums[k][pointers[k]],k});            
            MAX=max(MAX,nums[k][pointers[k]]);
            MIN=q.top().first;            
            pointers[k]++;
            
            if (MAX-MIN<range[1]-range[0])
            {
                range[0]=MIN;
                range[1]=MAX;
            }
        }while (1);
        
        return range;
    }
};
