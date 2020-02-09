class Solution {
    int M,N;
    int ret;
    set<int>visited;
public:
    int maxStudents(vector<vector<char>>& seats) 
    {
        M = seats.size();
        N = seats[0].size();
        
        ret = 0;
        
        int T = (1<<N);
        
        vector<int>dp(T,-1);
        for (int s=0; s<T; s++)
        {
            if (checkOK(seats,0,s,0))
                dp[s] = count(s);
        }
        
        for (int row = 1; row < M; row++)
        {
            vector<int>dp2(T,-1);
            
            for (int s=0; s<T; s++)
                for (int t=0; t<T; t++)
                {
                    if (dp[t]==-1) continue;
                    if (checkOK(seats,row,s,t))
                    {
                        dp2[s] = max(dp2[s], dp[t]+count(s));
                        ret = max(ret, dp2[s]);
                    }
                        
                }
            dp = dp2;            
        }
                
        return ret;
    }
    
    bool checkOK(vector<vector<char>>& seats, int row, int s, int t)
    {
        vector<int>arr1(N,0);
        vector<int>arr2(N,0);
        for (int i=0; i<N; i++)
        {
            arr1[N-1-i] = ((s>>i)&1);
            arr2[N-1-i] = ((t>>i)&1);
        }
        
        for (int i=0; i<N; i++)
        {
            if (arr1[i]==1 && seats[row][i]=='#')
                return false;
        }
        for (int i=1; i<N; i++)
        {
            if (arr1[i]==1 && arr1[i-1]==1)
                return false;
        }
        
        if (row==0) return true;
        
        for (int i=0; i<N; i++)
        {
            if (arr1[i]!=1) continue;
            if (i-1>=0 && arr2[i-1]==1)
                return false;
            if (i+1<N && arr2[i+1]==1)
                return false;
        }
        return true;
    }
    
    int count(int s)
    {
        int cnt = 0;
        for (int i=0; i<N; i++)
        {
            if (s%2==1)
                cnt++;
            s=s/2;
        }
        return cnt;
    }
    
};
