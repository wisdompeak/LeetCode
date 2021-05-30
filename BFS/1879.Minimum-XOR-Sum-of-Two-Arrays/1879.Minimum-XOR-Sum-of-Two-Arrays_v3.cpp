typedef pair<int,int> PII;

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>visited(1<<m, 0);        
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0,0});
        
        while (!pq.empty())
        {
            auto [cost, state] = pq.top();
            pq.pop();
                        
            if (visited[state]) continue;
            visited[state] = 1;
            
            int j = __builtin_popcount(state);
            if (j==n) return cost;
                
            for (int i=0; i<m; i++)
            {
                if ((state>>i)&1) continue;
                int newState = state+(1<<i);
                if (visited[newState]) continue;                                 
                pq.push({cost+(nums1[i]^nums2[j]), newState});
            }
        }
        
        return -1;
    }
};
