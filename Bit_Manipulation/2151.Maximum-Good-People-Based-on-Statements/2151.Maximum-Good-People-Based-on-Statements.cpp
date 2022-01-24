class Solution {
public:
    bool checkOK(int state, vector<vector<int>>& statements)
    {
        int n = statements.size();
        vector<int>judge(n, -1);
        int flag = 1;
        for (int i=0; i<n; i++)
        {
            int t = ((state>>i)&1);
            if (t==0) continue;
            
            for (int j=0; j<n; j++)
            {
                if (statements[i][j]==2) continue;
                if (judge[j]==-1)
                    judge[j] = statements[i][j];
                else if (judge[j]!=statements[i][j])
                {
                    flag = 0;
                    break;
                }   
            }            
            if (flag==0)
                break;
        }        
        
        for (int i=0; i<n; i++)
        {
            int t = ((state>>i)&1);
            if (t==1 && judge[i]==0)
            {
                flag = 0;
                break;
            }
            
            if (t==0 && judge[i]==1)
            {
                flag = 0;
                break;
            }
        }
                
        return flag;
    }
    
    int maximumGood(vector<vector<int>>& statements) 
    {
        int m = statements.size();
        for (int k=m; k>=1; k--)
        {
            int state = (1 << k) - 1;            
            while (state < (1 << m))
            {
                if (checkOK(state, statements))
                    return k;

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }            
        }
        return 0;
    }
};
