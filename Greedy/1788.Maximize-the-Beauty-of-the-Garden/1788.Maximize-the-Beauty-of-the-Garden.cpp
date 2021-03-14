class Solution {
public:
    int maximumBeauty(vector<int>& flowers) 
    {
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<flowers.size(); i++)
        {
            Map[flowers[i]].push_back(i);
        }
        
        int n = flowers.size();
        vector<int>presum(n);
        int sum = 0;
        for (int i=0; i<n; i++)
        {
            sum += (flowers[i]<0? 0:flowers[i]);
            presum[i] = sum;
        }
        
        int ret = INT_MIN;
        for (auto x: Map)
        {
            if (x.second.size()==1) continue;
            int beauty = x.first;            
            int a = x.second[0]+1, b = x.second.back()-1;            
            ret = max(ret, presum[b] - (a==0?0:presum[a-1]) + 2*beauty);
        }
        return ret;        
    }
};
