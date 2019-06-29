class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) 
    {
        int left = INT_MAX;
        int right = INT_MIN;
        int M = A.size();
        int N = A[0].size();
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
            {
                left = min(left,A[i][j]);
                right = max(right,A[i][j]);
            }
        
        while (left<right)
        {
            int mid = right-(right-left)/2;
                        
            if (check(A,mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;        
    }
    
    bool check(vector<vector<int>> A, int K)
    {
        if (A[0][0]<K) return false;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        int M = A.size();
        int N = A[0].size();
        
        queue<pair<int,int>>q;
        q.push({0,0});
        A[0][0] = -1;
        
        while (q.size()>0)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=M||j<0||j>=N)
                    continue;
                if (A[i][j]==-1)
                    continue;                
                if (A[i][j]<K) continue;
                if (i==M-1 && j==N-1) return true;
                A[i][j]=-1;
                
                q.push({i,j});                
            }
        }
                
        return false;
    
    }
};
