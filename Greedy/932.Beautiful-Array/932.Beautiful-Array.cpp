class Solution {
public:
    vector<int> beautifulArray(int N) 
    {
        if (N==1) return {1};
        if (N==2) return {2,1};
        
        vector<int>A = beautifulArray((N+1)/2);
        vector<int>B = beautifulArray(N-(N+1)/2);
        vector<int>ret;
        for (int x:A) ret.push_back(x*2-1);
        for (int x:B) ret.push_back(x*2);
        return ret;
    }
};
