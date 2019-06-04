class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        int n = grumpy.size();
        for (int i=0; i<n; i++)
            grumpy[i] = 1-grumpy[i];
        
        int base = 0;
        for (int i=0; i<n; i++)
            base += customers[i]*grumpy[i];
        
        int cur = base;
        for (int i=0; i<X; i++)
            if (grumpy[i]==0) cur+=customers[i];
        
        int result = cur;
        
        for (int i=0; i<=n-X; i++)
        {
            if (grumpy[i]==0)
                cur-=customers[i];
            
            if (i+X<n && grumpy[i+X]==0)
                cur+=customers[i+X];
            
            result = max(result, cur);
        }
        
        return result;
    }
};
