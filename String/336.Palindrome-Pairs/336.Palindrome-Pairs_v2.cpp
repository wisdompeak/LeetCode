class Solution {
    static bool cmp(string a,string b)
    {
        return a.size()<b.size();
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        unordered_set<string>Set;
        unordered_map<string,int>Map;
        for (int i=0; i<words.size(); i++)
            Map[words[i]]=i;

        sort(words.begin(),words.end(),cmp);
        
        vector<vector<int>>results;
        
        for (int i=0; i<words.size(); i++)
        {
            string w = words[i];
            for (int j=0; j<=w.size(); j++)
            {
                if (isPalindrome(w,0,j-1))
                {
                    string w2 = w.substr(j);
                    reverse(w2.begin(),w2.end());
                    if (Set.find(w2)!=Set.end())                    
                        results.push_back({Map[w2],Map[words[i]]});                    
                }                
                if (isPalindrome(w,j,w.size()-1))
                {
                    string w2 = w.substr(0,j);
                    reverse(w2.begin(),w2.end());
                    if (Set.find(w2)!=Set.end())                    
                        results.push_back({Map[words[i]],Map[w2]});                    
                }   
            }            
            Set.insert(words[i]);
        }        
        return results;
    }
    
    bool isPalindrome(string &w, int a, int b)
    {
        while (a<b)
        {
            if (w[a]!=w[b]) return false;
            a++;
            b--;
        }
        return true;
    }    
};
