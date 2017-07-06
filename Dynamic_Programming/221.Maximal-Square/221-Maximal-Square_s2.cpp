class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int M=matrix.size();
        if (M==0) return 0;
        int N=matrix[0].size();
        
        vector<int>q(N,0);
        
        int result=0;
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (matrix[i][j]=='0')
                    q[j]=0;
                else
                    q[j]=q[j]+1;
                    
            }

            result = max(result,helper(q));
        }
        
        return result;
        
    }
    
    int helper(vector<int>height)
    {
        if (height.size()==1) return (height[0]>0);
        height.push_back(0);
        height.insert(height.begin(),0);
        
        stack<int>s;
        int result=0;
        
        for (int i=0; i<height.size(); i++)
        {
            if (s.empty() || height[i]>=height[s.top()])
            {
                s.push(i);
                continue;
            }
            
            if (height[i]<height[s.top()])
            {
                while (!s.empty() && height[i]<height[s.top()])
                {
                    int H=height[s.top()];
                    
                    s.pop();
                    int d = min(H,i-s.top()-1);
                    result = max(result,d*d);
                }
                s.push(i);
            }
        }
    
        return result;

        
    }
};
