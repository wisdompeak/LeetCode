class Solution {
    unordered_map<string,string>Father;
    unordered_map<string,string>Owner;
    unordered_map<string,set<string>>Group;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        for (int i=0; i<accounts.size(); i++)
         for (int j=1; j<accounts[i].size(); j++)
         {
             Father[accounts[i][j]]=accounts[i][j];
             Owner[accounts[i][j]]=accounts[i][0];
         }
             
        
        for (int i=0; i<accounts.size(); i++)
        {
            for (int j=2; j<accounts[i].size(); j++)
            {
                if (FindSet(accounts[i][j])!=FindSet(accounts[i][j-1]))
                    Union(accounts[i][j],accounts[i][j-1]);
            }
        }
        
        for (int i=0; i<accounts.size(); i++)
         for (int j=1; j<accounts[i].size(); j++)
         {
             string parent = FindSet(accounts[i][j]);
             Group[parent].insert(accounts[i][j]);
         }
        
        vector<vector<string>>result;
        for (auto a:Group)
        {
            vector<string> temp;
            temp.push_back(Owner[a.first]);
            for (auto b:a.second)
                temp.push_back(b);
            result.push_back(temp);
        }
        return result;
    }
    
    string FindSet(string x)
    {
        if (x!=Father[x])
            Father[x]=FindSet(Father[x]);
        return Father[x];
    }
    
    void Union(string x, string y)
    {
        x=Father[x];
        y=Father[y];
        if (x<y)
            Father[y]=x;
        else
            Father[x]=y;
    }
};
