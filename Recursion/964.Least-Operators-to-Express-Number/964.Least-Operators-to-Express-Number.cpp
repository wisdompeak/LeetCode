class Solution {
    unordered_map<string,int>Map;
    long x;
public:
    int leastOpsExpressTarget(int x, int target) 
    {       
        this->x = x;
        
        float T = target;
        int k = 0;
        while (T>1.0)
        {
            T = T/x;
            k += 1;
        }                
        return dp(target,k)-1;
    }
    
    int dp(int target, int k)
    {       
        if (k==0)        
            return 2*target;
        
        string key = to_string(target)+"#"+to_string(k);
        if (Map.find(key)!=Map.end())
            return Map[key];
        
        int Div = pow(x,k);
        
        if (target==Div)
            return k;
                
        int m = target / Div;
        int n = target % Div;
                
        int result;
        int a = m*k+dp(n,k-1);
        int b = (m+1==x? (k+1) : (m+1)*k)+ dp(Div-n,k-1);
        result = min(a,b);        
        
        Map[key] = result;
        // cout<<target<<": "<<result<<endl;
        
        return result;
    }

};
