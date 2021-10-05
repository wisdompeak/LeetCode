class Solution {
public:
    string smallestSubsequence(string text) 
    {
        string str;        
        vector<int>count(26);
        for (auto ch: text)
            count[ch-'a']++;
        unordered_set<char>visited;
        
        for (auto ch: text)
        {
            if (visited.find(ch)!=visited.end())
            {
                count[ch-'a']--;
            }
            else
            {
                while (str.size()>0  && str.back()>ch && count[str.back()-'a']>0)
                {
                    visited.erase(str.back());
                    str.pop_back();
                }
                str.push_back(ch);
                count[ch-'a']--;
                visited.insert(ch);
            }
        }
        
        return str;
    }
};
