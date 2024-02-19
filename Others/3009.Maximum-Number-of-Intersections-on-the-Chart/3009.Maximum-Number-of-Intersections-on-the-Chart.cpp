class Solution {
public:
    int maxIntersectionCount(vector<int>& y) 
    {        
        int n = y.size();
        map<float,int>Map;
        for (int i=1; i<n; i++)
        {
            int a = y[i-1], b = y[i];            
            if (a<b)
            {
                Map[a]+=1;
                Map[b]-=1;
            }
            else
            {                
                Map[b+0.5]+=1;                
                Map[a+0.5]-=1;
            }            
        }        
        Map[y[n-1]]+=1;
        Map[y[n-1]+0.5]-=1;

        int ret = 0;
        int count = 0;
        for (auto [k,v]:Map)
        {            
            count += v;
            ret = max(ret, count);
        }
        return ret;
        
    }
};
