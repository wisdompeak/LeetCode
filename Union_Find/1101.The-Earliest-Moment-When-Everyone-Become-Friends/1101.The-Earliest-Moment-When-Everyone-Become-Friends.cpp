class Solution {
    unordered_map<int,int>Father;
public:
    int earliestAcq(vector<vector<int>>& logs, int N) 
    {
        sort(logs.begin(),logs.end());
        for (int i=0; i<N; i++)
            Father[i] = i;
        int groups = N;
            
        for (auto log:logs)
        {
            int A = log[1];
            int B = log[2];
            if (findFather(A)!=findFather(B))
            {
                Union(A,B);
                groups--;
            }
            if (groups==1)
                return log[0];
        }
        return -1;
        
    }
    
    int findFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = findFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int  y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y) Father[y]=x;
        else Father[x] = y;
    }
};
