class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        unordered_map<int,int>Map;
        for (auto x: flowers)
        {
            Map[x[0]]+=1;
            Map[x[1]+1]-=1;
        }
        vector<pair<int,int>>diff(Map.begin(), Map.end());
        sort(diff.begin(), diff.end());
        
        vector<pair<int,int>>p;
        for (int i=0; i<persons.size(); i++)
            p.push_back({persons[i],i});
        sort(p.begin(), p.end());
        
        int sum = 0;
        int j = 0;
        vector<int>rets(persons.size());
        for (int i=0; i<p.size(); i++)
        {
            while (j<diff.size() && diff[j].first<=p[i].first)
            {
                sum+= diff[j].second;
                j++;
            }
            rets[p[i].second] = sum;            
        }
        
        return rets;
    }
};
