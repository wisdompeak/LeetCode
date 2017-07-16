class Solution {
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return a.first>b.first;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        int M=nums1.size();
        int N=nums2.size();
        vector<pair<int, int>>results;
        if (M==0 || N==0) return results;
        
        auto used=vector<vector<int>>(M,vector<int>(N,0));
        q.push({nums1[0]+nums2[0],0});                
        used[0][0]=1;
        
        int count=0;
        while (count<k && q.size()>0)
        {
            int m=q.top().second/N;
            int n=q.top().second%N;
            results.push_back({nums1[m],nums2[n]});
            count++;
            q.pop();
            
            if (m+1<M && used[m+1][n]==0)
            {
                q.push({nums1[m+1]+nums2[n],(m+1)*N+n});
                used[m+1][n]=1;
            }
            if (n+1<N && used[m][n+1]==0)
            {
                q.push({nums1[m]+nums2[n+1],(m)*N+n+1});
                used[m][n+1]=1;
            }             
        }
        
        return results;                
    }
};
