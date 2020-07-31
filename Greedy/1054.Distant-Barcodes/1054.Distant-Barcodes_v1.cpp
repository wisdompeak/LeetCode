class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        unordered_map<int,int>Map;
        for (auto x:barcodes)
            Map[x]+=1;
        
        vector<pair<int,int>>p;
        for (auto x: barcodes)
            p.push_back({Map[x], x});        
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        int n = barcodes.size();
        vector<int>ret(n);
        int i = 0;
        for (auto x: p)
        {
            ret[i] = x.second;
            i+=2;
            if (i>=n) i = 1;
        }
        return ret;            
    }
};
