class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
        int M=mat.size();
        if (M==0) return 0;
        int N=mat[0].size();                
        int ret = 0;        
        for (int i=0; i<M; i++)
        {
            auto q= vector<int>(N,0);            
            for (int k=i; k<M; k++)
            {
                for (int j=0; j<N; j++)
                {
                    if (mat[k][j]==0)
                        q[j]=0;
                    else    
                        q[j]=q[j]+1;
                }
                int h = k-i+1;
                for (int a = 0; a<N; a++)
                {
                    if (q[a]!=h) continue;
                    int b = a;
                    while (b<N && q[b]==h)
                        b++;
                    int L = b-a;
                    ret += (1+L)*L/2;
                    a = b-1;
                }
            }
            
        }        
        return ret;        
    }
};
