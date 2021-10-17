class Solution {
private:
    int M;
    int N;
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return a.first>=b.first;
        }
    };
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        M=matrix.size();
        N=matrix[0].size();
        
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        visited[0][0]=1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        q.push({matrix[0][0],0});
        int count=0;
        int result;
        
        while (count<k)
        {
            //cout<<count<<endl;
            
            int i=q.top().second/N;
            int j=q.top().second%N;
            int t=q.top().first;
            q.pop();
            count++;
            if (count==k)
                result=t;
            
            if (i+1<M && j<N && visited[i+1][j]==0)
            {
                q.push({matrix[i+1][j],(i+1)*N+j});
                visited[i+1][j]=1;
            }
            if (i<M && j+1<N && visited[i][j+1]==0)
            {
                q.push({matrix[i][j+1],(i)*N+j+1});
                visited[i][j+1]=1;
            }
        }
        
        return result;
    }
};
