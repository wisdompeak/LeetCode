class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) 
    {        
        int N = A.size();
        
        A.insert(A.begin(),0);
        
        vector<int>Sum(N+1,0);
        map<int,int>Map;
        
        Map[0] = 0;        
        int ret = INT_MAX;
        
        for (int i=1; i<=N; i++)
        {
            Sum[i]=Sum[i-1]+A[i];
                        
            int num = Sum[i]-K;            
            
            auto it = Map.upper_bound(num);            
            if (it!=Map.begin())
            {                
                it = prev(it,1);
                ret = min(ret, i-it->second);
            }
            
            Map[Sum[i]] = i;
            while (Map.rbegin()->first!=Sum[i])
                Map.erase(Map.rbegin()->first);            
        }
        
        if (ret==INT_MAX)
            return -1;
        else
            return ret;                    
    }
};
