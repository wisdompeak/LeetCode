class Solution {
public:
    vector<int>q;
    int maxGroup=0, N;
    
    int minTransfers(vector<vector<int>>& transactions) 
    {
        map<int,int>Map;
        for (int i=0; i<transactions.size(); i++)
        {
            Map[transactions[i][0]]+=transactions[i][2];
            Map[transactions[i][1]]-=transactions[i][2];
        }        
        for (auto a:Map)
        {
            if (a.second!=0)
                q.push_back(a.second);
        }
            
        N = q.size();
        int GroupCount = 0; 
        DFS((1<<N)-1, GroupCount);        
        return N-maxGroup;
    }
    
    void DFS(int mask, int GroupCount)
    {
        if (mask==0)
        {
            maxGroup = max(maxGroup,GroupCount);
            return;
        }
        for (int subSet = mask; subSet!=0; subSet=((subSet-1)&mask))
        {
            if (zeroSum(subSet))
                DFS(mask-subSet, GroupCount+1);
        }
    }
    
    bool zeroSum(int mask)
    {
        int sum = 0;
        for (int i=0; i<N; i++)
        {
            if ((mask>>i)&1)
                sum+=q[i];
        }
        return sum==0;            
    }
    
};
