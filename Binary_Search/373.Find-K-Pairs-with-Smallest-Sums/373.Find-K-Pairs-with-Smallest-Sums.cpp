using AI3 = array<int,3>;
class Solution {    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<AI3,vector<AI3>, greater<>>pq;
        int m=nums1.size();
        int n=nums2.size();        
        vector<vector<int>>rets;
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        pq.push({nums1[0]+nums2[0], 0, 0});                
        visited[0][0]=1;
                
        while (rets.size() < k && pq.size()>0)
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            rets.push_back({nums1[i], nums2[j]});            
                        
            if (i+1<m && visited[i+1][j]==0)
            {
                pq.push({nums1[i+1]+nums2[j], i+1, j});
                visited[i+1][j] = 1;
            }
            if (j+1<n && visited[i][j+1]==0)
            {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
                visited[i][j+1] = 1;
            }             
        }
        
        return rets;                
    }
};
