class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        unordered_map<int,int>Map;
        for (auto x:barcodes)
            Map[x]++;
        vector<pair<int,int>>q;
        for (auto x:Map)
            q.push_back({x.second,x.first});
        sort(q.begin(),q.end());
        reverse(q.begin(),q.end());
        
        vector<int>idx;
        for (int i=0; i<barcodes.size(); i+=2)
            idx.push_back(i);
        for (int i=1; i<barcodes.size(); i+=2)
            idx.push_back(i);
        
        vector<int>results(barcodes.size());
        int k = 0;
        for (auto x:q)
        {
            for (int i=0; i<x.first; i++)
            {
                results[idx[k]] = x.second;
                k++;
            }                
        }
        return results;
    }
};
