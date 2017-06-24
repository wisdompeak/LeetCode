class Solution {
public:
    static bool cmp(string a, string b)
    {
        return (a.size()<b.size());
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>>result;
        
        unordered_set<string>Set;
        unordered_map<string,int>Map;
        for (int i=0; i<words.size(); i++)
            Map[words[i]]=i;
            
        sort(words.begin(),words.end(),cmp);
        
        for (int i=0; i<words.size(); i++)
        {
            string t=words[i];

            for (int k=0; k<=t.size(); k++)
            {
                string s1=t.substr(0,k);
                reverse(s1.begin(),s1.end());
                string s2=t.substr(k,t.size()-k);
                if (Set.find(s1)!=Set.end() && palindrome(s2))
                    result.push_back({Map[t],Map[s1]});
                    
                s1=t.substr(0,k);
                s2=t.substr(k,t.size()-k);
                reverse(s2.begin(),s2.end());                
                if (Set.find(s2)!=Set.end() && palindrome(s1))
                    result.push_back({Map[s2],Map[t]});
                    
            }
            
            Set.insert(t);
        }
        
        return result;
    }
    
    bool palindrome(string s)
    {
        int i=0; 
        int j=s.size()-1;
        while (i<=j)
        {
            if (s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
