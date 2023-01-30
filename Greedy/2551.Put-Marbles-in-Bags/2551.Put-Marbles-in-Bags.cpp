using LL = long long;
class Solution {    
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        if (n==1) return 0;
        
        vector<LL>arr;
        for (int i=0; i<n-1; i++)
            arr.push_back(weights[i]+weights[i+1]);
                
        sort(arr.begin(), arr.end());
        
        LL ret = 0;
        for (int i=0; i<k-1; i++)
            ret += arr[(int)arr.size()-1-i];
        
        for (int i=0; i<k-1; i++)
            ret -= arr[i];
        
        return ret;
    }
};
