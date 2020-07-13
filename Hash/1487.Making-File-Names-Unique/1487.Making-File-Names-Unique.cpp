class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) 
    {
        unordered_map<string,int>Map;
        unordered_set<string>Set;
        vector<string>rets;
        for (auto name: names)
        {
            if (Set.find(name)==Set.end())
            {
                Set.insert(name);
                Map[name] = 0;
                rets.push_back(name);
            }
            else
            {   
                Map[name] += 1;
                string new_name = name + "(" + to_string(Map[name]) + ")";
                while (Set.find(new_name)!=Set.end())
                {
                    Map[name] += 1;
                    new_name = name + "(" + to_string(Map[name]) + ")";
                }                
                Set.insert(new_name);
                rets.push_back(new_name);
            }
        }
        return rets;        
    }
};
