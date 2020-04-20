class Solution {
    int M,N,T;
public:
    int maxStudents(vector<vector<char>>& seats) 
    {
        M = seats.size();
        N = seats[0].size();
        T = (1<<N);
        vector<int>dp(T,0); 
        // dp[i]: until the current row, how many students at most we can host 
        // given the current row follows pattern "i"
      
        for (int p=0; p<T; p++)
        {
            if (selfOK(p, seats, 0))
                dp[p] = count(p);
        }
  
        for (int row = 1; row < M; row++)
        {
            auto dp2 = dp;
            for (int cur = 0; cur < T; cur++)
            {
                dp[cur] = 0;
                if (!selfOK(cur, seats, row)) continue;
                for (int prev = 0; prev < T; prev++)
                {
                    if (row==2 && cur==18 && prev==0) cout<<crossOK(cur,prev)<<" "<<dp2[prev]<<endl;
                    if (!selfOK(prev, seats, row-1)) continue;
                    if (!crossOK(cur, prev)) continue;
                    dp[cur] = max(dp[cur], count(cur) + dp2[prev]);
                }
            }
        }
        
        int ret = 0;
        for (int p = 0; p < T; p++)
        {
            if (!selfOK(p, seats, M-1)) continue;
            ret = max(ret, dp[p]);
        }
        return ret;
    }
    
    bool selfOK(int p, vector<vector<char>>& seats, int row)
    {
        vector<int>temp;
        for (int i=0; i<N; i++)
        {
            temp.push_back(p%2);
            p/=2;
        }
        for (int i=0; i<N; i++)
        {
            if (seats[row][i]=='#' && temp[i]==1)
                return false;
            if (i>=1 && temp[i]==1 && temp[i-1]==1)
                return false;
        }
        return true;     
    }
    
    bool crossOK(int cur, int prev)
    {
        vector<int>p1, p2;
        for (int i=0; i<N; i++)
        {
            p1.push_back(cur%2);
            p2.push_back(prev%2);
            cur/=2;
            prev/=2;
        }
        for (int i=0; i<N; i++)
        {
            if (p1[i]==0) continue;
            if (i-1>=0 && p2[i-1]==1) return false;
            if (i+1<N && p2[i+1]==1) return false;  
        }
        return true;     
    }
    
    int count(int p)
    {        
        int ret=0;
        while (p>0)
        {
            ret+=(p%2);
            p=p/2;
        }
        return ret;
    }
    
};

