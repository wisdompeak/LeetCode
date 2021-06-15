typedef pair<int,vector<int>> PIV;
class Solution {    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();

        set<vector<int>>visited;
        vector<int>idx(m,0);
        visited.insert(idx);

        int sum = 0;
        for (int i=0; i<m; i++)
            sum += mat[i][0];
        priority_queue<PIV,vector<PIV>,greater<>>pq;
        pq.push({sum, idx});

        for (int t=0; t<k; t++)
        {            
            auto [sum, idx] = pq.top();
            pq.pop();
            if (t==k-1) return sum;

            for (int i=0; i<m; i++)
            {
                idx[i]++;
                if (idx[i]<n && visited.find(idx)==visited.end())
                {
                    visited.insert(idx);
                    pq.push({sum + mat[i][idx[i]] - mat[i][idx[i]-1], idx});
                }
                idx[i]--;
            }
        }

        return -1;
    }        
};
