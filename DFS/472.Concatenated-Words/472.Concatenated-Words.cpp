class Solution {    
public:
    static bool cmp(string A, string B)
    {
        return A.size()<B.size();
    }
    
    unordered_set<string>Set;
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        sort(words.begin(),words.end(),cmp);            
        
        vector<string>results;
        for (auto s:words)     
        {
            if (s.size()==0) continue;
            if (DFS(s,0)) results.push_back(s);
            Set.insert(s);
        }
        return results;
    }
    
    bool DFS(string s, int times)
    {
        if (Set.count(s) && times>0) return true;
        
        string a = "";
	    for(int i=0; i<s.length(); ++i)
        {
		    a += s[i];
		    string b = s.substr(i+1);
		    if(Set.count(a) && DFS(b,times+1))
                return true;
	    }
	    return false;
    }
};
