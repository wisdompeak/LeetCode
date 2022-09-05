using AI3 = array<int,3>;
class Solution {    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<AI3,vector<AI3>, greater<>>pq;
        int m=nums1.size();
        int n=nums2.size();        
        vector<vector<int>>rets;
        
        set<pair<int,int>>Set;
        pq.push({nums1[0]+nums2[0], 0, 0});                
        Set.insert({0,0});
        
                
        while (rets.size() < k && pq.size()>0)
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            rets.push_back({nums1[i], nums2[j]});            
                        
            if (i+1<m && Set.find({i+1,j})==Set.end())
            {
                pq.push({nums1[i+1]+nums2[j], i+1, j});
                Set.insert({i+1,j});
            }
            if (j+1<n && Set.find({i,j+1})==Set.end())
            {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
                Set.insert({i,j+1});
            }             
        }
        
        return rets;                
    }
};
