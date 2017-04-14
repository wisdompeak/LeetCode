class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>>Map;
        
        for (int i=0; i<strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(),t.end());
            Map[t].push_back(strs[i]);
        }
        
        vector<vector<string>>results;
        for (auto a:Map)
            results.push_back(a.second);
        
        return results;
        
    }
};
