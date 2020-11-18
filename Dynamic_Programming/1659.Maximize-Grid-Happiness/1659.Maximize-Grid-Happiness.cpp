class Solution {
    int dp[6][7][7][243];
    int N;
    int a[6];
    int b[6];
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) 
    {
        this->N = n;
        int MAX_State = pow(3,n);
        for (int row = 0; row <= m; row++)
            for (int x = 0; x<=introvertsCount; x++)
                for (int y = 0; y<=extrovertsCount; y++)
                    for (int state = 0; state < MAX_State; state++)
                        dp[row][x][y][state] = INT_MIN/2;
        
        dp[0][0][0][0] = 0;
        int ret = 0;
        
        for (int row = 1; row <= m; row++)
            for (int x = 0; x<=introvertsCount; x++)
                for (int y = 0; y<=extrovertsCount; y++)
                    for (int state = 0; state < MAX_State; state++)
                    {
                        auto [count1, count2] = countPeople(state);
                        if (x<count1 || y<count2) continue;
                        int xx = x - count1;
                        int yy = y - count2;

                        for (int preState = 0; preState < MAX_State; preState++)
                        {
                            if (dp[row-1][xx][yy][preState]==INT_MIN/2) continue;
                            int val = computeScore(preState, state);
                            dp[row][x][y][state] = max(dp[row][x][y][state], dp[row-1][xx][yy][preState] + val);
                        }
                        
                        if (row==m) ret = max(ret, dp[row][x][y][state]);                            
                    }
        
        return ret;
    }

    pair<int,int> countPeople(int state)
    {
        int count1 = 0, count2 = 0;
        for (int i=0; i<N; i++)
        {
            if (state%3==1)
                count1++;
            else if (state%3==2)                
                count2++;
            state /= 3;
        }
        return {count1, count2};
    }
    
    int computeScore(int pre, int cur)
    {
        int ret = 0;        
        for (int i=0; i<N; i++)
        {
            a[i] = pre%3;
            pre/=3;
            b[i] = cur%3;
            cur/=3;
        }
        for (int i=0; i<N; i++)
        {
            if (b[i]==1)
            {
                ret += 120;
                if (i>=1 && b[i-1]>0) ret-=30;
                if (i<N-1 && b[i+1]>0) ret-=30;
                if (a[i]>0) ret-=30;
                if (a[i]==1) ret-=30;
                else if (a[i]==2) ret+=20;
            }
            else if (b[i]==2)
            {
                ret += 40;
                if (i>=1 && b[i-1]>0) ret+=20;
                if (i<N-1 && b[i+1]>0) ret+=20;
                if (a[i]>0) ret+=20;
                if (a[i]==1) ret-=30;
                else if (a[i]==2) ret+=20;
            }
        }
        return ret;
    }
};
