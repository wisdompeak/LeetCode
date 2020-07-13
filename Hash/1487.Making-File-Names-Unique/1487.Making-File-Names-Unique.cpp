class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) 
    {
        unordered_map<string,int>Map;
        vector<string>rets;
        
        for (auto name: names)
        {
            if (Map.find(name)!=Map.end())            
            {                
                while (Map.find(name + "(" + to_string(Map[name]) + ")")!=Map.end())
                    Map[name] += 1;
                string new_name = name + "(" + to_string(Map[name]) + ")";                
                rets.push_back(new_name);                
                Map[name]+=1;
                Map[new_name] = 1;
            }
            else            
            {
                rets.push_back(name);                
                Map[name] = 1;
            }
                
        }
        return rets;
        
    }
};
